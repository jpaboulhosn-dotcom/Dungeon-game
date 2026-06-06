#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 25

char mapa[MAX][MAX];
int linhas, colunas;
int jogadorL, jogadorC;
char direcao = 'v';

int vidas = 3;
int fase = 0;
int arma = 0;
int chaves = 0;
int bossVida = 5;
int venceu = 0;

void limparTela() {
    int i;
    for (i = 0; i < 30; i++) {
        printf("\n");
    }
}

void copiarMapa(char origem[MAX][MAX], int l, int c) {
    int i, j;

    linhas = l;
    colunas = c;

    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            mapa[i][j] = origem[i][j];

            if (mapa[i][j] == 'P') {
                jogadorL = i;
                jogadorC = j;
                mapa[i][j] = ' ';
            }
        }
    }
}

void carregarVila() {
    char vila[MAX][MAX] = {
        "**********",
        "*P       *",
        "*  N     *",
        "*        *",
        "*        *",
        "*    L   *",
        "*        *",
        "*        *",
        "*        *",
        "**********"
    };

    fase = 0;
    chaves = 0;
    copiarMapa(vila, 10, 10);
}

void carregarAndar1() {
    char andar[MAX][MAX] = {
        "**********",
        "*P   @   *",
        "* **** * *",
        "* k  D * *",
        "* **   * *",
        "*      * *",
        "* **** * *",
        "*      L *",
        "*        *",
        "**********"
    };

    fase = 1;
    chaves = 0;
    copiarMapa(andar, 10, 10);
}

void carregarAndar2() {
    char andar[MAX][MAX] = {
        "***************",
        "*P     *      *",
        "* ***  *  *** *",
        "* @ k  D   #  *",
        "*** ***** *** *",
        "*     O       *",
        "*  #      X   *",
        "* ***D*****   *",
        "*   @         *",
        "*      k      *",
        "*   ***** *** *",
        "*        #    *",
        "*  X          *",
        "*           L *",
        "***************"
    };

    fase = 2;
    chaves = 0;
    copiarMapa(andar, 15, 15);
}

void carregarAndar3() {
    char andar[MAX][MAX] = {
        "*************************",
        "*P@     *       #   L  *",
        "* ***    *   *******    *",
        "*   k    D      Y       *",
        "* *****  ***********    *",
        "*     O         #       *",
        "*  #       X      k     *",
        "* ***D************ **   *",
        "*   @          Y        *",
        "*       k  ********     *",
        "*   *****       #       *",
        "*        #   X          *",
        "*  X       @      ***   *",
        "*      D       Z        *",
        "* ***********   *****   *",
        "*    #       O          *",
        "*  ****** ******* **    *",
        "*      Y       @        *",
        "*  k       #      D     *",
        "* ***************       *",
        "*       X               *",
        "*   ************        *",
        "*   #       Y           *",
        "*                       *",
        "*************************"
    };

    fase = 3;
    chaves = 0;
    bossVida = 5;
    copiarMapa(andar, 25, 25);
}

void mostrarMapa() {
    int i, j;

    limparTela();

    printf("Vidas: %d | Chaves: %d | ", vidas, chaves);

    if (arma == 1) printf("Arma: Espada\n");
    else if (arma == 2) printf("Arma: Arco\n");
    else if (arma == 3) printf("Arma: Cajado\n");
    else printf("Arma: Nenhuma\n");

    if (fase == 3) {
        printf("Vida do Boss: %d\n", bossVida);
    }

    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            if (i == jogadorL && j == jogadorC) {
                printf("%c", direcao);
            } else {
                printf("%c", mapa[i][j]);
            }
        }
        printf("\n");
    }

    printf("\nComandos: w/a/s/d mover | i interagir | o atacar | q sair\n");
}

