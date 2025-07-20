#include<stdio.h>
#define TF 50

int ler_email(char email[TF])
{
    char input;
    int tl=0;

    printf("Insira o email: ");
    do
    {
        scanf("%c", &input);
        if (input != 10)
        {
            email[tl] = input;
            tl++;
        }
    }
    while(input != 10);
    return tl;
}

int usuario_email(char email[TF], char usuario[TF], int  tl)
{
    int i;
    for(i=0; email[i] != '@'; i++)
        usuario[i] = email[i];

    return i;
}

int servidor_email(char email[TF], char servidor[TF], int tl)
{
    int pos,
        arroba=0,
        tl_servidor;

    for(int i=0; i<tl; i++)
    {
        if(email[i] == '@')
        {
            pos = i+1;
            arroba = 1;
        }
        if(arroba == 1)
        {
            tl_servidor = i - pos;
            servidor[tl_servidor] = email[i];
        }
    }

    return tl_servidor;
}

void verificador(char email[TF], int tl)
{
    int verifica=0,
        arroba=0,
        espaco=0,
        ponto=0;

    for(int i=0; i<tl; i++)
    {
        if(email[i] == '@')
            arroba = 1;

        if(arroba == 1 && email[i] == '.')
            ponto = 1;

        if(email[i] == ' ')
            espaco = 1;
    }

    if(arroba == 1 && ponto == 1 && espaco == 0)
        verifica = 1;

    if(verifica == 1)
        printf("\n\nO e-mail eh valido!");
    else
        printf("\n\nErro, o e-mail nao eh valido.");
}

void verificador_br(char email[TF], int tl)
{
    int brasil=0;
    if(email[tl-1] == 'r')
        if(email[tl-2] == 'b')
            if(email[tl-3] == '.')
                brasil=1;

    if(brasil == 1)
        printf("\nO e-mail eh brasileiro.\n");
    else
        printf("\nO e-mail nao eh brasileiro.\n");
}
void main()
{
    char email[TF],
         usuario[TF],
         servidor[TF];
    int tl = ler_email(email),
        pos = usuario_email(email, usuario, tl),
        tl_servidor = servidor_email(email, servidor, tl);

    printf("\nO nome do usuario do e-mail: ");
    for(int i=0; i<pos; i++)
        printf("%c", usuario[i]);

    printf("\nO nome do servidor do e-mail: ");
    for(int i=0; i<tl_servidor+1; i++)
        printf("%c", servidor[i]);

    verificador(email, tl);
    verificador_br(email, tl);

}
