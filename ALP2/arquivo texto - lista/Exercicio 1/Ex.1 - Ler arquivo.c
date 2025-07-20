#include <stdio.h>

/**
1 - Faça um programa em linguagem C capaz de ler e analisar um arquivo texto, apresentando:
    Quantidade de linhas;
    Quantidade de espaços em branco;
    Quantidade de letras e números.
    Quantidade total de caracteres.
**/

void main()
{
    FILE *arquivo;

    char texto[100],
         caracter;

    int total_caracter=0,
        cont_espaco=0,
        cont_linha=1,
        cont_letra=0,
        cont_num=0;

    arquivo = fopen("texto.txt", "r");

    if(arquivo != NULL)
    {
        caracter = fgetc(arquivo);

        while(caracter != EOF)
        {
            if(caracter == '\n')
                cont_linha++;
            if(caracter == ' ')
                cont_espaco++;
            if(caracter >= 'a' && caracter <= 'z' ||
               caracter >= 'A' && caracter <= 'Z')
                cont_letra++;
            if(caracter >= '0' && caracter <= '9')
                cont_num++;
            total_caracter++;

            caracter = fgetc(arquivo);
        }

        printf("Quantidade de linhas: %d\n", cont_linha);
        printf("Quantidade de espacos em branco: %d\n", cont_espaco);
        printf("%d letras e %d numeros no arquivo.\n", cont_letra, cont_num);
        printf("Quantidade total de caracteres: %d\n", total_caracter);
    }
    else
        printf("\nArquivo nao encontrado...\n");
}
