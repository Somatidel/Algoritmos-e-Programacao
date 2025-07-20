//Rafael Luiz de Oliveira - PE3028534
//Eduardo Viana - PE

#include <stdio.h>
#include <string.h>

void ler_nomes(char nomes[3][50])
{
    int i;

    printf("Insira o nome dos alunos:\n\n");
    for(i=0; i<3; i++)
        fgets(nomes[i], 50, stdin);
}

int ordem_alfabetica(char nomes[3][50])
{
    char buff[50];

    int i, j;

    for(i=0; i<2; i++)
        for(j=0; j<2-i; j++)
            if(strcmpi(nomes[j], nomes[j+1]) > 0)
            {
                strcpy(buff, nomes[j]);
                strcpy(nomes[j], nomes[j+1]);
                strcpy(nomes[j+1], buff);
            }
}

void apresentar_nomes(char nomes[3][50])
{
    int i;

    printf("\nApresantando nomes em ordem alfabetica:\n\n");
    for(i=0; i<3; i++)
        printf("- %s\n", nomes[i]);
}

void main()
{
    char nomes[3][50];

    ler_nomes(nomes);

    ordem_alfabetica(nomes);

    apresentar_nomes(nomes);
}