void reiniciarFase() {
    vidas--;

    if (vidas <= 0) {
        printf("\nGAME OVER!\n");
        printf("Voltando ao menu principal...\n");
        getchar();
        getchar();
        carregarVila();
        vidas = 3;
        arma = 0;
        fase = 0;
        return;
    }

    printf("\nVoce perdeu uma vida! Reiniciando fase...\n");
    getchar();
    getchar();

    if (fase == 1) carregarAndar1();
    else if (fase == 2) carregarAndar2();
    else if (fase == 3) carregarAndar3();
}

int podeAndar(char c) {
    if (c == '*') return 0;
    if (c == 'D') return 0;
    if (c == 'k') return 0;
    if (c == 'N') return 0;
    return 1;
}

void posicaoFrente(int *l, int *c) {
    *l = jogadorL;
    *c = jogadorC;

    if (direcao == '^') (*l)--;
    else if (direcao == 'v') (*l)++;
    else if (direcao == '<') (*c)--;
    else if (direcao == '>') (*c)++;
}

void moverJogador(char comando) {
    int novaL = jogadorL;
    int novaC = jogadorC;
    char destino;

    if (comando == 'w') {
        direcao = '^';
        novaL--;
    } else if (comando == 's') {
        direcao = 'v';
        novaL++;
    } else if (comando == 'a') {
        direcao = '<';
        novaC--;
    } else if (comando == 'd') {
        direcao = '>';
        novaC++;
    }

    destino = mapa[novaL][novaC];

    if (destino == '#' || destino == 'X' || destino == 'Y' || destino == 'Z') {
        reiniciarFase();
        return;
    }

    if (podeAndar(destino)) {
        jogadorL = novaL;
        jogadorC = novaC;

        if (destino == 'L') {
            if (fase == 0) carregarAndar1();
            else if (fase == 1) carregarAndar2();
            else if (fase == 2) carregarAndar3();
            else if (fase == 3 && bossVida <= 0) venceu = 1;
        }
    }
}

void escolherArma() {
    int op;

    printf("\nNPC: Escolha sua arma:\n");
    printf("1 - Espada\n");
    printf("2 - Arco e Flecha\n");
    printf("3 - Cajado\n");
    printf("Escolha: ");
    scanf("%d", &op);

    if (op >= 1 && op <= 3) {
        arma = op;
        printf("\nArma escolhida!\n");
    } else {
        printf("\nOpcao invalida. Voce recebeu uma espada.\n");
        arma = 1;
    }

    getchar();
    getchar();
}

void acionarBotao() {
    if (fase == 2) {
        mapa[7][5] = '=';
        printf("\nO botao abriu uma passagem!\n");
    } else if (fase == 3) {
        mapa[14][13] = ' ';
        mapa[14][14] = ' ';
        mapa[14][15] = ' ';
        printf("\nO botao removeu parte da barreira perto do boss!\n");
    }

    getchar();
    getchar();
}

void interagir() {
    int l, c;
    char obj;

    posicaoFrente(&l, &c);
    obj = mapa[l][c];

    if (obj == 'N') {
        escolherArma();
    } else if (obj == '@') {
        chaves++;
        mapa[l][c] = ' ';
        printf("\nVoce pegou uma chave!\n");
        getchar();
        getchar();
    } else if (obj == 'D') {
        if (chaves > 0) {
            chaves--;
            mapa[l][c] = '=';
            printf("\nVoce abriu a porta!\n");
        } else {
            printf("\nVoce precisa de uma chave!\n");
        }
        getchar();
        getchar();
    } else if (obj == 'O') {
        acionarBotao();
    } else {
        printf("\nNao ha nada para interagir.\n");
        getchar();
        getchar();
    }
}

