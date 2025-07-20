void apresentar_cabecalho()
{
    printf("%-5s| %-30s| %10s| %6s| %-3s| %-30s| %-14s|\n", "NR", "Produto", "Valor",
           "Lances", "Sit", "Nome", "Telefone");
}

void apresentar_linha(tp_produto a)
{
    printf("%-5d| %-30s| %10.2f| %6d| %-3c| %-30s| %-14s|\n", a.codigo, a.nome_produto, a.valor,
           a.lances, a.situacao, a.nome, a.telefone);
}

int verificar_existencia()
{
    FILE *arquivo;

    tp_produto a;

    int verifica=0;

    arquivo = fopen("leilao.dat", "rb");
    if(arquivo == NULL)
        printf("\nNao foi possivel abrir o arquivo...\n");
    else
    {
        fread(&a, sizeof(tp_produto), 1, arquivo);
        while(!feof(arquivo))
        {
            if(a.estado)
                verifica = 1;
            fread(&a, sizeof(tp_produto), 1, arquivo);
        }
        fclose(arquivo);
    }

    return verifica;
}

int verificar_existencia_excluido()
{
    FILE *arquivo;

    tp_produto a;

    int verifica=0;

    arquivo = fopen("leilao.dat", "rb");
    if(arquivo == NULL)
        printf("\nNao foi possivel abrir o arquivo...\n");
    else
    {
        fread(&a, sizeof(tp_produto), 1, arquivo);
        while(!feof(arquivo))
        {
            if(!a.estado)
                verifica = 1;
            fread(&a, sizeof(tp_produto), 1, arquivo);
        }
        fclose(arquivo);
    }

    return verifica;
}

void lista_leilao()
{
    FILE* arquivo;

    tp_produto a;

    int verifica;

    arquivo = fopen("leilao.dat", "rb");
    if(arquivo == NULL)
        printf("\nNao foi possivel abrir o arquivo...\n");
    else
    {
        verifica = verificar_existencia();

        fread(&a, sizeof(tp_produto), 1, arquivo);
        if(verifica == 1)
            apresentar_cabecalho();
        else
            printf("Nao ha nenhum leilao para apresentar.\n");
        while(!feof(arquivo))
        {
            if(a.estado)
                apresentar_linha(a);
            fread(&a, sizeof(tp_produto), 1, arquivo);
        }
        printf("\n");
        fclose(arquivo);
    }
}

void lista_excluidos()
{
    FILE* arquivo;

    tp_produto a;

    int verifica;

    arquivo = fopen("leilao.dat", "rb");
    if(arquivo == NULL)
        printf("\nNao foi possivel abrir o arquivo...\n");
    else
    {
        verifica = verificar_existencia_excluido();

        fread(&a, sizeof(tp_produto), 1, arquivo);
        if(verifica == 1)
            apresentar_cabecalho();
        else
            printf("Nenhum leilao foi excluido para apresentar.\n");
        while(!feof(arquivo))
        {
            if(!a.estado)
                apresentar_linha(a);
            fread(&a, sizeof(tp_produto), 1, arquivo);
        }
        printf("\n");
        fclose(arquivo);
    }
}

int verificar_codigo(int codigo)
{
    FILE *arquivo;

    tp_produto a;

    int verificar = 0;

    arquivo = fopen("leilao.dat", "rb");
    if(arquivo == NULL)
        return verificar;
    else
    {
        fread(&a, sizeof(tp_produto), 1, arquivo);
        while(!feof(arquivo) && verificar == 0)
        {
            if(codigo == a.codigo)
                verificar = -1;
            fread(&a, sizeof(tp_produto), 1, arquivo);
        }
        fclose(arquivo);
    }

    return verificar;
}

tp_produto ler_produto()
{
    tp_produto a;

    int verifica;

    do
    {
        printf("Codigo.........: ");
        scanf("%d", &a.codigo);
        verifica = verificar_codigo(a.codigo);
        if(verifica == -1)
            printf("Um produto ja possui este codigo. Digite outro valor.\n\n");
    }while(verifica == -1);

    fflush(stdin);
    printf("Nome do produto: ");
    gets(a.nome_produto);
    printf("Valor..........: ");
    scanf("%f", &a.valor);
    a.lances = 0;
    a.situacao = 'A';
    a.nome[0] = '\0';
    a.telefone[0] = '\0';
    fflush(stdin);

    return a;
}

