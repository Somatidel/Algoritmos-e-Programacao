//Kauan Silva Camargo e Rafael Luiz de Oliveira

#include <stdio.h>
#include "estrutura.h"
#include "arquivo_leilao.h"
#include "interface_leilao.h"

int menu()
{
    int opcao;
    do
    {
        printf("-><-><-><-MENU-><-><-><-\n");
        printf("1. Incluir novo leilao;\n");
        printf("2. Alterar produto;\n");
        printf("3. Exclusao logica;\n");
        printf("4. Recuperar produto;\n");
        printf("5. Pesquisar produto;\n");
        printf("6. Exclusao fisica;\n");
        printf("7. Relatorio leilao;\n");
        printf("8. Novo lance;\n");
        printf("9. Finalizar leilao;\n");
        printf("10. Lista de leiloes abertos;\n");
        printf("11. Lista de leiloes finalizados;\n");
        printf("0. Sair.\n");
        printf("Selecionar: ");
        scanf("%d", &opcao);
        printf("\n");
        if(opcao < 0 || opcao > 11)
            printf("Opcao invalida. Digite novamente...\n\n");

    }
    while(opcao < 0 || opcao > 11);

    return opcao;
}

void main()
{
    int opcao;

    opcao = menu();
    while(opcao != 0)
    {
        switch(opcao)
        {
        case 1:
            novo_leilao();
            break;

        case 2:
            alterar_produto();
            break;

        case 3:
            exclusao_logica();
            break;

        case 4:
            recuperar_produto();
            break;

        case 5:
            pesquisar_produto();
            break;

        case 6:
            exclusao_fisica();
            break;

        case 7:
            lista_leilao();
            break;

        case 8:
            incluir_novo_lance();
            break;

        case 9:
            finalizar_leilao();
            break;

        case 10:
            apresentar_leiloes_abertos();
            printf("\nQuantidade de leiloes ativos: %d.\n", total_leiloes_abertos());
            printf("Quantidade total de lances: %d.\n\n", total_lances());
            break;

        case 11:
            apresentar_leiloes_finalizados();
            printf("\nQuantidade de leiloes finalizados: %d.\n", total_leiloes_finalizados());
            printf("Quantidade arrecadada: %.2f.\n\n", total_arrecadado());
            break;
        }
    opcao = menu();
    }
    printf("Fim do Programa.\n");
}
