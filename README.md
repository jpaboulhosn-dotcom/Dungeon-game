# 🏰 Dungeon of Shadows

## 🎮 Sobre o Projeto

**Dungeon of Shadows** é um jogo do gênero **Dungeon Crawler** desenvolvido em linguagem **C**, utilizando o console como forma principal de interação.

O jogo apresenta uma visão **top-down**, onde o jogador explora mapas criados com caracteres ASCII, passando por uma vila inicial e enfrentando três andares de uma perigosa masmorra cheia de armadilhas, monstros, desafios e um poderoso Boss Final.

Este projeto foi desenvolvido como trabalho acadêmico da disciplina de programação, com o objetivo de aplicar conceitos fundamentais da linguagem C, como:

* Variáveis
 Estruturas condicionais
 Laços de repetição
 Matrizes
 Funções
 Manipulação de caracteres
 Lógica de programação

---

# 👨‍💻 Desenvolvedor

**João Paulo Cavaleiro de Macêdo Aboul Hosn**

Curso: Ciência da Computação
Linguagem utilizada: C

---

# 📖 História do Jogo

Durante muitos anos, uma pequena vila viveu em paz, protegida por antigos guerreiros que mantinham uma força sombria presa dentro de uma masmorra esquecida.

Porém, o selo que prendia essa energia começou a enfraquecer. Criaturas misteriosas apareceram dentro da masmorra e um poderoso Boss assumiu o controle das profundezas.

Agora, um novo aventureiro surge com uma missão:

⚔️ **Entrar na masmorra, superar todos os desafios e derrotar o Boss Final antes que a escuridão alcance a vila.**

Antes da jornada começar, o jogador deverá conversar com um morador da vila para escolher uma arma que será utilizada durante toda a aventura.

---

# 🕹️ Como Jogar

O jogador controla um personagem dentro de mapas formados por caracteres no terminal.

O objetivo é:

1. Explorar a vila.
2. Escolher uma arma com o NPC.
3. Entrar na masmorra.
4. Coletar chaves.
5. Abrir portas.
6. Resolver desafios.
7. Derrotar monstros.
8. Vencer o Boss Final.

O jogador começa com:

❤️ **3 vidas**

Caso encoste em espinhos ou seja atingido por monstros:

 Perde 1 vida.
 O andar atual é reiniciado.

Ao perder todas as vidas:

💀 **Game Over**

---

# 🎮 Controles

| Tecla | Ação                 |
| ----- | -------------------- |
| W     | Move para cima       |
| A     | Move para esquerda   |
| S     | Move para baixo      |
| D     | Move para direita    |
| I     | Interage com objetos |
| O     | Realiza ataque       |
| Q     | Sai da partida       |

O símbolo do jogador muda dependendo da direção:

| Símbolo | Direção               |
| ------- | --------------------- |
| ^       | Olhando para cima     |
| v       | Olhando para baixo    |
| <       | Olhando para esquerda |
| >       | Olhando para direita  |

---

# ⚔️ Sistema de Armas

Durante a exploração da vila, o jogador encontra um NPC responsável por entregar uma arma.

Existem três opções:

## ⚔️ Espada

Ataque de curta distância.

Atinge uma área grande diretamente à frente do jogador.

```
zzz
zzz
 ^
```

---

## 🏹 Arco e Flecha

Ataque de longo alcance.

Atinge quatro espaços em linha reta.

```
> z z z z
```

---

## 🪄 Cajado

Ataque mágico ao redor do jogador.

Atinge todos os lados ao mesmo tempo.

```
z z z
z ^ z
z z z
```

---

# 🗺️ Símbolos do Mapa