void int atacarCelula(int l, int c) {
    if (l < 0 || l >= linhas || c < 0 || c >= colunas) {
        return 0;
    }

    if (mapa[l][c] == 'k') {
        mapa[l][c] = ' ';
        printf("\nVoce destruiu uma caixa!\n");
        return 1;
    } 
    else if (mapa[l][c] == 'X' || mapa[l][c] == 'Y') {
        mapa[l][c] = ' ';
        printf("\nVoce derrotou um monstro!\n");
        return 1;
    } 
    else if (mapa[l][c] == 'Z') {
        bossVida--;
        printf("\nVoce acertou o boss!\n");

        if (bossVida <= 0) {
            mapa[l][c] = ' ';
            venceu = 1;
        }

        return 1;
    }
return 0;
}
    

void ataqueEspada() {
    int i;

    if (direcao == '^') {
        for (i = -1; i <= 1; i++) {
            atacarCelula(jogadorL - 1, jogadorC + i);
            atacarCelula(jogadorL - 2, jogadorC + i);
        }
    } else if (direcao == 'v') {
        for (i = -1; i <= 1; i++) {
            atacarCelula(jogadorL + 1, jogadorC + i);
            atacarCelula(jogadorL + 2, jogadorC + i);
        }
    } else if (direcao == '<') {
        for (i = -1; i <= 1; i++) {
            atacarCelula(jogadorL + i, jogadorC - 1);
            atacarCelula(jogadorL + i, jogadorC - 2);
        }
    } else if (direcao == '>') {
        for (i = -1; i <= 1; i++) {
            atacarCelula(jogadorL + i, jogadorC + 1);
            atacarCelula(jogadorL + i, jogadorC + 2);
        }
    }
}

void ataqueArco() {
    int i;

    for (i = 1; i <= 4; i++) {
        if (direcao == '^') atacarCelula(jogadorL - i, jogadorC);
        else if (direcao == 'v') atacarCelula(jogadorL + i, jogadorC);
        else if (direcao == '<') atacarCelula(jogadorL, jogadorC - i);
        else if (direcao == '>') atacarCelula(jogadorL, jogadorC + i);
    }
}

void ataqueCajado() {
    int i, j;

    for (i = -1; i <= 1; i++) {
        for (j = -1; j <= 1; j++) {
            if (!(i == 0 && j == 0)) {
                atacarCelula(jogadorL + i, jogadorC + j);
            }
        }
    }
}

void atacar() {
    if (arma == 0) {
        printf("\nVoce ainda nao escolheu uma arma!\n");
        printf("Aperte ENTER para continuar...");
        getchar();
        getchar();
        return;
    }

    printf("\nAtaque realizado!\n");

    if (arma == 1) {
        ataqueEspada();
    } 
    else if (arma == 2) {
        ataqueArco();
    } 
    else if (arma == 3) {
        ataqueCajado();
    }

    printf("\nAperte ENTER para continuar...");
    getchar();
    getchar();
}

void moverMonstros() {
    int i, j;
    int nl, nc;
    int dir;
    char novoMapa[MAX][MAX];

    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            novoMapa[i][j] = mapa[i][j];
        }
    }

    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            if (mapa[i][j] == 'X') {
                dir = rand() % 4;
                nl = i;
                nc = j;

                if (dir == 0) nl--;
                else if (dir == 1) nl++;
                else if (dir == 2) nc--;
                else nc++;

                if (nl == jogadorL && nc == jogadorC) {
                    reiniciarFase();
                    return;
                }

                if (mapa[nl][nc] == ' ') {
                    novoMapa[i][j] = ' ';
                    novoMapa[nl][nc] = 'X';
                }
            }

            if (mapa[i][j] == 'Y') {
                nl = i;
                nc = j;

                if (abs(jogadorL - i) > abs(jogadorC - j)) {
                    if (jogadorL > i) nl++;
                    else nl--;
                } else {
                    if (jogadorC > j) nc++;
                    else nc--;
                }

                if (nl == jogadorL && nc == jogadorC) {
                    reiniciarFase();
                    return;
                }

                if (mapa[nl][nc] == ' ') {
                    novoMapa[i][j] = ' ';
                    novoMapa[nl][nc] = 'Y';
                }
            }
        }
    }

    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            mapa[i][j] = novoMapa[i][j];
        }
    }
}

