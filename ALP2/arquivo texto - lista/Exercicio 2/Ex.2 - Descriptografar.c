#include <stdio.h>

void main()
{
    FILE *origem, *destino;
    char caracter;

    origem = fopen("texto.txt", "r");
    destino = fopen("descriptografar.txt", "w");

    if(origem != NULL && destino != NULL)
    {
        caracter = fgetc(origem);

        while(caracter != EOF)
        {
            caracter--;
            fputc(caracter, destino);
            caracter = fgetc(origem);
        }
        fclose(origem);
        fclose(destino);

        remove("texto.txt");
        rename("descriptografar.txt", "texto.txt");
    }
    else
        printf("\nArquivo nao encontrado...\n");
}
