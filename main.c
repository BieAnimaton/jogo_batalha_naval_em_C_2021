// TRABALHO PRÁTICO - BATALHA NAVAL
// NOME: GABRIEL COSSARE BRAGION, RA:202110028, DISCIPLINA: CIÊNCIAS DA COMPUTAÇÃO
// PROFESSOR CLERIVADO

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "portuguese");

    char agua = '~', estrutura = 'o', contador, contador2, contador3, novaPart;
    int tamanhoMapa, mapaGerado,
        posicao, posicao2,
        ataque, ataque2,
        randomNum, randomNum2, randomNumDecidirColOuLin, randAtaqueLin, randAtaqueCol,
        jogoEncerrado = 0,
        naviosComputadorDestruidos = 0, naviosJogadorDestruidos = 0,
        vez,
        valorReturn;
    int mapa10[10][10], mapa10Inimigo[10][10], mapa10InimigoMostrar[10][10];
    int mapa15[15][15], mapa15Inimigo[15][15], mapa15InimigoMostrar[15][15];

    struct Navios{
        int linha[3];
        int coluna[3];
    };

    struct PortaA{
        int linha[4];
        int coluna[4];
    };

    struct Hidro{
        int linha[3];
        int coluna[3];
    };

    struct Jogadores{
        int vitorias;
        int derrotas;
        int tirosPerdidos;
        int tirosCerteiros;
        int navios;
        struct Navios navio1, navio2;
        struct PortaA portaA1;
        struct Hidro hidro1, hidro2;
    };
    struct Jogadores jogador, computador;


    jogador.vitorias = 0;
    jogador.derrotas = 0;
    jogador.tirosPerdidos = 0;
    jogador.tirosCerteiros = 0;
    jogador.navios = 5;

    computador.vitorias = 0;
    computador.derrotas = 0;
    computador.tirosPerdidos = 0;
    computador.tirosCerteiros = 0;
    computador.navios = 5;


    void funcaoApagarTela() { //      FUNÇÃO COM RETORNO E SEM PARÂMETRO
        return system("cls");
    }

    void funcaoImprimirRelatorioPartida(int tamanho) { //      FUNÇÃO SEM RETORNO E COM PARÂMETRO
        if(tamanho == 15) {
            printf("\n\n\t|JOGADOR\t\t|\t\t\t\t\t\t|COMPUTADOR\t\t|" // RELATÓRIO 15x15
            "\n\t|Vitórias: %d\t\t|\t\t\t\t\t\t|Vitórias: %d\t\t|"
            "\n\t|Derrotas: %d\t\t|\t\t\t\t\t\t|Derrotas: %d\t\t|"
            "\n\t|Tiros perdidos: %d\t|\t\t\t\t\t\t|Tiros perdidos: %d\t|"
            "\n\t|Tiros certeiros: %d\t|\t\t\t\t\t\t|Tiros certeiros: %d\t|"
            "\n\t|Navios restantes: %d\t|\t\t\t\t\t\t|Navios restantes: %d\t|"
            "\n\t|Navios destruidos: %d\t|\t\t\t\t\t\t|Navios destruidos: %d\t|\n",
            jogador.vitorias, computador.vitorias, jogador.derrotas, computador.derrotas,
            jogador.tirosPerdidos, computador.tirosPerdidos, jogador.tirosCerteiros, computador.tirosCerteiros,
            jogador.navios, computador.navios, naviosComputadorDestruidos, naviosJogadorDestruidos);
        } else {
            printf("\n\n\t|JOGADOR\t\t|\t\t\t\t|COMPUTADOR\t\t|" // RELATÓRIO 10x10
            "\n\t|Vitórias: %d\t\t|\t\t\t\t|Vitórias: %d\t\t|"
            "\n\t|Derrotas: %d\t\t|\t\t\t\t|Derrotas: %d\t\t|"
            "\n\t|Tiros perdidos: %d\t|\t\t\t\t|Tiros perdidos: %d\t|"
            "\n\t|Tiros certeiros: %d\t|\t\t\t\t|Tiros certeiros: %d\t|"
            "\n\t|Navios restantes: %d\t|\t\t\t\t|Navios restantes: %d\t|"
            "\n\t|Navios destruidos: %d\t|\t\t\t\t|Navios destruidos: %d\t|\n",
            jogador.vitorias, computador.vitorias, jogador.derrotas, computador.derrotas,
            jogador.tirosPerdidos, computador.tirosPerdidos, jogador.tirosCerteiros, computador.tirosCerteiros,
            jogador.navios, computador.navios, naviosComputadorDestruidos, naviosJogadorDestruidos);
        }
    }

    void funcaoImprimirMapa(int tamanho) { // IMPRIMINDO MAPA
        if(tamanho == 15) { // IMPRIMINDO MAPA 15X15
            printf("\n\n\t[+] MAPA %dx%d\n\n", tamanho, tamanho);
            printf("\n\t"
                "=================================================================================================="
                "\n\t||\t\t\t\t\t\t\t\t\t\t\t\t||\n"
                "\t||\t    ");
            for (contador = 0; contador < tamanho; contador++) {
                printf("%d ", contador);
            }
            printf("\t\t    ");
            for (contador = 0; contador < tamanho; contador++) {
                printf("%d ", contador);
            }
            printf("\t||\n\t||\t");
            for (contador = 0; contador < tamanho; contador++) {
                if (contador < 10) {
                    printf(" %d |", contador);
                } else {
                    printf("%d |", contador);
                }
                for (contador2 = 0; contador2 < tamanho; contador2++) {
                    printf("%c ", mapa15[contador][contador2]);
                    if (contador2 == 14) { // mapa 15x15 do computador
                        printf("|\t\t", contador);
                        if (contador < 10) {
                            printf(" %d |", contador);
                        } else {
                            printf("%d |", contador);
                        }
                        for (contador3 = 0; contador3 < tamanhoMapa; contador3++) {
                            printf("%c ", mapa15InimigoMostrar[contador][contador3]);
                        }
                    }
                }
                printf("|\t||\n\t||\t");
            }
            printf("\t       JOGADOR\t\t\t\t\t      COMPUTADOR\t\t||\n"
                "\t||\t\t\t\t\t\t\t\t\t\t\t\t||"
                "\n\t"
                "=================================================================================================="
                "\n\n");
        } else { //                    ------ IMPRIMINDO MAPA 10X10 ------
            printf("\n\n\t[+] MAPA %dx%d\n\n", tamanho, tamanho);
            printf("\n\t"
                "=================================================================================="
                "\n\t||\t\t\t\t\t\t\t\t\t\t||\n"
                "\t||\t    ");
            for (contador = 0; contador < tamanho; contador++) {
                printf("%d ", contador);
            }
            printf("\t\t    ");
            for (contador = 0; contador < tamanho; contador++) {
                printf("%d ", contador);
            }
            printf("\t||\n\t||\t");
            for (contador = 0; contador < tamanho; contador++) {
                if (contador < 10) {
                    printf(" %d |", contador);
                } else {
                    printf("%d |", contador);
                }
                for (contador2 = 0; contador2 < tamanho; contador2++) {
                    printf("%c ", mapa10[contador][contador2]);
                    if (contador2 == 9) { // mapa 10x10 do computador
                        printf("|\t\t", contador);
                        if (contador < 10) {
                            printf(" %d |", contador);
                        } else {
                            printf("%d |", contador);
                        }
                        for (contador3 = 0; contador3 < tamanhoMapa; contador3++) {
                            printf("%c ", mapa10InimigoMostrar[contador][contador3]);
                        }
                    }
                }
                printf("|\t||\n\t||\t");
            }
            printf("         JOGADOR\t\t\t         COMPUTADOR\t\t||\n"
                "\t||\t\t\t\t\t\t\t\t\t\t||"
                "\n\t"
                "=================================================================================="
                "\n\n");
        }

    }

    int funcaoGerarMapa(int tamanho) { //      FUNÇÃO COM RETORNO E COM PARÂMETRO
        for (contador = 0; contador < tamanho; contador++) {
            for (contador2 = 0; contador2 < tamanho; contador2++) {
                if (tamanhoMapa == 15) { // preenchendo de agua os mapas 15x15 do jogador e inimigo
                    mapa15[contador][contador2] = agua;
                    mapa15Inimigo[contador][contador2] = agua;
                    mapa15InimigoMostrar[contador][contador2] = agua;
                } else { // preenchendo de agua os mapas 10x10 do jogador e inimigo
                    mapa10[contador][contador2] = agua;
                    mapa10Inimigo[contador][contador2] = agua;
                    mapa10InimigoMostrar[contador][contador2] = agua;
                }
            }
        }

        return 1;
    }

    int funcaoGerarNaviosJogador(int tamanho) {
        if(tamanho == 15) { //      ------ GERANDO NAVIOS JOGADOR MAPA 15X15 ------

            void funcaoImprimirMapaeNaviosDojogador() {

                funcaoImprimirMapa(tamanhoMapa);
            }

            funcaoImprimirMapaeNaviosDojogador(); // gerando navio 1
            printf("Obs: horizontal e vertical do mapa começam de 0 até 14");
            printf("\nDigite três posições seguidas para o primeiro navio (lin col):");
            printf("\n");
            for (contador = 0; contador < 3; contador++) {
                scanf("%d%d", &posicao, &posicao2);
                mapa15[posicao][posicao2] = estrutura;
                jogador.navio1.linha[contador] = posicao; // guardando a posição do navio na struct
                jogador.navio1.coluna[contador] = posicao2;
                printf("\n");
            }
            funcaoApagarTela();

            funcaoImprimirMapaeNaviosDojogador(); // gerando navio 2
            printf("Obs: horizontal e vertical do mapa começam de 0 até 14");
            printf("\nDigite três posições seguidas para o segundo navio (lin col):");
            printf("\n");
            for (contador = 0; contador < 3; contador++) {
                scanf("%d%d", &posicao, &posicao2);
                mapa15[posicao][posicao2] = estrutura;
                jogador.navio2.linha[contador] = posicao; // guardando a posição do 2º navio na struct
                jogador.navio2.coluna[contador] = posicao2;
                printf("\n");
            }
            funcaoApagarTela();

            funcaoImprimirMapaeNaviosDojogador(); // gerando porta-avião
            printf("Obs: horizontal e vertical do mapa começam de 0 até 14");
            printf("\nDigite quatro posições seguidas para o porta avião (lin col):");
            printf("\n");
            for (contador = 0; contador < 4; contador++) {
                scanf("%d%d", &posicao, &posicao2);
                mapa15[posicao][posicao2] = estrutura;
                jogador.portaA1.linha[contador] = posicao; // guardando a posição do 2º navio na struct
                jogador.portaA1.coluna[contador] = posicao2;
                printf("\n");
            }
            funcaoApagarTela();

            funcaoImprimirMapaeNaviosDojogador();
            printf("Obs: horizontal e vertical do mapa começam de 0 até 14");
            printf("\nDigite três posições, sendo 2 na mesma linha e 1 em outra, "
                   "para o primeiro hidroavião (lin col):");
            printf("\n");
            for (contador = 0; contador < 3; contador++) {
                scanf("%d%d", &posicao, &posicao2);
                mapa15[posicao][posicao2] = estrutura;
                jogador.hidro1.linha[contador] = posicao; // guardando a posição do 1º hidro-avião na struct
                jogador.hidro1.coluna[contador] = posicao2;
                printf("\n");
            }
            funcaoApagarTela();

            funcaoImprimirMapaeNaviosDojogador();
            printf("Obs: horizontal e vertical do mapa começam de 0 até 14");
            printf("\nDigite três posições, sendo 2 na mesma linha e 1 em outra, "
                   "para o segundo hidroavião (lin col):");
            printf("\n");
            for (contador = 0; contador < 3; contador++) {
                scanf("%d%d", &posicao, &posicao2);
                mapa15[posicao][posicao2] = estrutura;
                jogador.hidro2.linha[contador] = posicao; // guardando a posição do 1º hidro-avião na struct
                jogador.hidro2.coluna[contador] = posicao2;
                printf("\n");
            }

            getch();

            funcaoApagarTela();

        } else { //      ------ GERANDO NAVIOS JOGADOR MAPA 10X10 ------

            void funcaoImprimirMapaeNaviosDojogador() {

                funcaoImprimirMapa(tamanhoMapa);
            }

            funcaoImprimirMapaeNaviosDojogador(); // gerando navio 1
            printf("Obs: horizontal e vertical do mapa começam de 0 até 9");
            printf("\nDigite três posições seguidas para o primeiro navio (lin col):");
            printf("\n");
            for (contador = 0; contador < 3; contador++) {
                scanf("%d%d", &posicao, &posicao2);
                mapa10[posicao][posicao2] = estrutura;
                jogador.navio1.linha[contador] = posicao; // guardando a posição do navio na struct
                jogador.navio1.coluna[contador] = posicao2;
                printf("\n");
            }
            funcaoApagarTela();

            funcaoImprimirMapaeNaviosDojogador(); // gerando navio 2
            printf("Obs: horizontal e vertical do mapa começam de 0 até 9");
            printf("\nDigite três posições seguidas para o segundo navio (lin col):");
            printf("\n");
            for (contador = 0; contador < 3; contador++) {
                scanf("%d%d", &posicao, &posicao2);
                mapa10[posicao][posicao2] = estrutura; // arrumar
                jogador.navio2.linha[contador] = posicao; // guardando a posição do 2º navio na struct
                jogador.navio2.coluna[contador] = posicao2;
                printf("\n");
            }
            funcaoApagarTela();

            funcaoImprimirMapaeNaviosDojogador(); // gerando porta-avião
            printf("Obs: horizontal e vertical do mapa começam de 0 até 9");
            printf("\nDigite quatro posições seguidas para o porta avião (lin col):");
            printf("\n");
            for (contador = 0; contador < 4; contador++) {
                scanf("%d%d", &posicao, &posicao2);
                mapa10[posicao][posicao2] = estrutura;
                jogador.portaA1.linha[contador] = posicao; // guardando a posição do 2º navio na struct
                jogador.portaA1.coluna[contador] = posicao2;
                printf("\n");
            }
            funcaoApagarTela();

            funcaoImprimirMapaeNaviosDojogador();
            printf("Obs: horizontal e vertical do mapa começam de 0 até 9");
            printf("\nDigite três posições, sendo 2 na mesma linha e 1 em outra, "
                   "para o primeiro hidroavião (lin col):");
            printf("\n");
            for (contador = 0; contador < 3; contador++) {
                scanf("%d%d", &posicao, &posicao2);
                mapa10[posicao][posicao2] = estrutura;
                jogador.hidro1.linha[contador] = posicao; // guardando a posição do 1º hidro-avião na struct
                jogador.hidro1.coluna[contador] = posicao2;
                printf("\n");
            }
            funcaoApagarTela();

            funcaoImprimirMapaeNaviosDojogador();
            printf("Obs: horizontal e vertical do mapa começam de 0 até 9");
            printf("\nDigite três posições, sendo 2 na mesma linha e 1 em outra, "
                   "para o segundo hidroavião (lin col):");
            printf("\n");
            for (contador = 0; contador < 3; contador++) {
                scanf("%d%d", &posicao, &posicao2);
                mapa10[posicao][posicao2] = estrutura;
                jogador.hidro2.linha[contador] = posicao; // guardando a posição do 1º hidro-avião na struct
                jogador.hidro2.coluna[contador] = posicao2;
                printf("\n");
            }

            getch();

            funcaoApagarTela();
        }
    }

    int funcaoGerarNaviosComputador(int tamanho) {
        if(tamanho == 15) { //      ------ GERANDO NAVIOS INIMIGOS PARA MAPA 15X15 ------

            void funcaoGerarNumeros() {
                randomNum = rand() % 14; // escolhe posição aleatória de 0 a 14
                randomNumDecidirColOuLin = rand() % 60; /* escolhe posição aleatória 2
                                                   (decide se navio inimigo vai ser
                                                    posicionado na vertical ou horizontal) */
            }

            void funcaoPrimeiroNavio() {
                funcaoGerarNumeros(); // gerando 1º navio
                if(randomNumDecidirColOuLin % 2 == 0) {
                    for (contador = 0; contador < 3; contador ++) {
                        mapa15Inimigo[randomNum][contador] = estrutura;
                        computador.navio1.linha[contador] = randomNum; // guardando a posição do 1º navio na struct
                        computador.navio1.coluna[contador] = contador;
                    }
                } else {
                    for (contador = 0; contador < 3; contador ++) {
                        mapa15Inimigo[contador][randomNum] = estrutura;
                        computador.navio1.linha[contador] = contador; // guardando a posição do 1º navio na struct
                        computador.navio1.coluna[contador] = randomNum;
                    }
                }
            }
            funcaoPrimeiroNavio();

            void funcaoSegundoNavio() {
                funcaoGerarNumeros(); // gerando 2º navio
                if(randomNumDecidirColOuLin % 2 == 0) {
                    for (contador = 0; contador < 3; contador ++) {
                        mapa15Inimigo[randomNum][contador] = estrutura;
                        computador.navio2.linha[contador] = randomNum; // guardando a posição do 2º navio na struct
                        computador.navio2.coluna[contador] = contador;
                    }
                    if (computador.navio2.linha[1] == computador.navio1.linha[1]) {
                        for (contador = 0; contador < 3; contador ++) {
                            mapa15Inimigo[randomNum][contador] = agua;
                            computador.navio2.linha[contador] = randomNum; // apagando parte do navio 2 e colocando agua
                            computador.navio2.coluna[contador] = contador;
                        }
                        funcaoSegundoNavio();
                    }
                } else {
                    for (contador = 0; contador < 3; contador ++) {
                        mapa15Inimigo[contador][randomNum] = estrutura;
                        computador.navio2.linha[contador] = contador; // guardando a posição do 2º navio na struct
                        computador.navio2.coluna[contador] = randomNum;
                    }
                    if (computador.navio2.linha[1] == computador.navio1.linha[1]) {
                        for (contador = 0; contador < 3; contador ++) {
                            mapa15Inimigo[contador][randomNum] = agua;
                            computador.navio2.linha[contador] = contador; // apagando parte do navio 2 e colocando agua
                            computador.navio2.coluna[contador] = randomNum;
                        }
                        funcaoSegundoNavio();
                    }
                }
            }
            funcaoSegundoNavio();

            void funcaoPortaAviao() {
                funcaoGerarNumeros(); // gerando porta-avião
                if(randomNumDecidirColOuLin % 2 == 0) {
                    for (contador = 0; contador < 4; contador ++) {
                        mapa15Inimigo[randomNum][contador] = estrutura;
                        computador.portaA1.linha[contador] = randomNum; // guardando a posição do porta-avião na struct
                        computador.portaA1.coluna[contador] = contador;
                    }
                    if (computador.portaA1.linha[0] == computador.navio1.linha[0] || computador.portaA1.linha[0] == computador.navio2.linha[0]) {
                        for (contador = 0; contador < 4; contador ++) {
                            mapa15Inimigo[randomNum][contador] = agua;
                            computador.portaA1.linha[contador] = randomNum; // apagando parte do porta aviao e colocando agua
                            computador.portaA1.coluna[contador] = contador;
                        }
                        funcaoPortaAviao();
                    }
                } else {
                    for (contador = 0; contador < 4; contador ++) {
                        mapa15Inimigo[contador][randomNum] = estrutura;
                        computador.portaA1.linha[contador] = randomNum; // guardando a posição do porta-avião na struct
                        computador.portaA1.coluna[contador] = contador;
                    }
                    if (computador.portaA1.linha[0] == computador.navio1.linha[1] || computador.portaA1.linha[0] == computador.navio2.linha[0]) {
                        for (contador = 0; contador < 4; contador ++) {
                            mapa15Inimigo[contador][randomNum] = estrutura;
                            computador.portaA1.linha[contador] = randomNum; // apagando parte do porta aviao e colocando agua
                            computador.portaA1.coluna[contador] = contador;
                        }
                        funcaoPortaAviao();
                    }
                }
            }
            funcaoPortaAviao();

            void funcaoPrimeiroHidro() {
                funcaoGerarNumeros(); // gerando 1º hidro-avião
                mapa15Inimigo[randomNum][randomNum + 1] = estrutura;
                mapa15Inimigo[randomNum + 1][randomNum] = estrutura;
                mapa15Inimigo[randomNum + 1][randomNum + 2] = estrutura;
                computador.hidro1.linha[0] = randomNum; // guardando a posição do 1º hidro-avião na struct
                computador.hidro1.linha[1] = randomNum + 1; // guardando a posição do 1º hidro-avião na struct
                computador.hidro1.linha[2] = randomNum + 1; // guardando a posição do 1º hidro-avião na struct

                computador.hidro1.coluna[0] = randomNum + 1;
                computador.hidro1.coluna[1] = randomNum;
                computador.hidro1.coluna[2] = randomNum + 2;
                if (computador.hidro1.linha[0] == computador.portaA1.linha[0] ||
                    computador.hidro1.linha[0] == computador.navio1.linha[1] ||
                    computador.hidro1.linha[0] == computador.navio2.linha[1]) {
                        mapa15Inimigo[randomNum][randomNum + 1] = agua;
                        mapa15Inimigo[randomNum + 1][randomNum] = agua;
                        mapa15Inimigo[randomNum + 1][randomNum + 2] = agua;
                        funcaoPrimeiroHidro();
                }
            }
            funcaoPrimeiroHidro();

            void funcaoSegundoHidro() {
                funcaoGerarNumeros(); // gerando 2º hidro-avião
                mapa15Inimigo[randomNum][randomNum + 1] = estrutura;
                mapa15Inimigo[randomNum + 1][randomNum] = estrutura;
                mapa15Inimigo[randomNum + 1][randomNum + 2] = estrutura;
                computador.hidro2.linha[0] = randomNum; // guardando a posição do 1º hidro-avião na struct
                computador.hidro2.linha[1] = randomNum + 1; // guardando a posição do 1º hidro-avião na struct
                computador.hidro2.linha[2] = randomNum + 1; // guardando a posição do 1º hidro-avião na struct

                computador.hidro2.coluna[0] = randomNum + 1;
                computador.hidro2.coluna[1] = randomNum;
                computador.hidro2.coluna[2] = randomNum + 2;
                if (computador.hidro2.linha[0] == computador.portaA1.linha[0] ||
                    computador.hidro2.linha[0] == computador.navio1.linha[0] ||
                    computador.hidro2.linha[0] == computador.navio2.linha[0] ||
                    computador.hidro2.coluna[0] == computador.portaA1.linha[0] ||
                    computador.hidro2.coluna[0] == computador.navio1.linha[0] ||
                    computador.hidro2.coluna[0] == computador.navio2.linha[0] ||
                    computador.hidro2.linha[0] == computador.hidro1.linha[0] ||
                    computador.hidro2.linha[2] == computador.hidro1.linha[2] ||
                    computador.hidro2.coluna[0] == computador.hidro1.coluna[0] ||
                    computador.hidro2.coluna[2] == computador.hidro1.coluna[2]) {
                        mapa15Inimigo[randomNum][randomNum + 1] = agua;
                        mapa15Inimigo[randomNum + 1][randomNum] = agua;
                        mapa15Inimigo[randomNum + 1][randomNum + 2] = agua;
                        funcaoSegundoHidro();
                }
            }
            funcaoSegundoHidro();

        } else { //      ------ GERANDO NAVIOS INIMIGOS PARA MAPA 10X10 ------

            void funcaoGerarNumeros() {
                randomNum = rand() % 9; // escolhe posição aleatória de 0 a 14
                randomNumDecidirColOuLin = rand() % 30; /* escolhe posição aleatória 2
                                                   (decide se navio inimigo vai ser
                                                    posicionado na vertical ou horizontal) */
            }

            void funcaoPrimeiroNavio() {
                funcaoGerarNumeros(); // gerando 1º navio
                if(randomNumDecidirColOuLin % 2 == 0) {
                    for (contador = 0; contador < 3; contador ++) {
                        mapa10Inimigo[randomNum][contador] = estrutura;
                        computador.navio1.linha[contador] = randomNum; // guardando a posição do 1º navio na struct
                        computador.navio1.coluna[contador] = contador;
                    }
                } else {
                    for (contador = 0; contador < 3; contador ++) {
                        mapa10Inimigo[contador][randomNum] = estrutura;
                        computador.navio1.linha[contador] = contador; // guardando a posição do 1º navio na struct
                        computador.navio1.coluna[contador] = randomNum;
                    }
                }
            }
            funcaoPrimeiroNavio();

            void funcaoSegundoNavio() {
                funcaoGerarNumeros(); // gerando 2º navio
                if(randomNumDecidirColOuLin % 2 == 0) {
                    for (contador = 0; contador < 3; contador ++) {
                        mapa10Inimigo[randomNum][contador] = estrutura;
                        computador.navio2.linha[contador] = randomNum; // guardando a posição do 2º navio na struct
                        computador.navio2.coluna[contador] = contador;
                    }
                    if (computador.navio2.linha[0] == computador.navio1.linha[0]) {
                        for (contador = 0; contador < 3; contador ++) {
                            mapa10Inimigo[randomNum][contador] = agua;
                            computador.navio2.linha[contador] = randomNum; // apagando parte do navio 2 e colocando agua
                            computador.navio2.coluna[contador] = contador;
                        }
                        funcaoSegundoNavio();
                    }
                } else {
                    for (contador = 0; contador < 3; contador ++) {
                        mapa10Inimigo[contador][randomNum] = estrutura;
                        computador.navio2.linha[contador] = contador; // guardando a posição do 2º navio na struct
                        computador.navio2.coluna[contador] = randomNum;
                    }
                    if (computador.navio2.linha[0] == computador.navio1.linha[0]) {
                        for (contador = 0; contador < 3; contador ++) {
                            mapa10Inimigo[contador][randomNum] = agua;
                            computador.navio2.linha[contador] = contador; // apagando parte do navio 2 e colocando agua
                            computador.navio2.coluna[contador] = randomNum;
                        }
                        funcaoSegundoNavio();
                    }
                }
            }
            funcaoSegundoNavio();

            void funcaoPortaAviao() {
                funcaoGerarNumeros(); // gerando porta-avião
                if(randomNumDecidirColOuLin % 2 == 0) {
                    for (contador = 0; contador < 4; contador ++) {
                        mapa10Inimigo[randomNum][contador] = estrutura;
                        computador.portaA1.linha[contador] = randomNum; // guardando a posição do porta-avião na struct
                        computador.portaA1.coluna[contador] = contador;
                    }
                    if (computador.portaA1.linha[0] == computador.navio1.linha[0] || computador.portaA1.linha[0] == computador.navio2.linha[0]) {
                        for (contador = 0; contador < 4; contador ++) {
                            mapa10Inimigo[randomNum][contador] = agua;
                            computador.portaA1.linha[contador] = randomNum; // apagando parte do porta aviao e colocando agua
                            computador.portaA1.coluna[contador] = contador;
                        }
                        funcaoPortaAviao();
                    }
                } else {
                    for (contador = 0; contador < 4; contador ++) {
                        mapa10Inimigo[contador][randomNum] = estrutura;
                        computador.portaA1.linha[contador] = randomNum; // guardando a posição do porta-avião na struct
                        computador.portaA1.coluna[contador] = contador;
                    }
                    if (computador.portaA1.linha[0] == computador.navio1.linha[0] || computador.portaA1.linha[0] == computador.navio2.linha[0]) {
                        for (contador = 1; contador < 5; contador ++) {
                            mapa10Inimigo[contador][randomNum] = estrutura;
                            computador.portaA1.linha[contador] = randomNum; // apagando parte do porta aviao e colocando agua
                            computador.portaA1.coluna[contador] = contador;
                        }
                        funcaoPortaAviao();
                    }
                }
            }
            funcaoPortaAviao();

            void funcaoPrimeiroHidro() {
                funcaoGerarNumeros(); // gerando 1º hidro-avião
                mapa10Inimigo[randomNum][randomNum + 1] = estrutura;
                mapa10Inimigo[randomNum + 1][randomNum] = estrutura;
                mapa10Inimigo[randomNum + 1][randomNum + 2] = estrutura;
                computador.hidro1.linha[0] = randomNum; // guardando a posição do 1º hidro-avião na struct
                computador.hidro1.linha[1] = randomNum + 1; // guardando a posição do 1º hidro-avião na struct
                computador.hidro1.linha[2] = randomNum + 1; // guardando a posição do 1º hidro-avião na struct

                computador.hidro1.coluna[0] = randomNum + 1;
                computador.hidro1.coluna[1] = randomNum;
                computador.hidro1.coluna[2] = randomNum + 2;
                if (computador.hidro1.linha[0] == computador.portaA1.linha[0] ||
                    computador.hidro1.linha[0] == computador.navio1.linha[0] ||
                    computador.hidro1.linha[0] == computador.navio2.linha[0]) {
                        mapa10Inimigo[randomNum][randomNum + 1] = agua;
                        mapa10Inimigo[randomNum + 1][randomNum] = agua;
                        mapa10Inimigo[randomNum + 1][randomNum + 2] = agua;
                        funcaoPrimeiroHidro();
                }
            }
            funcaoPrimeiroHidro();

            void funcaoSegundoHidro() {
                funcaoGerarNumeros(); // gerando 2º hidro-avião
                mapa10Inimigo[randomNum][randomNum + 1] = estrutura;
                mapa10Inimigo[randomNum + 1][randomNum] = estrutura;
                mapa10Inimigo[randomNum + 1][randomNum + 2] = estrutura;
                computador.hidro2.linha[0] = randomNum; // guardando a posição do 1º hidro-avião na struct
                computador.hidro2.linha[1] = randomNum + 1; // guardando a posição do 1º hidro-avião na struct
                computador.hidro2.linha[2] = randomNum + 1; // guardando a posição do 1º hidro-avião na struct

                computador.hidro2.coluna[0] = randomNum + 1;
                computador.hidro2.coluna[1] = randomNum;
                computador.hidro2.coluna[2] = randomNum + 2;
                if (computador.hidro2.linha[0] == computador.portaA1.linha[0] ||
                    computador.hidro2.linha[0] == computador.navio1.linha[0] ||
                    computador.hidro2.linha[0] == computador.navio2.linha[0] ||
                    computador.hidro2.coluna[0] == computador.portaA1.linha[0] ||
                    computador.hidro2.coluna[0] == computador.navio1.linha[0] ||
                    computador.hidro2.coluna[0] == computador.navio2.linha[0] ||
                    computador.hidro2.linha[0] == computador.hidro1.linha[0] ||
                    computador.hidro2.linha[2] == computador.hidro1.linha[2] ||
                    computador.hidro2.coluna[0] == computador.hidro1.coluna[0] ||
                    computador.hidro2.coluna[2] == computador.hidro1.coluna[2]) {
                        mapa10Inimigo[randomNum][randomNum + 1] = agua;
                        mapa10Inimigo[randomNum + 1][randomNum] = agua;
                        mapa10Inimigo[randomNum + 1][randomNum + 2] = agua;
                        funcaoSegundoHidro();
                }
            }
            funcaoSegundoHidro();

        }
    }


    void funcaoChecagemNavios(int tamanho) {
        if(tamanho == 15) { //      ------ CHECANDO NAVIOS MAPA 15X15 ------

            naviosComputadorDestruidos = 0;
            naviosJogadorDestruidos = 0;
            jogador.navios = 5;
            computador.navios = 5;

            void respostaComp(char entidade[12]) {
                printf("\n\t[---] %s do Computador foi destruído!", entidade);
            }

            void respostaJog(char entidade[12]) {
                printf("\n\t[---] %s do Jogador foi destruído!", entidade);
            }


            if (mapa15[jogador.navio1.linha[0]][jogador.navio1.coluna[0]] == 'X' &&
                mapa15[jogador.navio1.linha[1]][jogador.navio1.coluna[1]] == 'X' &&
                mapa15[jogador.navio1.linha[2]][jogador.navio1.coluna[2]] == 'X' ||
                mapa15[jogador.navio1.coluna[0]][jogador.navio1.linha[0]] == 'X' &&
                mapa15[jogador.navio1.coluna[1]][jogador.navio1.linha[1]] == 'X' &&
                mapa15[jogador.navio1.coluna[2]][jogador.navio1.linha[2]] == 'X') {
                respostaJog("Navio 1");
                naviosJogadorDestruidos++;
            }
            if (mapa15Inimigo[computador.navio1.linha[0]][computador.navio1.coluna[0]] == 'X' &&
                mapa15Inimigo[computador.navio1.linha[1]][computador.navio1.coluna[1]] == 'X' &&
                mapa15Inimigo[computador.navio1.linha[2]][computador.navio1.coluna[2]] == 'X' ||
                mapa15Inimigo[computador.navio1.coluna[0]][computador.navio1.linha[0]] == 'X' &&
                mapa15Inimigo[computador.navio1.coluna[1]][computador.navio1.linha[1]] == 'X' &&
                mapa15Inimigo[computador.navio1.coluna[2]][computador.navio1.linha[2]] == 'X') {
                respostaComp("Navio 1");
                naviosComputadorDestruidos++;
            }



            if (mapa15[jogador.navio2.linha[0]][jogador.navio2.coluna[0]] == 'X' &&
                mapa15[jogador.navio2.linha[1]][jogador.navio2.coluna[1]] == 'X' &&
                mapa15[jogador.navio2.linha[2]][jogador.navio2.coluna[2]] == 'X' ||
                mapa15[jogador.navio2.coluna[0]][jogador.navio2.linha[0]] == 'X' &&
                mapa15[jogador.navio2.coluna[1]][jogador.navio2.linha[1]] == 'X' &&
                mapa15[jogador.navio2.coluna[2]][jogador.navio2.linha[2]] == 'X') {
                respostaJog("Navio 2");
                naviosJogadorDestruidos++;
            }
            if (mapa15Inimigo[computador.navio2.linha[0]][computador.navio2.coluna[0]] == 'X' &&
                mapa15Inimigo[computador.navio2.linha[1]][computador.navio2.coluna[1]] == 'X' &&
                mapa15Inimigo[computador.navio2.linha[2]][computador.navio2.coluna[2]] == 'X' ||
                mapa15Inimigo[computador.navio2.coluna[0]][computador.navio2.linha[0]] == 'X' &&
                mapa15Inimigo[computador.navio2.coluna[1]][computador.navio2.linha[1]] == 'X' &&
                mapa15Inimigo[computador.navio2.coluna[2]][computador.navio2.linha[2]] == 'X') {
                respostaComp("Navio 2");
                naviosComputadorDestruidos++;
            }




            if (mapa15[jogador.portaA1.linha[0]][jogador.portaA1.coluna[0]] == 'X' &&
                mapa15[jogador.portaA1.linha[1]][jogador.portaA1.coluna[1]] == 'X' &&
                mapa15[jogador.portaA1.linha[2]][jogador.portaA1.coluna[2]] == 'X' &&
                mapa15[jogador.portaA1.linha[3]][jogador.portaA1.coluna[3]] == 'X' ||
                mapa15[jogador.portaA1.coluna[0]][jogador.portaA1.linha[0]] == 'X' &&
                mapa15[jogador.portaA1.coluna[1]][jogador.portaA1.linha[1]] == 'X' &&
                mapa15[jogador.portaA1.coluna[2]][jogador.portaA1.linha[2]] == 'X' &&
                mapa15[jogador.portaA1.coluna[3]][jogador.portaA1.linha[3]] == 'X') {
                respostaJog("Porta-Avião");
                naviosJogadorDestruidos++;
            }
            if (mapa15Inimigo[computador.portaA1.linha[0]][computador.portaA1.coluna[0]] == 'X' &&
                mapa15Inimigo[computador.portaA1.linha[1]][computador.portaA1.coluna[1]] == 'X' &&
                mapa15Inimigo[computador.portaA1.linha[2]][computador.portaA1.coluna[2]] == 'X' &&
                mapa15Inimigo[computador.portaA1.linha[3]][computador.portaA1.coluna[3]] == 'X' ||
                mapa15Inimigo[computador.portaA1.coluna[0]][computador.portaA1.linha[0]] == 'X' &&
                mapa15Inimigo[computador.portaA1.coluna[1]][computador.portaA1.linha[1]] == 'X' &&
                mapa15Inimigo[computador.portaA1.coluna[2]][computador.portaA1.linha[2]] == 'X' &&
                mapa15Inimigo[computador.portaA1.coluna[3]][computador.portaA1.linha[3]] == 'X') {
                respostaComp("Porta-Avião");
                naviosComputadorDestruidos++;
            }




            if (mapa15[jogador.hidro1.linha[0]][jogador.hidro1.coluna[0]] == 'X' &&
                mapa15[jogador.hidro1.linha[1]][jogador.hidro1.coluna[1]] == 'X' &&
                mapa15[jogador.hidro1.linha[2]][jogador.hidro1.coluna[2]] == 'X') {
                respostaJog("Hidro-Avião 1");
                naviosJogadorDestruidos++;
            }
            if (mapa15Inimigo[computador.hidro1.linha[0]][computador.hidro1.coluna[0]] == 'X' &&
                mapa15Inimigo[computador.hidro1.linha[1]][computador.hidro1.coluna[1]] == 'X' &&
                mapa15Inimigo[computador.hidro1.linha[2]][computador.hidro1.coluna[2]] == 'X') {
                respostaComp("Hidro-Avião 1");
                naviosComputadorDestruidos++;
            }




            if (mapa15[jogador.hidro2.linha[0]][jogador.hidro2.coluna[0]] == 'X' &&
                mapa15[jogador.hidro2.linha[1]][jogador.hidro2.coluna[1]] == 'X' &&
                mapa15[jogador.hidro2.linha[2]][jogador.hidro2.coluna[2]] == 'X') {
                respostaJog("Hidro-Avião 2");
                naviosJogadorDestruidos++;
            }
            if (mapa15Inimigo[computador.hidro2.linha[0]][computador.hidro2.coluna[0]] == 'X' &&
                mapa15Inimigo[computador.hidro2.linha[1]][computador.hidro2.coluna[1]] == 'X' &&
                mapa15Inimigo[computador.hidro2.linha[2]][computador.hidro2.coluna[2]] == 'X') {
                respostaComp("Hidro-Avião 2");
                naviosComputadorDestruidos++;
            }

        } else { //      ------ CHECANDO NAVIOS MAPA 10X10 ------

            naviosComputadorDestruidos = 0;
            naviosJogadorDestruidos = 0;
            jogador.navios = 5;
            computador.navios = 5;

            void respostaComp(char entidade[12]) {
                printf("\n\t[---] %s do Computador foi destruído!", entidade);
            }

            void respostaJog(char entidade[12]) {
                printf("\n\t[---] %s do Jogador foi destruído!", entidade);
            }


            if (mapa10[jogador.navio1.linha[0]][jogador.navio1.coluna[0]] == 'X' &&
                mapa10[jogador.navio1.linha[1]][jogador.navio1.coluna[1]] == 'X' &&
                mapa10[jogador.navio1.linha[2]][jogador.navio1.coluna[2]] == 'X' ||
                mapa10[jogador.navio1.coluna[0]][jogador.navio1.linha[0]] == 'X' &&
                mapa10[jogador.navio1.coluna[1]][jogador.navio1.linha[1]] == 'X' &&
                mapa10[jogador.navio1.coluna[2]][jogador.navio1.linha[2]] == 'X') {
                respostaJog("Navio 1");
                naviosJogadorDestruidos++;
            }
            if (mapa10Inimigo[computador.navio1.linha[0]][computador.navio1.coluna[0]] == 'X' &&
                mapa10Inimigo[computador.navio1.linha[1]][computador.navio1.coluna[1]] == 'X' &&
                mapa10Inimigo[computador.navio1.linha[2]][computador.navio1.coluna[2]] == 'X' ||
                mapa10Inimigo[computador.navio1.coluna[0]][computador.navio1.linha[0]] == 'X' &&
                mapa10Inimigo[computador.navio1.coluna[1]][computador.navio1.linha[1]] == 'X' &&
                mapa10Inimigo[computador.navio1.coluna[2]][computador.navio1.linha[2]] == 'X') {
                respostaComp("Navio 1");
                naviosComputadorDestruidos++;
            }



            if (mapa10[jogador.navio2.linha[0]][jogador.navio2.coluna[0]] == 'X' &&
                mapa10[jogador.navio2.linha[1]][jogador.navio2.coluna[1]] == 'X' &&
                mapa10[jogador.navio2.linha[2]][jogador.navio2.coluna[2]] == 'X' ||
                mapa10[jogador.navio2.coluna[0]][jogador.navio2.linha[0]] == 'X' &&
                mapa10[jogador.navio2.coluna[1]][jogador.navio2.linha[1]] == 'X' &&
                mapa10[jogador.navio2.coluna[2]][jogador.navio2.linha[2]] == 'X') {
                respostaJog("Navio 2");
                naviosJogadorDestruidos++;
            }
            if (mapa10Inimigo[computador.navio2.linha[0]][computador.navio2.coluna[0]] == 'X' &&
                mapa10Inimigo[computador.navio2.linha[1]][computador.navio2.coluna[1]] == 'X' &&
                mapa10Inimigo[computador.navio2.linha[2]][computador.navio2.coluna[2]] == 'X' ||
                mapa10Inimigo[computador.navio2.coluna[0]][computador.navio2.linha[0]] == 'X' &&
                mapa10Inimigo[computador.navio2.coluna[1]][computador.navio2.linha[1]] == 'X' &&
                mapa10Inimigo[computador.navio2.coluna[2]][computador.navio2.linha[2]] == 'X') {
                respostaComp("Navio 2");
                naviosComputadorDestruidos++;
            }




            if (mapa10[jogador.portaA1.linha[0]][jogador.portaA1.coluna[0]] == 'X' &&
                mapa10[jogador.portaA1.linha[1]][jogador.portaA1.coluna[1]] == 'X' &&
                mapa10[jogador.portaA1.linha[2]][jogador.portaA1.coluna[2]] == 'X' &&
                mapa10[jogador.portaA1.linha[3]][jogador.portaA1.coluna[3]] == 'X' ||
                mapa10[jogador.portaA1.coluna[0]][jogador.portaA1.linha[0]] == 'X' &&
                mapa10[jogador.portaA1.coluna[1]][jogador.portaA1.linha[1]] == 'X' &&
                mapa10[jogador.portaA1.coluna[2]][jogador.portaA1.linha[2]] == 'X' &&
                mapa10[jogador.portaA1.coluna[3]][jogador.portaA1.linha[3]] == 'X') {
                respostaJog("Porta-Avião");
                naviosJogadorDestruidos++;
            }
            if (mapa10Inimigo[computador.portaA1.linha[0]][computador.portaA1.coluna[0]] == 'X' &&
                mapa10Inimigo[computador.portaA1.linha[1]][computador.portaA1.coluna[1]] == 'X' &&
                mapa10Inimigo[computador.portaA1.linha[2]][computador.portaA1.coluna[2]] == 'X' &&
                mapa10Inimigo[computador.portaA1.linha[3]][computador.portaA1.coluna[3]] == 'X' ||
                mapa10Inimigo[computador.portaA1.coluna[0]][computador.portaA1.linha[0]] == 'X' &&
                mapa10Inimigo[computador.portaA1.coluna[1]][computador.portaA1.linha[1]] == 'X' &&
                mapa10Inimigo[computador.portaA1.coluna[2]][computador.portaA1.linha[2]] == 'X' &&
                mapa10Inimigo[computador.portaA1.coluna[3]][computador.portaA1.linha[3]] == 'X') {
                respostaComp("Porta-Avião");
                naviosComputadorDestruidos++;
            }




            if (mapa10[jogador.hidro1.linha[0]][jogador.hidro1.coluna[0]] == 'X' &&
                mapa10[jogador.hidro1.linha[1]][jogador.hidro1.coluna[1]] == 'X' &&
                mapa10[jogador.hidro1.linha[2]][jogador.hidro1.coluna[2]] == 'X') {
                respostaJog("Hidro-Avião 1");
                naviosJogadorDestruidos++;
            }
            if (mapa10Inimigo[computador.hidro1.linha[0]][computador.hidro1.coluna[0]] == 'X' &&
                mapa10Inimigo[computador.hidro1.linha[1]][computador.hidro1.coluna[1]] == 'X' &&
                mapa10Inimigo[computador.hidro1.linha[2]][computador.hidro1.coluna[2]] == 'X') {
                respostaComp("Hidro-Avião 1");
                naviosComputadorDestruidos++;
            }




            if (mapa10[jogador.hidro2.linha[0]][jogador.hidro2.coluna[0]] == 'X' &&
                mapa10[jogador.hidro2.linha[1]][jogador.hidro2.coluna[1]] == 'X' &&
                mapa10[jogador.hidro2.linha[2]][jogador.hidro2.coluna[2]] == 'X') {
                respostaJog("Hidro-Avião 2");
                naviosJogadorDestruidos++;
            }
            if (mapa10Inimigo[computador.hidro2.linha[0]][computador.hidro2.coluna[0]] == 'X' &&
                mapa10Inimigo[computador.hidro2.linha[1]][computador.hidro2.coluna[1]] == 'X' &&
                mapa10Inimigo[computador.hidro2.linha[2]][computador.hidro2.coluna[2]] == 'X') {
                respostaComp("Hidro-Avião 2");
                naviosComputadorDestruidos++;
            }

        }
    }


    void funcaoJogadorAtacar(int tamanho) {
        if(tamanho == 15) { // ------ JOGADOR ATACANDO NO MAPA 15X15 ------

            printf("\n[+] Digite as coordenadas para atacar (lin col) (0 até 14): ");
            printf("\n");
            if (scanf("%d%d", &ataque, &ataque2)) { //trabalhar
                if (mapa15Inimigo[ataque][ataque2] == estrutura) {
                    mapa15Inimigo[ataque][ataque2] = 'X';
                    mapa15InimigoMostrar[ataque][ataque2] = 'X';
                    jogador.tirosCerteiros++;
                    printf("Navio do inimigo atingido na posição [%d][%d]", ataque, ataque2);
                    printf("\nnavios destruidas do inimigo: %d\n\n", naviosComputadorDestruidos);
                } else if (mapa15Inimigo[ataque][ataque2] == 'X') {
                    mapa15Inimigo[ataque][ataque2] = 'X';
                    mapa15InimigoMostrar[ataque][ataque2] = 'X';
                    printf("\nPosição já atacada. Escolha outra coordenada.\n");
                    funcaoJogadorAtacar(tamanhoMapa);
                } else if (mapa15Inimigo[ataque][ataque2] == '-') {
                    mapa15Inimigo[ataque][ataque2] = '-';
                    mapa15InimigoMostrar[ataque][ataque2] = '-';
                    printf("\nPosição já atacada. Escolha outra coordenada.\n");
                    funcaoJogadorAtacar(tamanhoMapa);
                } else {
                    mapa15InimigoMostrar[ataque][ataque2] = '-';
                    mapa15Inimigo[ataque][ataque2] = '-';
                    printf("\npartes destruidas do inimigo contagem: %d\n\n", naviosComputadorDestruidos);
                    jogador.tirosPerdidos++;
                }

                getch();

            } else {
                printf("O dado de entrada não é um número... tente outra vez.\n");
                getch();
                funcaoJogadorAtacar(tamanhoMapa);
            }

        } else { // ------ JOGADOR ATACANDO NO MAPA 10X10 ------

            printf("\n[+] Digite as coordenadas para atacar (lin col) (0 até 14): ");
            printf("\n");
            if (scanf("%d%d", &ataque, &ataque2)) { //trabalhar
                if (mapa10Inimigo[ataque][ataque2] == estrutura) {
                    mapa10Inimigo[ataque][ataque2] = 'X';
                    mapa10InimigoMostrar[ataque][ataque2] = 'X';
                    jogador.tirosCerteiros++;
                    printf("Navio do inimigo atingido na posição [%d][%d]", ataque, ataque2);
                    printf("\nnavios destruidas do inimigo: %d\n\n", naviosComputadorDestruidos);
                } else if (mapa10Inimigo[ataque][ataque2] == 'X') {
                    mapa10Inimigo[ataque][ataque2] = 'X';
                    mapa10InimigoMostrar[ataque][ataque2] = 'X';
                    printf("\nPosição já atacada. Escolha outra coordenada.\n");
                    funcaoJogadorAtacar(tamanhoMapa);
                } else if (mapa10Inimigo[ataque][ataque2] == '-') {
                    mapa10Inimigo[ataque][ataque2] = '-';
                    mapa10InimigoMostrar[ataque][ataque2] = '-';
                    printf("\nPosição já atacada. Escolha outra coordenada.\n");
                    funcaoJogadorAtacar(tamanhoMapa);
                } else {
                    mapa10Inimigo[ataque][ataque2] = '-';
                    mapa10InimigoMostrar[ataque][ataque2] = '-';
                    printf("\npartes destruidas do inimigo contagem: %d\n\n", naviosComputadorDestruidos);
                    jogador.tirosPerdidos++;
                }

                getch();

            } else {
                printf("O dado de entrada não é um número... tente outra vez.\n");
                getch();
                funcaoJogadorAtacar(tamanhoMapa);
            }

        }
    }

    void funcaoComputadorAtacar(int tamanho) {
        if(tamanho == 15) { //      ------ COMPUTADOR ATACANDO NO MAPA 15X15 ------

            randAtaqueLin = rand() % 14;
            randAtaqueCol = rand() % 14;

            if (mapa15[randAtaqueLin][randAtaqueCol] == estrutura) {
                mapa15[randAtaqueLin][randAtaqueCol] = 'X';
                computador.tirosCerteiros++;
                printf("Navio do jogador atingido na posição [%d][%d]", randAtaqueLin, randAtaqueCol);
                printf("\nnavios destruidas do jogador: %d\n\n", naviosJogadorDestruidos);
            } else if (mapa15[randAtaqueLin][randAtaqueCol] == 'X') {
                mapa15[randAtaqueLin][randAtaqueCol] = 'X';
                funcaoComputadorAtacar(tamanhoMapa);
            } else if (mapa15[randAtaqueLin][randAtaqueCol] == '-') {
                mapa15[randAtaqueLin][randAtaqueCol] = '-';
                funcaoComputadorAtacar(tamanhoMapa);
            } else {
                mapa15[randAtaqueLin][randAtaqueCol] = '-';
                printf("\npartes destruidas do jogador contagem: %d\n\n", naviosJogadorDestruidos);
                computador.tirosPerdidos++;
            }

            getch();

        } else { //      ------ COMPUTADOR ATACANDO NO MAPA 10X10 ------

            randAtaqueLin = rand() % 9;
            randAtaqueCol = rand() % 9;

            if (mapa10[randAtaqueLin][randAtaqueCol] == estrutura) {
                mapa10[randAtaqueLin][randAtaqueCol] = 'X';
                computador.tirosCerteiros++;
                printf("Navio do jogador atingido na posição [%d][%d]", randAtaqueLin, randAtaqueCol);
                printf("\nnavios destruidas do jogador: %d\n\n", naviosJogadorDestruidos);
            } else if (mapa10[randAtaqueLin][randAtaqueCol] == 'X') {
                mapa10[randAtaqueLin][randAtaqueCol] = 'X';
                funcaoComputadorAtacar(tamanhoMapa);
            } else if (mapa10[randAtaqueLin][randAtaqueCol] == '-') {
                mapa10[randAtaqueLin][randAtaqueCol] = '-';
                funcaoComputadorAtacar(tamanhoMapa);
            } else {
                mapa10[randAtaqueLin][randAtaqueCol] = '-';
                printf("\npartes destruidas do jogador contagem: %d\n\n", naviosJogadorDestruidos);
                computador.tirosPerdidos++;
            }

            getch();

        }

    }

    void funcaoEscolherMapa() {
        printf("Digite o tamanho do mapa que pretende jogar - 10x10 ou 15x15 (digite 10 ou 15): ");
        if (scanf("%d*%c", &tamanhoMapa)) {
            if (tamanhoMapa == 10 || tamanhoMapa == 15) {
                printf("Mapa de tamanho %dx%d escolhido.", tamanhoMapa, tamanhoMapa);
                getch();
                funcaoApagarTela();
            } else {
                funcaoApagarTela();
                printf("Tamanho não disponível... tente outra vez.\n");
                funcaoEscolherMapa();
            }
        } else { //      ------ ARRUMAR ------
            funcaoApagarTela();
            printf("Letras, caracteres e símbolos não são permitidos... tente outra vez.\n");
            funcaoEscolherMapa();
        }
    }

    funcaoEscolherMapa();
    mapaGerado = funcaoGerarMapa(tamanhoMapa);
    if(mapaGerado == 1) {
        printf("Mapa gerado com sucesso!\n");
    } else {
        printf("Erro na geração de mapa!\n");
    }
    funcaoGerarNaviosJogador(tamanhoMapa);
    funcaoGerarNaviosComputador(tamanhoMapa);
    funcaoImprimirRelatorioPartida(tamanhoMapa);
    funcaoImprimirMapa(tamanhoMapa);

    vez = rand() % 1; //escolhendo de 0 a 1, quem será o primeiro a jogar
    //vez = 0;

    while (jogoEncerrado != 1) {

        if (vez == 0) { //decidindo quem joga de acordo com a variável "vez"
            printf("\n - Vez do Computador atacar!\n");
            funcaoComputadorAtacar(tamanhoMapa);
            vez = 1;
        } else {
            printf("\n - Vez do Jogador atacar!\n");
            funcaoJogadorAtacar(tamanhoMapa);
            vez = 0;
        }

        jogador.navios -= naviosJogadorDestruidos;
        computador.navios -= naviosComputadorDestruidos;

        void funcaoApagarImprimirEChecar() {
            funcaoApagarTela();
            funcaoImprimirRelatorioPartida(tamanhoMapa);
            funcaoChecagemNavios(tamanhoMapa);
            funcaoImprimirMapa(tamanhoMapa);

        }
        funcaoApagarImprimirEChecar();

        void funcaoImprimirPosicoes() {
            printf("\COMPUTADOR NAVIO 1: %d %d, %d %d, %d %d\n",
                   computador.navio1.linha[0], computador.navio1.coluna[0],
                   computador.navio1.linha[1], computador.navio1.coluna[1],
                   computador.navio1.linha[2], computador.navio1.coluna[2]
                   );
            printf("COMPUTADOR NAVIO 2: %d %d, %d %d, %d %d\n",
                   computador.navio2.linha[0], computador.navio2.coluna[0],
                   computador.navio2.linha[1], computador.navio2.coluna[1],
                   computador.navio2.linha[2], computador.navio2.coluna[2]
                   );
            printf("COMPUTADOR PORTA AVIAO: %d %d, %d %d, %d %d, %d %d\n",
                   computador.portaA1.linha[0], computador.portaA1.coluna[0],
                   computador.portaA1.linha[1], computador.portaA1.coluna[1],
                   computador.portaA1.linha[2], computador.portaA1.coluna[2],
                   computador.portaA1.linha[3], computador.portaA1.coluna[3]
                   );
            printf("COMPUTADOR HIDRO 1: %d %d, %d %d, %d %d\n",
                   computador.hidro1.linha[0], computador.hidro1.coluna[0],
                   computador.hidro1.linha[1], computador.hidro1.coluna[1],
                   computador.hidro1.linha[2], computador.hidro1.coluna[2]
                   );
            printf("COMPUTADOR HIDRO 2: %d %d, %d %d, %d %d",
                   computador.hidro2.linha[0], computador.hidro2.coluna[0],
                   computador.hidro2.linha[1], computador.hidro2.coluna[1],
                   computador.hidro2.linha[2], computador.hidro2.coluna[2]
                   );

            printf("\nJOGADOR NAVIO 1: %d %d, %d %d, %d %d\n",
                   jogador.navio1.linha[0], jogador.navio1.coluna[0],
                   jogador.navio1.linha[1], jogador.navio1.coluna[1],
                   jogador.navio1.linha[2], jogador.navio1.coluna[2]
                   );
            printf("JOGADOR NAVIO 2: %d %d, %d %d, %d %d\n",
                   jogador.navio2.linha[0], jogador.navio2.coluna[0],
                   jogador.navio2.linha[1], jogador.navio2.coluna[1],
                   jogador.navio2.linha[2], jogador.navio2.coluna[2]
                   );
            printf("JOGADOR PORTA AVIAO: %d %d, %d %d, %d %d, %d %d\n",
                   jogador.portaA1.linha[0], jogador.portaA1.coluna[0],
                   jogador.portaA1.linha[1], jogador.portaA1.coluna[1],
                   jogador.portaA1.linha[2], jogador.portaA1.coluna[2],
                   jogador.portaA1.linha[3], jogador.portaA1.coluna[3]
                   );
            printf("JOGADOR HIDRO 1: %d %d, %d %d, %d %d\n",
                   jogador.hidro1.linha[0], jogador.hidro1.coluna[0],
                   jogador.hidro1.linha[1], jogador.hidro1.coluna[1],
                   jogador.hidro1.linha[2], jogador.hidro1.coluna[2]
                   );
            printf("JOGADOR HIDRO 2: %d %d, %d %d, %d %d\n",
                   jogador.hidro2.linha[0], jogador.hidro2.coluna[0],
                   jogador.hidro2.linha[1], jogador.hidro2.coluna[1],
                   jogador.hidro2.linha[2], jogador.hidro2.coluna[2]
                   );
        }
        //funcaoImprimirPosicoes();

        void funcaoPerguntarProximaPartida() { // FUNÇÃO SEM RETORNO E SEM PARÂMETRO
            printf("\n[+] Deseja jogar outra partida [s ou n]? ");
            fflush(stdin);
            scanf("%c", &novaPart);
            if (novaPart == 's') {
                jogoEncerrado = 0;
                funcaoApagarTela();
                printf("Reiniciando...");
                naviosJogadorDestruidos = 0;
                naviosComputadorDestruidos = 0;
                jogador.tirosCerteiros = 0;
                jogador.tirosPerdidos = 0;
                jogador.navios = 5;
                computador.tirosCerteiros = 0;
                computador.tirosPerdidos = 0;
                computador.navios = 5;
                getch();
                funcaoApagarTela();

                funcaoEscolherMapa();
                funcaoGerarMapa(tamanhoMapa);
                funcaoGerarNaviosJogador(tamanhoMapa);
                funcaoGerarNaviosComputador(tamanhoMapa);
                funcaoImprimirRelatorioPartida(tamanhoMapa);
                funcaoImprimirMapa(tamanhoMapa);

            } else if (novaPart == 'n'){
                exit(1);
            } else {
                printf("\nOpção não listada... Tente novamente.");
                funcaoPerguntarProximaPartida();
            }
        }
        if (naviosComputadorDestruidos == 3) {
            funcaoApagarImprimirEChecar();
            jogoEncerrado = 1;
            printf("\nPARTIDA ENCERRADA!\nVitória do Jogador!\n");
            jogador.vitorias++;
            computador.derrotas++;
            funcaoPerguntarProximaPartida();
        } else if (naviosJogadorDestruidos == 3) {
            funcaoApagarImprimirEChecar();
            jogoEncerrado = 1;
            printf("\nPARTIDA ENCERRADA!\nVitória do Computador!\n");
            computador.vitorias++;
            jogador.derrotas++;
            funcaoPerguntarProximaPartida();
        }
    }

    return 0;
}
