//Kauan Silva Camargo - PE3028488
//Rafael Luiz de Oliveira - PE3028534

#include<stdio.h>
#define TF 50

void menu(int *op)
{
    printf("1. Ler/reler vetor de caracteres;\n");
    printf("2. Excluir um caracter de uma determinada posicao;\n");
    printf("3. Incluir um caracter em uma determinada posicao;\n");
    printf("4. Copiar uma parte dos caracteres para dentro de outro vetor;\n");
    printf("5. Copiar a ultima palavra para outro vetor;\n");
    printf("6. Copiar a primeira palavra para outro vetor;\n");
    printf("7. Retirar os espaços em branco repetidos;\n");
    printf("8. Contar a quantidade de palavras;\n");
    printf("9. Contar a quantidade de vogais;\n");
    printf("0. Sair do programa.\n\n");
    printf("Opcao: ");
    scanf("%d", op);
    fflush(stdin);
}

void ler_vetor_char(char vetor[], int *tl)
{
    char carac;

    (*tl) = 0;

    printf("Digite um 'texto' (ENTER para finalizar): ");
    do
    {
        scanf("%c", &carac);
        if(carac != 10)
        {
            vetor[*tl] = carac;
            (*tl)++;
        }
    }
    while(carac != 10);

    printf("\nFim de leitura.\n");
}

void excluir_Pos(char vetor[], int *tl)
{
    int i,
        pos;

    do
    {
        printf("\nEm qual posicao devera ser excluido o caracter?\n");
        scanf("%d", &pos);

        if(pos > *tl || pos < 0)
            printf("\nInsira uma posicao valida...\n");
    }
    while(pos > *tl || pos < 0);

    for(i=pos; i<*tl; i++)
        vetor[i] = vetor[i+1];

    (*tl)--;
    printf("\nExcluido...\n");
}

void incluir_Pos(char vetor[], int *tl)
{
    int i,
        pos;

    char carac = ' ';

    do
    {
        printf("\nEm qual posicao devera ser incluido o caracter?\n");
        scanf("%d", &pos);

        if(pos > *tl || pos < 0)
            printf("\nInsira uma posicao valida...\n");
    }
    while(pos > *tl || pos < 0);

    fflush(stdin);
    printf("\nQual caracter incluir? (ENTER para confirmar)\n");
    scanf("%c", &carac);
    fflush(stdin);

    for(i=(*tl); i>pos; i--)
        vetor[i] = vetor[i-1];

    vetor[pos] = carac;

    (*tl)++;
    printf("\nIncluido...\n");
}

void copiar_carac(char vetor[], int tl, char copia[], int *tl_copia)
{
    int i,
        min,
        max;

    *tl_copia = 0;

    do
    {
        printf("\nInforme a posicao inicial e final: ");
        scanf("%d %d", &min, &max);

        if(min > max || min < 0 || max > tl)
            printf("\nInsira posicoes validas...\n");
    }
    while(min > max || min < 0 || max > tl);

    for(i=0; i<max-min+1 && *tl_copia <= TF; i++)
    {
        copia[*tl_copia] = vetor[min + i];
        (*tl_copia)++;
    }

    if(*tl_copia >= TF)
        printf("\nLimite deste vetor atingido...\n");
}

void copiar_ultima_palavra(char vetor[], int tl, char copia[], int *tl_copia)
{
    int i,
        j,
        fim=0;

    *tl_copia = 0;

    for(i=tl; i>0 && *tl_copia <= TF && fim == 0; i--)
        if(vetor[i] == ' ')
        {
            for(j=i+1; j<tl; j++)
            {
                copia[*tl_copia] = vetor[j];
                (*tl_copia)++;
            }
            fim = 1;
        }

    if(*tl_copia >= TF)
        printf("\nLimite deste vetor atingido...\n");
}

void copiar_primeira_palavra(char vetor[], int tl, char copia[], int *tl_copia)
{
    int i;

    *tl_copia = 0;

    for(i=0; i<tl && vetor[i] != ' ' && *tl_copia <= TF; i++)
    {
        copia[*tl_copia] = vetor[i];
        (*tl_copia)++;
    }

    if(*tl_copia >= TF)
        printf("\nLimite deste vetor atingido...\n");
}

void retirar_espacos(char vetor[], int *tl)
{
    int i,
        j=0;

    for(i=0; i<*tl; i++)
        if(vetor[i] != ' ' || vetor[i+1] != ' ')
        {
            vetor[j] = vetor[i];
            j++;
        }
    *tl = j;
}

void contar_palavras(char vetor[], int tl, int *palavras)
{
    int i,
        verifica=0;

    *palavras = 0;

    for(i=0; i<tl; i++)
    {
        if(vetor[i] != ' ')
        {
            if(verifica == 0)
            {
                (*palavras)++;
                verifica=1;
            }
        }
        else
            verifica=0;
    }
}

void contar_vogais(char vetor[], int tl, int *vogais)
{
    int i;

    *vogais = 0;

    for(i=0; i<tl; i++)
        if(vetor[i] == 'a' || vetor[i] == 'A' || vetor[i] == 'e' || vetor[i] == 'E'|| vetor[i] == 'i' || vetor[i] == 'I' || vetor[i] == 'o' || vetor[i] == 'O'|| vetor[i] == 'u' || vetor[i] == 'U')
            (*vogais)++;
}

void apresentar_vetor(char vetor[], int tl)
{
    int i;

    for(i=0; i<tl; i++)
        printf("%c", vetor[i]);
    printf("\n");
}

void main()
{
    char origem[TF],
         primeira[TF],
         ultima[TF],
         copia[TF];

    int tl=0,
        tl_copia=0,
        tl_primeira=0,
        tl_ultima=0,
        palavras=0,
        vogais=0,
        op;

    do
    {
        menu(&op);

        switch(op)
        {
        case 0:
            printf("\nFim de programa.\n");
            break;

        case 1:
            ler_vetor_char(origem, &tl);
            printf("\n");
            break;

        case 2:
            excluir_Pos(origem, &tl);
            printf("Apos excluir: ");
            apresentar_vetor(origem, tl);
            printf("\n");

            break;

        case 3:
            incluir_Pos(origem, &tl);
            printf("Apos incluir: ");
            apresentar_vetor(origem, tl);
            printf("\n");

            break;

        case 4:
            copiar_carac(origem, tl, copia, &tl_copia);
            printf("Copiado: ");
            apresentar_vetor(copia, tl_copia);
            printf("\n");

            break;

        case 5:
            copiar_ultima_palavra(origem, tl, ultima, &tl_ultima);
            printf("Ultima palavra: ");
            apresentar_vetor(ultima, tl_ultima);
            printf("\n");

            break;

        case 6:
            copiar_primeira_palavra(origem, tl, primeira, &tl_primeira);
            printf("Primeira palavra: ");
            apresentar_vetor(primeira, tl_primeira);
            printf("\n");

            break;

        case 7:
            retirar_espacos(origem, &tl);
            printf("Sem espacos: ");
            apresentar_vetor(origem, tl);
            printf("\n");

            break;

        case 8:
            contar_palavras(origem, tl, &palavras);
            printf("\nQuantidade de palavras: %d.\n\n", palavras);
            break;

        case 9:
            contar_vogais(origem, tl, &vogais);
            printf("\nQuantidade de vogais: %d.\n\n", vogais);
            break;

        default:
            printf("\nSelecione uma opcao valida...\n\n");
        }
    }
    while(op != 0);
}
