#include <stdio.h>

void main()
{
    FILE *origem, *destino;
    char caracter;

    origem = fopen("texto.txt", "r");
    destino = fopen("criptografar.txt", "w");

    if(origem != NULL && destino != NULL)
    {
        caracter = fgetc(origem);

        while(caracter != EOF)
        {
            caracter++;
            fputc(caracter, destino);
            caracter = fgetc(origem);
        }
        fclose(origem);
        fclose(destino);

        remove("texto.txt");
        rename("criptografar.txt", "texto.txt");
    }
    else
        printf("\nArquivo nao encontrado...\n");
}
