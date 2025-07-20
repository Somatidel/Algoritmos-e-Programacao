#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct
{
    int codigo,
        qte_estoque;

    char nome[30],
         departamento[30];

    float preco;

} tp_produto;


int importar_estoque(tp_produto tabela[])
{
    char aux[30];

    int tl=0,
        i;

    FILE *arquivo;

    arquivo = fopen("produtos.txt", "r");

    if(arquivo != NULL)
    {
        fgets(aux, 10, arquivo);
        tl = atoi(aux);

        for(i=0; i<tl; i++)
        {
            fgets(aux, 10, arquivo);
            tabela[i].codigo = atoi(aux);
            fgets(tabela[i].nome, 30, arquivo);
            fgets(tabela[i].departamento, 30, arquivo);
            fgets(aux, 10, arquivo);
            tabela[i].preco = atof(aux);
            fgets(aux, 10, arquivo);
            tabela[i].qte_estoque = atoi(aux);
        }

        fclose(arquivo);
    }
    else
        printf("\nNao foi possivel abrir o arquivo.\n");

    return tl;
}

void apresentar_produto(tp_produto a)
{
    printf("Codigo.......: %d\n", a.codigo);
    printf("Nome.........: %s", a.nome);
    printf("Departamento.: %s", a.departamento);
    printf("Preco........: %.2f\n", a.preco);
    printf("Quantidade...: %d\n", a.qte_estoque);
}

void apresentar_todos_produtos(tp_produto tabela[], int tl)
{
    int i;

    for(i=0; i<tl; i++)
    {
        apresentar_produto(tabela[i]);
        printf("\n");
    }
}

int pesquisar_codigo(tp_produto tabela[], int tl)
{
    int codigo,
        pos=-1,
        i;

    printf("Insira um codigo para pesquisar: ");
    scanf("%d", &codigo);
    fflush(stdin);

    for(i=0; i<tl && pos == -1; i++)
        if(codigo == tabela[i].codigo)
            pos=i;

    return pos;
}

void apresentar_codigo(tp_produto tabela[], int pos)
{
    if(pos == -1)
        printf("\nCodigo nao existe.\n");
    else
        apresentar_produto(tabela[pos]);
}

int calcular_qte_produtos(tp_produto tabela[], int tl)
{
    int soma=0,
        i;

    for(i=0; i<tl; i++)
        soma += tabela[i].qte_estoque;

    return soma;
}

void apresentar_qte_produtos_estoque(int soma)
{
    printf("\n%d produtos em estoque.\n", soma);
}

float calcular_valor_estoque(tp_produto tabela[], int tl)
{
    float valor=0;

    int i;

    for(i=0; i<tl; i++)
        valor += tabela[i].qte_estoque * tabela[i].preco;

    return valor;
}

void apresentar_valor_total(float valor)
{
    printf("\n%.2f eh o valor total em estoque.\n\n", valor);
}

void pesquisar_departamento(tp_produto tabela[], int tl, int pos[])
{
    char texto[30];

    int j=0,
        i;

    printf("Procurar por qual departamento?\n");
    fgets(texto, 30, stdin);
    printf("\n");

    for(i=0; i<tl; i++)
        if(strcmpi(texto, tabela[i].departamento) == 0)
        {
            pos[j]=i;
            j++;
        }
    pos[j] = -1;
}

void apresentar_departamento(tp_produto tabela[], int tl, int pos[])
{
    int i;

    for(i=0; i<tl && pos[i] != -1; i++)
    {
        apresentar_produto(tabela[pos[i]]);
        printf("\n");
    }
    if(pos[0] == -1)
        printf("Departamento nao existe.\n");
}

void main()
{
    int tl,
        pos[10];

    tp_produto tabela[5];

    tl = importar_estoque(tabela);

    apresentar_todos_produtos(tabela, tl);

    apresentar_codigo(tabela, pesquisar_codigo(tabela, tl));

    apresentar_qte_produtos_estoque(calcular_qte_produtos(tabela, tl));

    apresentar_valor_total(calcular_valor_estoque(tabela, tl));

    pesquisar_departamento(tabela, tl, pos);
    apresentar_departamento(tabela, tl, pos);
}
