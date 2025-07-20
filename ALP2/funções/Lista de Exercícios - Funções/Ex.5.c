//Kauan Silva Camargo - PE3028488
//Rafael Luiz de Oliveira - PE3028534

#include<stdio.h>
#define TF 50

void ler_votos(char votar[], int *alunos)
{
    char voto;

    printf("Leitura dos votos:\n");
    do
    {
        scanf("%c", &voto);
        fflush(stdin);

        if(voto == 'X' || voto == 'x')
            printf("\nInsira pelo menos um voto...\n\n");
    }
    while(voto == 'X' || voto == 'x');
    while(voto != 'X' && voto != 'x' && *alunos < TF)
    {
        votar[*alunos] = voto;
        (*alunos)++;

        if(*alunos < TF)
        {
            scanf("%c", &voto);
            fflush(stdin);
        }

        if(voto == 'X' || voto == 'x')
            printf("\nFim da votacao.\n");

        if(*alunos >= TF)
            printf("\nLimite de votos atingido.\n");
    }
}

void quantidade_votos(char votar[], int alunos, int *marcos, int *ana, int *brancos, int *nulos)
{
    int i;

    for(i=0; i<alunos; i++)
    {
        if(votar[i] == 'M' || votar[i] == 'm')
            (*marcos)++;
        else if(votar[i] == 'A' || votar[i] == 'a')
            (*ana)++;
        else if(votar[i] == 'B' || votar[i] == 'b')
            (*brancos)++;
        else
            (*nulos)++;
    }
}

float calculo_validos(int alunos, int marcos, int ana)
{
    return (float)(marcos + ana)/alunos * 100;
}

void calculo_candidatos(int marcos, float *percent_marcos, int ana, float *percent_ana)
{
    *percent_marcos = (float) marcos/(marcos+ana) * 100;
    *percent_ana = (float) ana/(marcos+ana) * 100;
}

void main()
{
    char votar[TF];

    int brancos=0,
        marcos=0,
        alunos=0,
        nulos=0,
        ana=0;

    float percent_marcos,
          percent_ana,
          percent;

    ler_votos(votar, &alunos);

    quantidade_votos(votar, alunos, &marcos, &ana, &brancos, &nulos);

    printf("\nTotal de alunos que votaram: %d.\n\n", alunos);

    printf("Total de votos para Marcos da Silva: %d.\n", marcos);
    printf("Total de votos para Ana Claudia: %d.\n", ana);
    printf("Quantidade de votos brancos: %d.\n", brancos);
    printf("Quantidade de votos nulos: %d.\n\n", nulos);

    percent = calculo_validos(alunos, marcos, ana);
    printf("Percentual de votos validos: %.2f%%.\n\n", percent);

    calculo_candidatos(marcos, &percent_marcos, ana, &percent_ana);
    printf("Percentual de votos para Marcos: %.2f%%.\n", percent_marcos);
    printf("Percentual de votos para Ana: %.2f%%.\n", percent_ana);

    if(percent < 50.0)
        printf("\nA eleicao nao foi valida...\n");
    else
    {
        printf("\nA eleicao foi valida, ");
        if(marcos > ana)
            printf("Marcos eh o novo representante.\n");
        else if(ana > marcos)
            printf("Ana eh a nova representante.\n");
        else
            printf("mas houve um empate!\n");
    }
}
