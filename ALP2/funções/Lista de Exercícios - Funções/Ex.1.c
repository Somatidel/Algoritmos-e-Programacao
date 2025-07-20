//Kauan Silva Camargo - PE3028488
//Rafael Luiz de Oliveira - PE3028534

#include<stdio.h>

void menu(int *opcao)
{
    printf("=========MENU==========\n");
    printf("1. Conversao de Celsius para Fahrenheit;\n");
    printf("2. Conversao de Fahrenheit para Celsius.\n");
    printf("0. Sair do programa.\n\n");
    printf("Opcao: ");
    scanf("%d", opcao);
}

void conversao_fahrenheit(float celsius, float *fahrenheit)
{
    printf("\nQual o valor da temperatura em Celsius(C)?\n");
    scanf("%f", &celsius);

    *fahrenheit = (9*celsius + 160)/5;
}

void conversao_celsius(float fahrenheit, float *celsius)
{
    printf("\nQual o valor da temperatura em Fahrenheit(F)?\n");
    scanf("%f", &fahrenheit);

    *celsius = (fahrenheit - 32) * 5.0/9;
}

void main()
{
    float celsius,
          fahrenheit;

    int opcao;

        do
        {
            menu(&opcao);

            switch(opcao)
            {
            case 0:
                printf("\nFim de programa...\n");
                break;

            case 1:
                conversao_fahrenheit(celsius, &fahrenheit);

                printf("\nEquivale a %.2f em Fahrenheit (F).\n\n", fahrenheit);
                break;

            case 2:
                conversao_celsius(fahrenheit, &celsius);

                printf("\nEquivale a %.2f em Celsius (C).\n\n", celsius);
                break;

            default:
                printf("\nEscolha uma opcao valida...\n\n");
            }
        }while(opcao != 0);

}
