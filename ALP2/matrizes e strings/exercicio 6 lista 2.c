//Eduardo Viana PE3029387
//Rafael Luiz de Oliveira PE3028534

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TF 10
#define TOTAL 20

void inicializarMatriz(int matriz[TF][TF]) {
    for (int i = 0; i < TF; i++)
        for (int j = 0; j < TF; j++)
            matriz[i][j] = 0;
}

void inserirNumerosAleatorios(int matriz[TF][TF]) {
    int count = 0;
    while (count < 20) {
        int linha = rand() % TF;
        int coluna = rand() % TF;
        if (matriz[linha][coluna] == 0) {
            matriz[linha][coluna] = (rand() % 19) + 2;
            count++;
        }
    }
}

void jogar(int matriz[TF][TF]) {
    int pontosUsuario = 0, pontosMaquina = 0;
    int linha, coluna;

    for (int i = 0; i < TOTAL; ) {
        printf("Rodada %d - Sua vez!\n", i + 1);
        printf("Escolha a linha (1-10) e a coluna (1-10): ");
        scanf("%d %d", &linha, &coluna);

        linha--;
        coluna--;

        if (linha >= 0 && linha < TF && coluna >= 0 && coluna < TF) {
            if (matriz[linha][coluna] != 0) {
                pontosUsuario += matriz[linha][coluna];
                matriz[linha][coluna] = 0;
                printf("Voce atingiu! Pontos: %d\n", pontosUsuario);
            } else {
                printf("Nada atingido!\n");
            }
            i++;
        } else {
            printf("Posicao invalida!\n");
        }

        linha = rand() % TF;
        coluna = rand() % TF;
        if (matriz[linha][coluna] != 0) {
            pontosMaquina += matriz[linha][coluna];
            matriz[linha][coluna] = 0;
            printf("Maquina atingiu na posicao [%d][%d]! Pontos da maquina: %d\n", linha + 1, coluna + 1, pontosMaquina);
        } else {
            printf("Maquina nao atingiu.\n");
        }
    }

    printf("Pontuacao final: Voce: %d, Maquina: %d\n", pontosUsuario, pontosMaquina);
    if (pontosUsuario > pontosMaquina) {
        printf("Voce venceu!\n");
    } else if (pontosUsuario < pontosMaquina) {
        printf("Maquina venceu!\n");
    } else {
        printf("Empate!\n");
    }
}

int main() {
    int matriz[TF][TF];
    srand(time(NULL));
    inicializarMatriz(matriz);
    inserirNumerosAleatorios(matriz);
    jogar(matriz);
    return 0;
}
