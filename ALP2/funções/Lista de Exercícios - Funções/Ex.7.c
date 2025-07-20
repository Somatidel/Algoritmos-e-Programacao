//Kauan Silva Camargo - PE3028488
//Rafael Luiz de Oliveira - PE3028534

#include<stdio.h>
#define TF 5

void menu(int *op)
{
    printf("1. Ler dois vetores inteiros a e b, com 5 elementos;\n");
    printf("2. Colocar os elementos dos dois vetores a e b, em um terceiro vetor c com tamanho de 10 elementos;\n");
    printf("3. Imprimir qual dos dois (a e b) tem a maior soma de elementos;\n");
    printf("4. Multiplicar os elementos do vetor c por um valor inteiro e apresentar;\n");
    printf("5. Trocar os elementos entre os vetores a e b;\n");
    printf("6. Apresentar os elementos dos vetores a e b;\n");
    printf("0. Sair do programa.\n\n");
    printf("Operacao: ");
    scanf("%d", op);
}

void ler_vetor(int vetor[])
{
    int i;

    printf("\n");
    for(i=0; i<TF; i++)
    {
        printf("Vetor[%d]: ", i);
        scanf("%d", &vetor[i]);
    }
}

void colocar_em_vetor(int v1[], int v2[], int v3[])
{
    int i;

    for(i=0; i<TF; i++)
    {
        v3[i] = v1[i];
        v3[i+TF] = v2[i];
    }
}

void maior_soma(int v1[], int v2[])
{
    int i,
        soma1=0,
        soma2=0;

    for(i=0; i<TF; i++)
    {
        soma1 += v1[i];
        soma2 += v2[i];
    }

    if(soma1 > soma2)
        printf("\nO vetor (a) tem a maior soma de elementos...\n");
    else if(soma1 < soma2)
        printf("\nO vetor (b) tem a maior soma de elementos...\n");
    else
        printf("\nAmbos tem a mesma soma de elementos...\n");
}

void multiplicar_vetor(int vetor[])
{
    int i,
        valor;

    printf("\nPor qual valor inteiro multiplicar os elementos do vetor?\n");
    scanf("%d", &valor);

    for(i=0; i<2*TF; i++)
        vetor[i] *= valor;
}

void trocar_elementos(int v1[], int v2[])
{
    int i,
        buf;

    for(i=0; i<TF; i++)
    {
        buf = v1[i];
        v1[i] = v2[i];
        v2[i] = buf;
    }
}

void apresentar_vetor(int vetor[])
{
    int i;

    printf("\n");
    for(i=0; i<TF; i++)
        printf("Vetor[%d]: %d.\n", i, vetor[i]);
    printf("\n");
}

void main()
{
    int i,
        op,
        a[TF],
        b[TF],
        c[2*TF];

    do
    {
        menu(&op);

        switch(op)
        {
        case 0:
            printf("\nFim do programa...\n");
            break;

        case 1:
            printf("\nLendo vetor (a)...\n");
            ler_vetor(a);

            printf("\nLendo vetor (b)...\n");
            ler_vetor(b);
            printf("\n");
            break;

        case 2:
            colocar_em_vetor(a, b, c);
            printf("\nVetor (c) preenchido.\n\n");
            break;

        case 3:
            maior_soma(a, b);
            printf("\n");
            break;

        case 4:
            multiplicar_vetor(c);

            printf("\nApresentando vetor(c)...\n\n");
            for(i=0; i<TF*2; i++)
                printf("Vetor[%d]: %d.\n", i, c[i]);

            printf("\n");
            break;

        case 5:
            printf("\nTrocando elementos...\n");
            trocar_elementos(a, b);
            printf("\nElementos substituídos.\n\n");
            break;

        case 6:
            printf("\nApresentando vetor (a)...\n");
            apresentar_vetor(a);

            printf("Apresentando vetor (b)...\n");
            apresentar_vetor(b);
            break;

        default:
            printf("\nDigite uma operacao valida...\n\n");
        }
    }
    while(op != 0);
    }
