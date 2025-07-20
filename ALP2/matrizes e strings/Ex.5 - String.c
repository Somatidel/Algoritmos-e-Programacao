//Rafael Luiz de Oliveira PE3028534
//Eduardo Viana PE3029387

#include <stdio.h>
#include <string.h>

void ler_matriz_inteiros(int matriz[10][10], int linhas, int colunas)
{
    int i,
        j;

    printf("\nPreencha a matriz\n\n");
    for(i=0; i<linhas; i++)
        for(j=0; j<colunas; j++)
        {
            printf("Matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
}

void soma_linhas(int matriz[10][10], int somatoria[], int linhas, int colunas)
{
    int i,
        j,
        soma=0;

    for(i=0; i<linhas; i++)
    {
        for(j=0; j<colunas; j++)
            soma += matriz[i][j];

        somatoria[i] = soma;
        soma = 0;
    }
}

void soma_colunas(int matriz[10][10], int somatoria[], int linhas, int colunas)
{
    int i,
        j,
        soma=0;

    for(j=0; j<colunas; j++)
    {
        for(i=0; i<linhas; i++)
            soma += matriz[i][j];

        somatoria[j] = soma;
        soma = 0;
    }
}

int encontrar_maior_soma_linha(int somatoria[], int linhas, int *pos_linha)
{
    int i,
        maior;

    *pos_linha = 0;
    maior = somatoria[0];
    for(i=1; i<linhas; i++)
        if(somatoria[i] > maior)
        {
            maior = somatoria[i];
            *pos_linha = i;
        }

    return maior;
}

int pos_maior_elemento(int matriz[10][10], int linhas, int colunas, int *pos_linha, int *pos_coluna)
{
    int i,
        j,
        maior;

    *pos_linha = 0;
    *pos_coluna = 0;
    maior = matriz[0][0];
    for(i=0; i<linhas; i++)
        for(j=0; j<colunas; j++)
            if(matriz[i][j] > maior)
            {
                maior = matriz[i][j];
                *pos_linha = i;
                *pos_coluna = j;
            }

    return maior;
}

int pos_menor_elemento(int matriz[10][10], int linhas, int colunas, int *pos_linha, int *pos_coluna)
{
    int i,
        j,
        menor;

    *pos_linha = 0;
    *pos_coluna = 0;
    menor = matriz[0][0];
    for(i=0; i<linhas; i++)
        for(j=0; j<colunas; j++)
            if(matriz[0][0] < menor)
            {
                menor = matriz[i][j];
                *pos_linha = i;
                *pos_coluna = j;
            }

    return menor;
}

void main()
{
    int i,
        linhas,
        colunas,
        pos_linha,
        maior_soma,
        pos_coluna,
        maior_elemento,
        menor_elemento,
        soma_linha[10],
        soma_coluna[10],
        matriz_int[10][10];

    printf("Quantas linhas tera a matriz? (MAX 10)\n");
    do
    {
        scanf("%d", &linhas);

        if(linhas < 0 || linhas > 10)
            printf("Insira uma valor entre 0 e 10...\n");
    }
    while(linhas < 0 || linhas > 10);

    printf("\nQuantas colunas tera a matriz? (MAX 10)\n");
    do
    {
        scanf("%d", &colunas);

        if(colunas < 0 || colunas > 10)
            printf("Insira uma valor entre 0 e 10...\n\n");
    }
    while(colunas < 0 || colunas > 10);

    ler_matriz_inteiros(matriz_int, linhas, colunas);

    soma_linhas(matriz_int, soma_linha, linhas, colunas);
    printf("\nSomatoria de cada linha:\n");
    for(i=0; i<linhas; i++)
        printf("Soma[%d] - %d.\n", i, soma_linha[i]);

    soma_colunas(matriz_int, soma_coluna, linhas, colunas);
    printf("\nSomatoria de cada coluna:\n");
    for(i=0; i<colunas; i++)
        printf("Soma[%d] - %d.\n", i, soma_coluna[i]);

    maior_soma = encontrar_maior_soma_linha(soma_linha, linhas, &pos_linha);
    printf("\nLinha %d possui a maior soma de elementos - %d.\n\n", pos_linha, maior_soma);

    maior_elemento = pos_maior_elemento(matriz_int, linhas, colunas, &pos_linha, &pos_coluna);
    printf("O maior elemento [%d] esta na linha %d e coluna %d.\n", maior_elemento, pos_linha, pos_coluna);

    menor_elemento = pos_menor_elemento(matriz_int, linhas, colunas, &pos_linha, &pos_coluna);
    printf("O menor elemento [%d] esta na linha %d e coluna %d.\n", menor_elemento, pos_linha, pos_coluna);

}
