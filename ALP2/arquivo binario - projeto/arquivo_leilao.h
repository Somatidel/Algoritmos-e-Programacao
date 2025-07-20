void incluir_produto(tp_produto a)
{
    FILE *arquivo;

    arquivo = fopen("leilao.dat", "ab");

    if(arquivo == NULL)
        arquivo = fopen("leilao.dat", "wb");
    if(arquivo == NULL)
        printf("\nNao foi possivel abrir o arquivo...\n");
    else
    {
        a.estado = 1;
        fwrite(&a, sizeof(tp_produto), 1, arquivo);
        fclose(arquivo);
    }
}

int encontrar_pos_produto(int codigo)
{
    FILE *arquivo;

    tp_produto a;

    int i=0,
        posicao = -1;

    arquivo = fopen("leilao.dat", "rb");
    if(arquivo == NULL)
        printf("\nNao foi possivel abrir o arquivo...\n");
    else
    {
        fread(&a, sizeof(tp_produto), 1, arquivo);
        while(!feof(arquivo) && posicao == -1)
        {
            if(codigo == a.codigo)
                posicao = i;

            i++;
            fread(&a, sizeof(tp_produto), 1, arquivo);
        }
        fclose(arquivo);
    }
    return posicao;
}

void substituir_produto(tp_produto a, int posicao)
{
    FILE *arquivo;

    arquivo = fopen("leilao.dat", "rb+");
    if(arquivo == NULL)
        printf("\nNao foi possivel abrir o arquivo...\n");
    else
    {
        fseek(arquivo, posicao*sizeof(tp_produto), SEEK_SET);
        fwrite(&a, sizeof(tp_produto), 1, arquivo);
    }
    fclose(arquivo);
}

tp_produto retornar_produto(int posicao)
{
    FILE *arquivo;

    tp_produto a;

    arquivo = fopen("leilao.dat", "rb");
    if(arquivo == NULL)
        printf("\nNao foi possivel abrir o arquivo...\n");
    else
    {
        fseek(arquivo, posicao*sizeof(tp_produto), SEEK_SET);
        fread(&a, sizeof(tp_produto), 1, arquivo);
    }
    fclose(arquivo);

    return a;
}

int total_leiloes_abertos()
{
    FILE *arquivo;

    tp_produto a;

    int total_leiloes = 0;

    arquivo = fopen("leilao.dat", "rb");
    if (arquivo == NULL)
        printf("\nNao foi possivel abrir o arquivo...\n");
    else
    {
        fread(&a, sizeof(tp_produto), 1, arquivo);
        while(!feof(arquivo))
        {
            if(a.estado == 1 && a.situacao == 'A')
                total_leiloes++;
            fread(&a, sizeof(tp_produto), 1, arquivo);
        }
        fclose(arquivo);
    }

    return total_leiloes;
}

int total_lances()
{
    FILE *arquivo;

    tp_produto a;

    int lances_totais = 0;

    arquivo = fopen("leilao.dat", "rb");
    if (arquivo == NULL)
        printf("\nNao foi possivel abrir o arquivo...\n");
    else
    {
        fread(&a, sizeof(tp_produto), 1, arquivo);
        while(!feof(arquivo))
        {
            if (a.estado && a.situacao == 'A')
                lances_totais += a.lances;
            fread(&a, sizeof(tp_produto), 1, arquivo);
        }
        fclose(arquivo);
    }

    return lances_totais;
}

float total_arrecadado()
{
    FILE *arquivo;

    tp_produto a;

    float valor_total = 0;

    arquivo = fopen("leilao.dat", "rb");
    if (arquivo == NULL)
        printf("\nNao foi possivel abrir o arquivo...\n");
    else
    {
        fread(&a, sizeof(tp_produto), 1, arquivo);
        while(!feof(arquivo))
        {
            if (a.estado && a.situacao == 'F' && a.lances > 0)
                valor_total += a.valor;
            fread(&a, sizeof(tp_produto), 1, arquivo);
        }
        fclose(arquivo);
    }

    return valor_total;
}

int total_leiloes_finalizados()
{
    FILE *arquivo;

    tp_produto a;

    int total_leiloes = 0;

    arquivo = fopen("leilao.dat", "rb");
    if (arquivo == NULL)
        printf("\nNao foi possivel abrir o arquivo...\n");
    else
    {
        fread(&a, sizeof(tp_produto), 1, arquivo);
        while(!feof(arquivo))
        {
            if(a.estado == 1 && a.situacao == 'F')
                total_leiloes++;
            fread(&a, sizeof(tp_produto), 1, arquivo);
        }
        fclose(arquivo);
    }

    return total_leiloes;
}
