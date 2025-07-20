#include<stdio.h>
#define TF 30

int incluir_No_Final(int vetor[], int tl)
{
    int i,
        num;

    if(tl >= TF)
    {
        printf("\nO vetor ja atingiu o tamanho maximo...\n");
        return tl;
    }

    printf("\nQual numero sera incluido no final do vetor?\n");
    scanf("%d", &num);

    vetor[tl] = num;

    tl++;
    return tl;
}

int incluir_Na_Posicao(int vetor[], int tl)
{
    int i,
        num,
        pos;

    if(tl >= TF)
    {
        printf("\nO vetor ja atingiu o tamanho maximo...\n");
        return tl;
    }

    do
    {
        printf("\nEm qual posicao o numero sera inserido?\n");
        scanf("%d", &pos);

        if(pos < 0 || pos > tl)
            printf("\n\nInsira um valor valido dentro dos limites do vetor...\n");

    }while(pos < 0 || pos > tl);

    printf("\nQual numero sera incluido na posicao?\n");
    scanf("%d", &num);

    for(i=tl; i>pos; i--)
    {
        vetor[i] = vetor[i-1];
    }
    vetor[pos] = num;

    tl++;
    return tl;
}

int incluir_No_Inicio(int vetor[], int tl)
{
    int i,
        num;

    if(tl >= TF)
    {
        printf("\nO vetor ja atingiu o tamanho maximo...\n");
        return tl;
    }

    printf("Qual numero sera incluido no inicio do vetor?\n");
    scanf("%d", &num);

    for(i=tl; i>0; i--)
        vetor[i] = vetor[i-1];
    vetor[0] = num;

    tl++;
    return tl;
}

int excluir_No_Inicio(int vetor[], int tl)
{
    int i;

    if(tl <= 0)
    {
        printf("\n\nNão eh possivel excluir (tamanho minimo atingido).\n");
        return tl;
    }

    for(i=0; i<tl; i++)
        vetor[i] = vetor[i+1];

    tl--;
    return tl;
}

int excluir_No_Final(int vetor[], int tl)
{
    if(tl <= 0)
    {
        printf("\n\nNao eh possivel excluir (tamanho minimo atingido).\n");
        return tl;
    }

    tl--;
    return tl;
}

int excluir_Na_Posicao(int vetor[], int tl)
{
    int i,
        pos;

    if(tl <= 0)
    {
        printf("\n\nNão eh possivel excluir (tamanho minimo atingido).\n");
        return tl;
    }

    do
    {
        printf("Em qual posicao o numero sera inserido?\n");
        scanf("%d", &pos);

        if(pos < 0 || pos > tl)
            printf("\n\nInsira um valor valido dentro dos limites do vetor...\n");

    }while(pos < 0 || pos > tl);

    if(pos < 0 || pos > tl)
    {
        printf("\n\nPosicao invalida, insira uma posicao dentro do tamanho do vetor...\n");
        return tl;
    }

    for(i=pos; i<tl; i++)
        vetor[i] = vetor[i+1];

    tl--;
    return tl;
}
void apresentar_Vetor(int vetor[], int tl)
{
    int i;

    printf("\n\nApresentando vetores...:\n");
    for(i=0; i<tl; i++)
        printf("\nVetor[%d] - %d.", i, vetor[i]);
    printf("\n");
    printf("\n");
}

int excluir_Elemento(int vetor[], int tl)
{
    int i,
        num,
        novo_tl=0;

    if(tl <= 0)
    {
        printf("\n\nNão eh possivel excluir (tamanho minimo atingido).\n");
        return tl;
    }

    printf("\nQual elemento devera ser excluido?\n");
    scanf("%d", &num);

    for(i=0; i<tl; i++)
        if(vetor[i] != num)
        {
            vetor[novo_tl] = vetor[i];
            novo_tl++;
        }

    if(novo_tl == tl)
        printf("\nElemento %d nao foi encontrado...\n", num);

    tl = novo_tl;
    return tl;

}

void localizar_Elemento(int vetor[], int tl)
{
    int i,
        num,
        pos=-1;

    printf("\nQual numero deve-se localizar?\n");
    scanf("%d", &num);
    printf("\n");

    for(i=0; i<tl; i++)
        if(vetor[i] == num)
        {
            pos=i;
            printf("\nVetor[%d]: %d.", pos, num);
        }

    if(pos == -1)
        printf("\nElemento nao localizado...\n");
}

int excluir_Entre_Posicao(int vetor[], int tl)
{
    int i,
        min,
        max,
        new_tl=0,
        intervalo;

    if(tl <= 0)
    {
        printf("\n\nNão eh possivel excluir (tamanho minimo atingido).\n");
        return tl;
    }

    do
    {
        printf("\nInforme entre quais posicoes os elementos serao excluidos(min e max): ");
        scanf("%d %d", &min, &max);

        if(max > tl || min < 0)
            printf("\n\nInforme um valor minimo e maximo validos (dentro do intervalo do vetor).\n");

    }while(max > tl || min < 0);

    intervalo = max - min - 1;

    for(i = max; i<tl; i++)
        vetor[i - intervalo] = vetor[i];


    tl -= intervalo;
    return tl;
}

void main()
{
    int op,
        tl,
        vetor[TF];

    do
    {
        printf("1. Incluir um numero no final do vetor;\n");
        printf("2. Incluir um numero em uma determinada posicao definida pelo usuario;\n");
        printf("3. Incluir um numero no inicio do vetor;\n");
        printf("4. Excluir o primeiro elemento do vetor;\n");
        printf("5. Excluir o ultimo elemento do vetor;\n");
        printf("6. Excluir um elemento de uma posicao indicada pelo usuario;\n");
        printf("7. Apresentar o vetor inteiro;\n");
        printf("8. Excluir um determinado elemento determinado pelo usuario;\n");
        printf("9. Localizar e apresentar a posicao de um determinado elemento do vetor.\n");
        printf("10. Excluir os elementos entre duas posicoes do vetor;\n");
        printf("0. Sair do programa.\n");
        printf("\nOpcao: ");
        scanf("%d", &op);

        switch(op)
        {
        case 0:
            printf("\nFim de programa...\n");
            break;

        case 1:
            tl = incluir_No_Final(vetor, tl);
            break;

        case 2:
            tl = incluir_Na_Posicao(vetor, tl);
            break;

        case 3:
            tl = incluir_No_Inicio(vetor, tl);
            break;

        case 4:
            tl = excluir_No_Inicio(vetor, tl);
            break;

        case 5:
            tl = excluir_No_Final(vetor, tl);
            break;

        case 6:
            tl = excluir_Na_Posicao(vetor, tl);
            break;

        case 7:
            apresentar_Vetor(vetor, tl);
            break;

        case 8:
            tl = excluir_Elemento(vetor, tl);
            break;

        case 9:
            localizar_Elemento(vetor, tl);
            break;

        case 10:
            tl = excluir_Entre_Posicao(vetor, tl);
            break;

        default:
            printf("\nDigite uma opcao valida...\n\n");
        }
    }while(op !=0);
}
