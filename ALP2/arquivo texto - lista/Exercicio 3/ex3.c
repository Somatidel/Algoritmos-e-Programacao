#include<stdio.h>

int identificar_formatacao(char caracter)
{
    if(caracter == '#')
        return 1;
    if(caracter == '.')
        return 2;
    return 0;
}

void pegar_elemento(char texto[])
{
    char caracter;

    int i=0;

    caracter = texto[0];
    while(caracter != '{' && caracter != ' ' && caracter != '}')
    {
        texto[i] = caracter;
        i++;
        caracter = texto[i];
    }
    texto[i] = '\0';
}

void apresentar_formatacao(char texto[], int retorno)
{
    if(retorno == 0)
        printf("%s eh um elemento HTML\n", texto);
    if(retorno == 1)
        printf("%s eh um identificador(#)\n", texto);
    if(retorno == 2)
        printf("%s eh uma classe(.)\n", texto);
}

void ler_arquivo()
{

    char string[100],
         caracter;

    FILE *arquivo;

    arquivo = fopen("arquivo-css.txt", "r");

    if(arquivo != NULL)
    {

        while(fgets(string, 100, arquivo)!= NULL)
        {
            if(string[0] != '}' && string[0] != ' ')
            {
                caracter = string[0];
                pegar_elemento(string);
                apresentar_formatacao(string, identificar_formatacao(caracter));
            }
        }
        fclose(arquivo);
    }
    else
    {
        printf("nao e possivel abrir o arquivo");
    }
}

void main()
{
    ler_arquivo();
}
