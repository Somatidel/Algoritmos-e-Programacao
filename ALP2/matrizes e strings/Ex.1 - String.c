//Rafael Luiz de Oliveira PE3028534
//Eduardo Viana PE3029387

#include<stdio.h>
#define TF 50

void menu(int *opcao)
{
    printf("1. Ler uma string;\n");
    printf("2. Excluir um caracter de uma determinada posicao de uma string;\n");
    printf("3. Incluir um caracter em uma determinada posicao de uma string;\n");
    printf("4. Copiar uma parte de uma string para dentro de outra;\n");
    printf("5. Copiar a ultima palavra de uma string para outra string;\n");
    printf("6. Copiar a primeira palavra de uma string para outra;\n");
    printf("7. Retirar os espacos em branco repetidos de uma string;\n");
    printf("8. Retirar os espacos em branco do final de uma string; \n");
    printf("9. Retirar os espacos em branco do inicio de uma string\n");
    printf("10. Copiar o conteudo de uma string para outra;\n");
    printf("11. Apagar o conteudo de uma string.\n");
    printf("0. Sair do programa.\n\n");
    printf("Operacao: ");
    scanf("%d", opcao);
    fflush(stdin);
}

void ler_string(char string[])
{
    int i=0;

    char carac;

    do
    {
        scanf("%c", &carac);
        if(carac == 10)
            printf("Insira algum texto...\n\n");
    }
    while(carac == 10);
    while(carac != 10 && i < TF)
    {
        if(i<TF-1)
        {
            string[i] = carac;
            i++;
        }

        scanf("%c", &carac);

        if(carac == 10)
            printf("\nFim de leitura.\n");
    }
    string[i] = '\0';
}

void excluir_pos(char string[])
{
    int i=0,
        pos,
        j;

    while(string[i] != '\0')
        i++;

    printf("\nQual posicao deseja excluir um caracter?\n");
    do
    {
        fflush(stdin);
        scanf("%d", &pos);

        if(pos < 0 || pos > i)
            printf("Coloque uma posicao valida...\n\n");
    }
    while(pos < 0 || pos > i);


    for(j=pos; j<i; j++)
        string[j] = string[j+1];
    string[j] = '\0';

}

void incluir_pos(char string[])
{
    int j,
        i=0,
        pos,
        carac;

    while(string[i] != '\0')
        i++;

    printf("\nQual posicao deseja incluir um caracter?\n");
    do
    {
        fflush(stdin);
        scanf("%d", &pos);

        if(pos < 0 || pos > i)
            printf("Coloque uma posicao valida...\n\n");
    }
    while(pos < 0 || pos > i);


    printf("\nInsira um caracter: ");
    fflush(stdin);
    scanf("%c", &carac);

    for(j=i; j>pos; j--)
        string[j] = string[j-1];
    string[i+1] = '\0';
    string[pos] = carac;
}

void copiar_pos_string(char string[], char copia[])
{
    int i,
        pos_in,
        pos_fin;

    //fazer verificacao depois
    printf("\nInforme a posicao inicial e a final: ");
    scanf("%d %d", &pos_in, &pos_fin);

    for(i=pos_in; i<=pos_fin; i++)
        copia[i] = string[i];
    copia[i+1] = '\0';
}

void copiar_ultima_palavra(char string[], char ultima_palavra[])
{
    int espaco=0,
        i=0,
        pos;

    while(string[i] != '\0')
    {
        if(string[i] == ' ')
            pos = i+1;
        i++;
    }

    i=pos;
    while(string[i] != '\0')
    {
        ultima_palavra[i-pos] = string[i];
        i++;
    }
}

void copia_primeira_palavra(char string[], char primeira_palavra[])
{
    int i=0;

    while(string[i] != '\0' && string[i] != ' ')
    {
        primeira_palavra[i] = string[i];
        i++;
    }
    primeira_palavra[i] = '\0';
}

void retirar_espacos(char string[])
{
    int i=0,
        j=0;

    while(string[i] != '\0')
    {
        if(string[i] != ' ' || string[i+1] != ' ')
        {
            string[j] = string[i];
            j++;
        }
        i++;
    }
    string[j] = '\0';
}

void espacos_final(char string[])
{
    int i=0;

    while(string[i] != '\0')
        i++;

    while(string[i-1] == ' ')
    {
        string[i-1] = string[i-2];
        i--;
    }
    string[i]='\0';
}

void espacos_inicio(char string[])
{
    int espaco=0,
        i,
        j=0;

    while(string[j]!='\0')
        j++;

    while(string[espaco] == ' ')
        espaco++;

    for(i=espaco; i<j; i++)
        string[i-espaco] = string[i];
    string[i-espaco] = '\0';
}

void copiar_string(char string[], char copia[])
{
    int i=0;

    while(string[i] != '\0')
    {
        copia[i] = string[i];
        i++;
    }
    copia[i] = '\0';
}

void apagar_string(char string[])
{
    int i=0,
        j;

    while(string[i] != '\0')
        i++;

    for(j=0; j<=i; j++)
        string[i] = string[i+1];
    string[0] = '\0';
}

void apresentar_string(char string[])
{
    int i=0;

    printf("\n\nApresentando string: ");
    while(string[i] != '\0')
    {
        printf("%c", string[i]);
        i++;
    }
}

void main()
{
    char copia_pos[TF],
         primeira[TF],
         string[TF],
         ultima[TF],
         copia[TF];

    int op;

    do
    {
        menu(&op);

        switch(op)
        {
        case 0:
            printf("\nFim de programa...\n");
            break;

        case 1:
            ler_string(string);
            apresentar_string(string);
            printf("\n\n");
            break;

        case 2:
            excluir_pos(string);
            apresentar_string(string);
            printf("\n\n");
            break;

        case 3:
            incluir_pos(string);
            apresentar_string(string);
            printf("\n\n");
            break;

        case 4:
            copiar_pos_string(string, copia_pos);
            apresentar_string(string);
            printf("\n\n");
            break;

        case 5:
            copiar_ultima_palavra(string, ultima);
            apresentar_string(ultima);
            printf("\n\n");
            break;

        case 6:
            copia_primeira_palavra(string, primeira);
            apresentar_string(primeira);
            printf("\n\n");
            break;

        case 7:
            retirar_espacos(string);
            apresentar_string(string);
            printf("\n\n");
            break;

        case 8:
            espacos_final(string);
            apresentar_string(string);
            printf("\n\n");
            break;

        case 9:
            espacos_inicio(string);
            apresentar_string(string);
            printf("\n\n");
            break;

        case 10:
            copiar_string(string, copia);
            apresentar_string(copia);
            printf("\n\n");
            break;

        case 11:
            apagar_string(string);
            apresentar_string(string);
            printf("\n\n");

            break;

        default:
            printf("\nInsira uma operacao valida...\n\n");
        }
    }
    while(op != 0);
}