void novo_leilao()
{
    tp_produto a;

    char opcao;

    printf("Inserindo novo leilao...\n");
    do
    {
        a = ler_produto();
        incluir_produto(a);
        printf("Inserir mais outro leilao? <S/N>\n");
        scanf(" %c", &opcao);
        printf("\n");
    }
    while(opcao == 's' || opcao == 'S');
}

void apresentar_produto(tp_produto a)
{
    printf("\nCodigo.........: %d\n", a.codigo);
    printf("Nome do produto: %s\n", a.nome_produto);
    printf("Valor..........: %.2f\n", a.valor);
    printf("Lances.........: %d\n", a.lances);
    printf("Situacao.......: %c\n", a.situacao);
    printf("Nome...........: %s\n", a.nome);
    printf("Telefone.......: %s\n\n", a.telefone);
}

void pesquisar_produto()
{
    int codigo,
        posicao;

    tp_produto a;

    printf("Insira o codigo/numero do leilao a pesquisar: ");
    scanf("%d", &codigo);

    posicao = encontrar_pos_produto(codigo);
    if(posicao == -1)
        printf("\nNao foi possivel encontrar o produto.\n");
    else
    {
        a = retornar_produto(posicao);
        if(!a.estado)
            printf("\nProduto foi excluido.\n");
        apresentar_produto(a);
    }
}

tp_produto alterar_dados(tp_produto a)
{

    fflush(stdin);
    printf("Nome do produto: ");
    gets(a.nome_produto);
    printf("Valor..........: ");
    scanf("%f", &a.valor);

    return a;
}

void alterar_produto()
{
    int codigo,
        posicao;

    tp_produto a;

    lista_leilao();

    printf("Insira o codigo/numero do leilao para alterar: ");
    scanf("%d", &codigo);

    posicao = encontrar_pos_produto(codigo);
    if(posicao == -1)
        printf("\nNao foi possivel encontrar o produto.\n");
    else
    {
        a = retornar_produto(posicao);
        if(a.estado)
        {
            if(a.situacao == 'A')
            {
                apresentar_produto(a);
                printf("\nDigite o novo nome e valor do produto leiloado:\n");
                a = alterar_dados(a);
                substituir_produto(a, posicao);
            }
            else
            printf("\nNao eh possivel alterar um produto de leilao fechado.\n\n");
        }
        else
            printf("\nProduto foi excluido, nao eh possivel alterar.\n\n");
    }
}

void exclusao_logica()
{
    int codigo,
        posicao;

    char confirmar;

    tp_produto a;

    lista_leilao();

    printf("Insira o codigo/numero do leilao a excluir: ");
    scanf("%d", &codigo);

    posicao = encontrar_pos_produto(codigo);
    if(posicao == -1)
        printf("\nNao foi possivel encontrar o produto.\n");
    else
    {
        a = retornar_produto(posicao);
        if(a.situacao == 'F')
        {
            if(a.estado)
            {
                apresentar_produto(a);
                printf("Deseja remover o produto leiloado? <S/N>\n");
                scanf(" %c", &confirmar);
                printf("\n");
                if(confirmar == 's' || confirmar == 'S')
                {
                    a.estado = 0;
                    substituir_produto(a, posicao);
                }
            }
            else
                printf("\nProduto ja foi excluido.\n\n");
        }
        else
            printf("\nNao eh possivel excluir um leilao aberto.\n\n");
    }
}

void recuperar_produto()
{
    int codigo,
        posicao;

    char confirmar;

    tp_produto a;

    lista_excluidos();

    printf("Insira o codigo/numero do leilao a recuperar: ");
    scanf("%d", &codigo);

    posicao = encontrar_pos_produto(codigo);
    if(posicao == -1)
        printf("\nNao foi possivel encontrar o produto.\n");
    else
    {
        a = retornar_produto(posicao);
        if(!a.estado)
        {
            apresentar_produto(a);
            printf("Deseja recuperar o produto leiloado? <S/N>\n");
            scanf(" %c", &confirmar);
            if(confirmar == 's' || confirmar == 'S')
            {
                a.estado = 1;
                substituir_produto(a, posicao);
            }
        }
        else
            printf("\nNao eh possivel recuperar, produto nao foi excluido.\n");
    }
}