| Símbolo | Significado                   |
| ------- | ----------------------------- |
| ^       | Jogador olhando para cima     |
| v       | Jogador olhando para baixo    |
| <       | Jogador olhando para esquerda |
| >       | Jogador olhando para direita  |
| *       | Parede                        |
| #       | Espinho                       |
| k       | Caixa destrutível             |
| O       | Botão                         |
| D       | Porta fechada                 |
| @       | Chave                         |
| =       | Porta aberta                  |
| L       | Escada / passagem             |
| N       | NPC                           |
| X       | Monstro Tipo 1                |
| Y       | Monstro Tipo 2                |
| Z       | Boss Final                    |

---

# 👾 Inimigos

## Monstro Tipo 1 — X

Criatura imprevisível.

Características:

 Movimento aleatório.
 Anda uma posição por turno.
 Não persegue o jogador.

---

## Monstro Tipo 2 — Y

Criatura perseguidora.

Características:

 Analisa a posição do jogador.
 Move-se tentando diminuir a distância.
 Torna os últimos desafios mais perigosos.

---

## Boss Final — Z

O maior desafio da aventura.

O Boss possui:

 Mais resistência.
 Habilidade especial.
 Capacidade de alterar o mapa criando novos perigos.

Somente derrotando o Boss a vila será salva.

---

# 🏘️ Áreas do Jogo

## Vila

Área inicial.

Contém:

 NPC para escolha de arma.
 Entrada para a masmorra.

---

## Primeiro Andar

Introdução às mecânicas:

✔ Movimento
✔ Chaves
✔ Portas
✔ Destruição de caixas

---

## Segundo Andar

Novos desafios:

✔ Espinhos
✔ Botões
✔ Monstro aleatório

---

## Terceiro Andar

Desafio final contendo:

✔ Todos os elementos anteriores
✔ Monstro perseguidor
✔ Boss Final

---

# 🛠️ Tecnologias Utilizadas

 Linguagem C
 Terminal/Console
 Caracteres ASCII

---

# ▶️ Como Executar

Clone o repositório:

```bash
git clone link-do-repositorio
```

Compile o arquivo:

```bash
gcc jogo.c -o jogo
```

Execute:

```bash
./jogo
```

---

# 🏆 Objetivo do Projeto

Criar um jogo completo utilizando apenas recursos fundamentais da linguagem C, demonstrando domínio da lógica de programação e organização de código.

---


# Uso do ChatGPT durante o desenvolvimento do projeto

Durante o desenvolvimento do jogo **Dungeon Crawler em C**, utilizei o ChatGPT como uma ferramenta de apoio para entender melhor algumas partes do meu próprio código, melhorar a organização da lógica e esclarecer dúvidas sobre conceitos da linguagem C.

O ChatGPT não foi utilizado apenas para gerar código pronto, mas principalmente para explicar conceitos, revisar trechos específicos e auxiliar na compreensão da lógica utilizada no projeto.

## 1. Manipulação do mapa usando matrizes

Utilizei o ChatGPT para entender melhor a lógica da função responsável por copiar os mapas das fases: 

mapa[i][j]=origem[i][j]

2. Controle da posição do jogador

Também utilizei o ChatGPT para entender por que o jogador era removido da matriz após carregar a fase:

if (mapa[i][j] == 'P') {
    jogadorL = i;
    jogadorC = j;
    mapa[i][j] = ' ';
}

Aprendi que o caractere P serve apenas para indicar a posição inicial do jogador.

Depois disso, sua localização passa a ser controlada pelas variáveis:

jogadorL
jogadorC

Isso facilita a movimentação, pois o programa não precisa alterar constantemente a matriz para mover o personagem.

3. Limpeza da tela do terminal

Utilizei o ChatGPT para compreender o funcionamento da função:

void limparTela() {
    int i;
    
   for(i = 0;i < 30; i++) {
    printf("\n");
     }
}
    
Aprendi que o for repete o printf("\n") várias vezes para criar linhas vazias e simular uma limpeza de tela antes do mapa ser desenhado novamente.





## Obrigado por jogar Dungeon of Shadows! 🏰⚔️
