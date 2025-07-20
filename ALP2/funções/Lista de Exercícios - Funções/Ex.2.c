//Kauan Silva Camargo - PE3028488
//Rafael Luiz de Oliveira - PE3028534

#include<stdio.h>
#define TF 50

void ler_nota_alunos(float nota1[], float nota2[], int *alunos)
{
    float primeira_nota,
          segunda_nota;

    do
    {
        printf("Insira as notas do 1o. e 2o. bimestre do %do. aluno (-1 para finalizar):\n", *alunos+1);
        printf("Nota 1 - ");
        scanf("%f", &primeira_nota);

        printf("Nota 2 - ");
        scanf("%f", &segunda_nota);

        if(primeira_nota == -1 || segunda_nota == -1)
            printf("Insira pelo menos uma dupla de notas validas...\n\n");

    }
    while(primeira_nota == -1 || segunda_nota == -1 );
    while(primeira_nota != -1 && segunda_nota != -1 && *alunos < TF)
    {
        if(primeira_nota >= 0 && primeira_nota <= 10 && segunda_nota >= 0 && segunda_nota <= 10 && *alunos < TF)
        {
            nota1[*alunos] = primeira_nota;
            nota2[*alunos] = segunda_nota;
            (*alunos)++;
        }
        else if(primeira_nota < 0 || primeira_nota > 10 || segunda_nota < 0 || segunda_nota > 0 && primeira_nota != -1 && segunda_nota != -1)
            printf("Insira uma nota valida(maior ou igual a 0 e menor ou igual a 10).\n\n");

        if(*alunos < TF)
        {
            printf("Insira as notas do 1o. e 2o. bimestre do %do. aluno (-1 para finalizar):\n", *alunos+1);
            printf("Nota 1 - ");
            scanf("%f", &primeira_nota);

            printf("Nota 2 - ");
            scanf("%f", &segunda_nota);
        }

        if(primeira_nota == -1 || segunda_nota == -1)
            printf("Fim de leitura.\n");

        if(*alunos >= TF)
            printf("Fim de leitura, limite de alunos atingido...\n");
    }
}

void calcular_somatoria(float nota1[], float nota2[], int soma[], int alunos)
{
    int i;

    for(i=0; i<alunos; i++)
        soma[i] = nota1[i] + nota2[i];
}

void calcular_media(float nota1[], float nota2[], float media[],int soma[], int alunos)
{
    int i;

    for(i=0; i<alunos; i++)
        media[i] = soma[i]/2.0;
}

void apresentar_media(float media[], int alunos)
{
    int i;

    printf("\nApresentando as medias finais de cada aluno...\n");
    for(i=0; i<alunos; i++)
        printf("Aluno %d: %.2f.\n", i+1, media[i]);
}

void calcular_media_turma(float media[], int alunos, float *media_total)
{
    int i;

    for(i=0; i<alunos; i++)
        *media_total += media[i];

    *media_total /= alunos;
}

void alunos_reprovados(float media[], float *percentual, int *reprovados, int alunos)
{
    int i;

    for(i=0; i<alunos; i++)
        if(media[i] < 6.0)
            (*reprovados)++;

    *percentual = (float) *reprovados/alunos *100;
}

void main()
{
    float nota1[TF],
          nota2[TF],
          media[TF],
          percentual,
          media_total=0;

    int alunos=0,
        soma[TF],
        reprovados=0;

    ler_nota_alunos(nota1, nota2, &alunos);

    calcular_somatoria(nota1, nota2, soma, alunos);
    calcular_media(nota1, nota2, media, soma, alunos);
    apresentar_media(media, alunos);

    calcular_media_turma(media, alunos, &media_total);
    printf("\nA media da turma: %.2f.\n", media_total);

    alunos_reprovados(media, &percentual, &reprovados, alunos);
    printf("\nTotal de %d alunos reprovados, representando %.2f%%.\n", reprovados, percentual);
}