void exclusao_fisica()
{
    FILE *arquivo,
         *auxiliar;

    tp_produto a;

    int sucesso=0;

    arquivo = fopen("leilao.dat", "rb");
    if(arquivo == NULL)
        printf("\nNao foi possivel abrir o arquivo...\n");
    else
    {
        auxiliar = fopen("auxiliar.dat", "wb");
        if(auxiliar == NULL)
            printf("\nNao foi possivel excluir...\n");
        else
        {
            fread(&a, sizeof(tp_produto), 1, arquivo);
            while(!feof(arquivo))
            {
                if(a.estado == 1)
                    fwrite(&a, sizeof(tp_produto), 1, auxiliar);
                else
                    sucesso = 1;

                fread(&a, sizeof(tp_produto), 1, arquivo);
            }

            if(sucesso == 1)
                printf("Exclusao bem sucedida!\n");
            else
                printf("Nenhum leilao encontrado para exclusao.\n");

            fclose(arquivo);
            fclose(auxiliar);

            remove("leilao.dat");
            rename("auxiliar.dat", "leilao.dat");
        }
    }
}

tp_produto atualizar_informacao(tp_produto a, float novo_valor)
{
    fflush(stdin);
    a.valor = novo_valor;
    a.lances++;
    a.situacao = 'A';
    printf("\nNome do cliente: ");
    gets(a.nome);
    printf("Telefone.........: ");
    gets(a.telefone);

    return a;
}

void incluir_novo_lance()
{
    int codigo,
        posicao;

    char confirmar;

    tp_produto a;

    float novo_valor;

    lista_leilao();

    printf("Insira o codigo/numero do leilao para dar um novo lance: ");
    scanf("%d", &codigo);

    posicao = encontrar_pos_produto(codigo);
    if(posicao == -1)
        printf("\nNao foi possivel encontrar o produto.\n");
    else
    {
        a = retornar_produto(posicao);
        if(a.situacao == 'F')
            printf("\nNao eh possivel realizar lances em leiloes finalizados.\n\n");
        else
        {
            if(a.estado)
            {
                apresentar_produto(a);
                do
                {
                    printf("Digite o valor do lance: ");
                    scanf("%f", &novo_valor);
                    if(novo_valor <= a.valor)
                    {
                        printf("\nO lance precisa ser maior que o valor inicial do produto.\nDeseja refazer o lance? <S/N>\n");
                        scanf(" %c", &confirmar);
                        printf("\n");
                    }
                }
                while((confirmar == 's' || confirmar == 'S') && novo_valor <= a.valor);

                if(novo_valor > a.valor)
                {
                    a = atualizar_informacao(a, novo_valor);
                    apresentar_produto(a);
                    substituir_produto(a, posicao);
                }
            }
            else
                printf("\nLeilao esta excluido, nao eh possivel realizar o lance.\n\n");
        }
    }
}

void finalizar_leilao()
{
    int codigo,
        posicao;

    char confirmar;

    tp_produto a;

    float novo_valor;

    lista_leilao();

    printf("Insira o codigo/numero do leilao para finalizar: ");
    scanf("%d", &codigo);

    posicao = encontrar_pos_produto(codigo);
    if(posicao == -1)
        printf("\nNao foi possivel encontrar o produto.\n");
    else
    {
        a = retornar_produto(posicao);
        if(a.situacao == 'A')
        {
            apresentar_produto(a);

            printf("Deseja finalizar o leilao? <S/N>\n");
            scanf(" %c", &confirmar);
            printf("\n");

            if(confirmar == 's' || confirmar == 'S')
            {
                a.situacao = 'F';
                substituir_produto(a, posicao);
            }
        }
        else
            printf("\nLeilao ja foi finalizado...\n\n");
    }
}

void apresentar_leiloes_abertos()
{
    FILE *arquivo;

    tp_produto a;

    arquivo = fopen("leilao.dat", "rb");
    if(arquivo == NULL)
        printf("\nNao foi possivel abrir o arquivo...\n");
    else
    {
        fread(&a, sizeof(tp_produto), 1, arquivo);
        apresentar_cabecalho();
        while(!feof(arquivo))
        {
            if(a.estado == 1 && a.situacao == 'A')
                apresentar_linha(a);
            fread(&a, sizeof(tp_produto), 1, arquivo);
        }
        fclose(arquivo);
    }
}

void apresentar_leiloes_finalizados()
{
    FILE *arquivo;

    tp_produto a;

    arquivo = fopen("leilao.dat", "rb");
    if(arquivo == NULL)
        printf("\nNao foi possivel abrir o arquivo...\n");
    else
    {
        fread(&a, sizeof(tp_produto), 1, arquivo);
        apresentar_cabecalho();
        while(!feof(arquivo))
        {
            if(a.estado == 1 && a.situacao == 'F')
                apresentar_linha(a);
            fread(&a, sizeof(tp_produto), 1, arquivo);
        }
        fclose(arquivo);
    }
}
