#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    char nome_produto[50];
    int qte_vendida;
    float valor;
}tp_produto;

void remover_nova_linha(char string[])
{
    if(string[strlen(string)-1] == '\n')
        string[strlen(string)-1] = '\0';
}

int importar_venda(tp_produto produtos[], int *nota_fiscal, char nome_cliente[], char cpf[])
{
    FILE *arquivo;

    int tl=0,
        i;

    char auxiliar[30];

    arquivo = fopen("dados_venda.txt", "r");
    if(arquivo != NULL)
    {
        fgets(auxiliar, 10, arquivo); //nota fiscal
        *nota_fiscal = atoi(auxiliar);
        fscanf(arquivo, "%s", cpf); //cpf
        remover_nova_linha(cpf);

        fgetc(arquivo);
        fgets(nome_cliente, 50, arquivo); // nome do cliente
        remover_nova_linha(nome_cliente);

        fgets(auxiliar, 10, arquivo);
        tl = atoi(auxiliar);

        for(i=0; i<tl; i++)
        {
            fgets(produtos[i].nome_produto, 49, arquivo);
            remover_nova_linha(produtos[i].nome_produto);
            fscanf(arquivo, "%d %f\n", &produtos[i].qte_vendida, &produtos[i].valor);
        }
        fclose(arquivo);
    }
    else
        printf("Nao foi possivel abrir o arquivo...\n");

    return tl;
}

void apresentar_produto(tp_produto a)
{
    printf("%s\n", a.nome_produto);
    printf("%d %.2f\n", a.qte_vendida, a.valor);
}

void apresentar_nota_fiscal(tp_produto produtos[], int tl, int nota_fiscal, char nome_cliente[], char cpf[])
{
    int i;

    printf("%d\n", nota_fiscal);
    printf("%s %s\n", cpf, nome_cliente);
    printf("%d\n", tl);

    for(i=0; i<tl; i++)
        apresentar_produto(produtos[i]);
}

int calcular_total_produtos(tp_produto produtos[], int tl)
{
    int total_produtos=0,
        i;

    for(i=0; i<tl; i++)
        total_produtos += produtos[i].qte_vendida;

    return total_produtos;
}

float calcular_total_venda(tp_produto produtos[], int tl)
{
    int i;
    float total_venda=0;

    for(i=0; i<tl; i++)
        total_venda += produtos[i].valor*produtos[i].qte_vendida;

    return total_venda;
}

//total itens eh simplesmente o tl
void gerar_nota_fiscal(tp_produto produtos[], int nota_fiscal, char nome_cliente[], char cpf[],
                       int total_itens, int total_produtos, float total_venda)
{
    FILE *arquivo;

    int i;

    arquivo = fopen("notal_fiscal.txt", "w");
    if(arquivo != NULL)
    {
        fprintf(arquivo, "Nota fiscal de Venda - nr.: %d\n", nota_fiscal);
        fprintf(arquivo, "================================================================\n");
        fprintf(arquivo, "Cliente: %s\n", nome_cliente);
        fprintf(arquivo, "CPF: %s\n", cpf);
        fprintf(arquivo, "================================================================\n");
        fprintf(arquivo, "Produtos:\n");
        fprintf(arquivo, "Seq Nome                                   Qte    Preço    Total\n");
        fprintf(arquivo, "----------------------------------------------------------------\n");

        for(i=0; i<total_itens; i++)
            fprintf(arquivo, "%03d %-35s %5d %9.2f %8.2f\n", i+1, produtos[i].nome_produto,
                    produtos[i].qte_vendida, produtos[i].valor,
                    produtos[i].qte_vendida*produtos[i].valor);

        fprintf(arquivo, "================================================================\n");
        fprintf(arquivo, "Quantidade de itens vendidos ...: %d\n", total_itens);
        fprintf(arquivo, "Quantidade total de produtos ...: %d\n", total_produtos);
        fprintf(arquivo, "Valor total da venda............: R$%.2f\n", total_venda);
        fprintf(arquivo, "================================================================\n");

        fclose(arquivo);
    }
    else
        printf("Nao foi possivel gerar a nota fiscal...\n");
}

void main()
{
    tp_produto produtos[20];

    int nota_fiscal,
        tl,
        i;

    char nome_cliente[50],
         cpf[20];


    tl = importar_venda(produtos, &nota_fiscal, nome_cliente, cpf);

    gerar_nota_fiscal(produtos, nota_fiscal, nome_cliente, cpf,
                      tl, calcular_total_produtos(produtos, tl),
                      calcular_total_venda(produtos, tl));

    apresentar_nota_fiscal(produtos, tl, nota_fiscal, nome_cliente, cpf);
}
