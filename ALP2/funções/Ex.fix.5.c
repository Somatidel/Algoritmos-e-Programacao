#include<stdio.h>
#define TF 30

void ler_email(char email[], int *tl)
{
    char input;

    printf("Insira o email: ");
    do
    {
        scanf("%c", &input);
        if (input != 10 && *tl < TF)
        {
            email[*tl] = input;
            (*tl)++;
        }
    }
    while(input != 10 && *tl < TF);
}

void separar_nomes(char email[], int tl, char usuario[], int *tl_usuario, char servidor[], int *tl_servidor)
{
    int i,
        arroba=0;

    for(i=0; i<tl; i++)
    {
        if(email[i] == '@')
            arroba = 1;

        if(arroba == 0)
        {
            usuario[*tl_usuario] = email[i];
            (*tl_usuario)++;
        }
        else
        {
            servidor[*tl_servidor] = email[i+1];
            (*tl_servidor)++;
        }
    }
}

void verificador(char email[], int tl)
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

void apresentar_vetor(char vetor[], int tl)
{
    int i;

    for(i=0; i<tl; i++)
        printf("%c", vetor[i]);
}

void main()
{
    char email[TF],
         usuario[TF],
         servidor[TF];

    int tl=0,
        tl_usuario=0,
        tl_servidor=0;

    //ler o bendito do email
    ler_email(email, &tl);

    //separar os nomes do usuario e servidor
    separar_nomes(email, tl, usuario, &tl_usuario, servidor, &tl_servidor);

    //apresentar os vetoresssssssssssssssssssss :snake:
    printf("\nApresentando os vetores...\n");
    printf("\nO nome do usuario do e-mail: ");
    apresentar_vetor(usuario, tl_usuario);

    printf("\nO nome do servidor do e-mail: ");
    apresentar_vetor(servidor, tl_servidor);

    //verificando se o email eh valido...
    verificador(email, tl);
    verificador_br(email, tl);

}
