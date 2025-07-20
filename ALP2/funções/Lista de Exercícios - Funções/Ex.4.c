//Kauan Silva Camargo - PE3028488
//Rafael Luiz de Oliveira - PE3028534

#include<stdio.h>
#define TF 100

void ler_dados(float altura[], char sexo[], int *pessoas, int *homens, int *mulheres)
{
    float estatura;

    char genero;

    printf("Insira a altura e sexo da populacao (M/m ou F/f) - 0 para finalizar.\n");
    do
    {
        scanf("%f %c", &estatura, &genero);
        fflush(stdin);

        if(estatura <= 0 || (genero != 'M' && genero != 'm' && genero != 'F' && genero != 'f'))
            printf("Insira pelo menos uma estutura e genero validos...\n");
    }
    while(estatura <= 0 || (genero != 'M' && genero != 'm' && genero != 'F' && genero != 'f'));
    while(estatura > 0 && (genero == 'M' || genero == 'm' || genero == 'F' || genero == 'f') && *pessoas < TF)
    {
        if(estatura > 0 && genero == 'M' || genero == 'm' || genero == 'F' || genero == 'f')
        {
            altura[*pessoas] = estatura;
            sexo[*pessoas] = genero;
            (*pessoas)++;

            if(genero == 'M' || genero == 'm')
                (*homens)++;

            else
                (*mulheres)++;
        }
        else
            printf("Insira valores validos (estatura maior que 0 e genero M/m ou F/f).\n\n");

        if(*pessoas < TF)
        {
            scanf("%f %c", &estatura, &genero);
            fflush(stdin);
        }

        if(estatura == 0)
            printf("\nFim de leitura.\n\n");

        if(*pessoas >= TF)
            printf("\nLimite de pessoas atingido, fim de leitura...\n\n");
    }

}

void identificador_altura(float altura[], int pessoas, float *maior, float *menor)
{
    int i;

    for(i=0; i<pessoas; i++)
    {
        if(altura[i] < *menor)
            *menor = altura[i];
        if(altura[i] > *maior)
            *maior = altura[i];
    }
}

void calculo_media_altura(float altura[], char sexo[], int mulheres, float *media_mulheres, int pessoas, float *media_populacao)
{
    int i;

        for(i=0; i<pessoas; i++)
            if(sexo[i] == 'F' || sexo[i] == 'f')
                *media_mulheres += altura[i];

        for(i=0; i<pessoas; i++)
            *media_populacao += altura[i];

    *media_mulheres /= mulheres;
    *media_populacao /= pessoas;
}

void percentual_homens(int homens, int pessoas, float *percent)
{
    *percent = (float) homens/pessoas * 100;
}

void main()
{
    int homens=0,
        mulheres=0,
        pessoas=0;

    char sexo[TF];

    float populacao_media=0,
          mulheres_media=0,
          altura[TF],
          percent,
          maior,
          menor;

    ler_dados(altura, sexo, &pessoas, &homens, &mulheres);

    maior = altura[0];
    menor = altura[0];
    identificador_altura(altura, pessoas, &maior, &menor);
    printf("Maior altura: %.2f.\n", maior);
    printf("Menor altura: %.2f.\n", menor);
    if(maior == menor)
        printf("Possuem a mesma altura...\n");

    calculo_media_altura(altura, sexo, mulheres, &mulheres_media, pessoas, &populacao_media);
    if(mulheres > 0)
        printf("\nMedia de altura das mulheres: %.2f.\n", mulheres_media);
    else
        printf("\nMedia de altura das mulheres: sem registro.\n");
    printf("Media de altura da populacao: %.2f.\n", populacao_media);

    percentual_homens(homens, pessoas, &percent);
    printf("O percentual de homens na populacao: %.2f%%.\n", percent);
}

