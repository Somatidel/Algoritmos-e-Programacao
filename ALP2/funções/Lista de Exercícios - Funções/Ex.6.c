//Kauan Silva Camargo - PE3028488
//Rafael Luiz de Oliveira - PE3028534

#include<stdio.h>
#define TF 50

void ler_prontuario(int vetor[], int *alunos)
{
    int prontuario;

    printf("Insira os prontuarios dos alunos (0 para finalizar)...\n\n");
    do
    {
        printf("Aluno %d: ", *alunos+1);
        scanf("%d", &prontuario);

        if(prontuario < 0)
            printf("\nInsira um prontuario valido...\n\n");

        if(prontuario > 0)
        {
            vetor[*alunos] = prontuario;
            (*alunos)++;
        }
    }
    while(prontuario != 0 && *alunos < TF);

    printf("\nFim de leitura.\n");
}

void apresentar_posicao(int vetor[], int alunos, int prontuario)
{
    int i,
        pos=0;

    for(i=0; i<alunos; i++)
        if(vetor[i] == prontuario)
        {
            printf("\nEsse aluno esta na posicao %d na lista de classificacao.\n\n", i+1);
            pos=i;
        }

    if(pos == 0)
        printf("\nNao encontrado...\n\n");
}

void apresentar_beneficiados(int vetor[], int beneficiados)
{
    int i;

    printf("\nAlunos beneficiados...\n\n");
    for(i=0; i<beneficiados; i++)
        printf("Aluno %d: %d.\n", i+1, vetor[i]);
}

void apresentar_classificacao(int vetor[], int alunos, int beneficiados)
{
    int i;

    printf("\nApresentando classificacao completa:\n\n");
    for(i=0; i<alunos; i++)
    {
        printf("Aluno %d: %d ", i+1, vetor[i]);
        if(i < beneficiados)
            printf("- beneficiado.\n");
        else
            printf("- desclassificado.\n");
    }
}

void main()
{
    int prontuario[TF],
        beneficiados,
        alunos=0,
        pront;

    ler_prontuario(prontuario, &alunos);

    printf("Qual prontuario deseja encontrar a posicao?\n");
    scanf("%d", &pront);
    apresentar_posicao(prontuario, alunos, pront);

    printf("Quantos alunos serao beneficiados?\n");
    scanf("%d", &beneficiados);
    apresentar_beneficiados(prontuario, beneficiados);

    apresentar_classificacao(prontuario, alunos, beneficiados);
}