void acaoBoss() {
    int i, j;

    // boss só funciona no terceiro andar
    if (fase != 3) {
        return;
    }

    if (bossVida <= 0) {
        return;
    }


    
    for (i = jogadorL - 1; i <= jogadorL + 1; i++) {

        for (j = jogadorC - 1; j <= jogadorC + 1; j++) {

            if (i >= 0 && i < linhas && j >= 0 && j < colunas) {

                if (mapa[i][j] == 'Z') {

                    printf("\nO boss usou uma onda de energia!\n");

                    reiniciarFase();

                    return;
                }
            }
        }
    }


    
    if (mapa[jogadorL][jogadorC + 1] == ' ') {

        mapa[jogadorL][jogadorC + 1] = '#';

    }
}

    if (mapa[jogadorL][jogadorC + 1] == ' ') {
        mapa[jogadorL][jogadorC + 1] = '#';
    }
}

void tutorial() {
    limparTela();

    printf("=== TUTORIAL ===\n\n");
    printf("Voce e um aventureiro que precisa explorar uma vila,\n");
    printf("entrar na masmorra e derrotar o Boss Final.\n\n");

    printf("Simbolos:\n");
    printf("^ v < > = Jogador\n");
    printf("* = Parede\n");
    printf("# = Espinho\n");
    printf("k = Caixa\n");
    printf("O = Botao\n");
    printf("D = Porta fechada\n");
    printf("@ = Chave\n");
    printf("= = Porta aberta\n");
    printf("L = Escada\n");
    printf("X = Monstro aleatorio\n");
    printf("Y = Monstro perseguidor\n");
    printf("Z = Boss Final\n");
    printf("N = NPC da vila\n\n");

    printf("Comandos:\n");
    printf("w = cima\n");
    printf("a = esquerda\n");
    printf("s = baixo\n");
    printf("d = direita\n");
    printf("i = interagir\n");
    printf("o = atacar\n");

    getchar();
    getchar();
}

void telaVitoria() {
    limparTela();

    printf("=====================================\n");
    printf("              VITORIA!\n");
    printf("=====================================\n");
    printf("O Boss Final foi derrotado.\n");
    printf("A masmorra perdeu sua forca sombria.\n");
    printf("A vila finalmente esta livre novamente.\n");
    printf("Voce se tornou o heroi da aventura!\n");
    printf("=====================================\n");

    getchar();
    getchar();
}

void jogar() {
    char comando;
    int sair = 0;

    vidas = 3;
    arma = 0;
    venceu = 0;
    carregarVila();

    while (!sair && !venceu) {
        mostrarMapa();
        printf("Digite o comando: ");
        scanf(" %c", &comando);

        if (comando == 'q') {
            sair = 1;
        } else if (comando == 'w' || comando == 'a' || comando == 's' || comando == 'd') {
            moverJogador(comando);
            moverMonstros();
            acaoBoss();
        } else if (comando == 'i') {
            interagir();
            moverMonstros();
            acaoBoss();
        } else if (comando == 'o') {
            atacar();
            moverMonstros();
            acaoBoss();
        }
    }

    if (venceu) {
        telaVitoria();
    }
}

int main() {
    int opcao;

    srand(time(NULL));

    do {
        limparTela();

        printf("=====================================\n");
        printf("        DUNGEON CRAWLER EM C\n");
        printf("=====================================\n");
        printf("1 - Jogar\n");
        printf("2 - Tutorial\n");
        printf("3 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            jogar();
        } else if (opcao == 2) {
            tutorial();
        } else if (opcao == 3) {
            printf("\nCreditos:\n");
            printf("Desenvolvido por: Joao Paulo Hosn\n");
            printf("Obrigado por jogar!\n");
        } else {
            printf("\nOpcao invalida!\n");
            getchar();
            getchar();
        }

    } while (opcao != 3);

    return 0;
}