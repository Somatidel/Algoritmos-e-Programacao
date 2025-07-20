//Rafael Luiz de Oliveira PE3028534
//Eduardo Viana PE3029387

#include <stdio.h>
#include <string.h>

void menu(int *op)
{
    printf("\n===============MENU===============\n");
    printf("1. Ler nomes;\n");
    printf("2. Contar nomes que iniciam com uma letra;\n");
    printf("3. Encontrar posicao de um nome;\n");
    printf("4. Contar ocorrencias de uma letra;\n");
    printf("5. Apresentar nomes iniciados com uma string;\n");
    printf("6. Encontrar posicao do maior nome;\n");
    printf("7. Apresentar primeiros nomes;\n");
    printf("8. Apresentar sobrenomes;\n");
    printf("9. Encontrar pessoa com mais palavras no nome;\n");
    printf("0. Sair.\n");
    printf("Opcao: ");
    scanf("%d", op);
    fflush(stdin);
}

int ler_lista(char nomes[50][50])
{
    int i,
        qte_lista;

    printf("Quantos nomes tem na lista? (MAX 50)\n");
    do
    {
        scanf("%d", &qte_lista);
        fflush(stdin);

        if(qte_lista < 1 || qte_lista > 50)
            printf("No minimo 1 nome e no maximo 50 nomes...\n");
    }
    while(qte_lista < 1 || qte_lista > 50);

    printf("\nLendo nomes:\n");
    for(i=0; i<qte_lista; i++)
    {
        fgets(nomes[i], 50, stdin);
    }

    return qte_lista;
}

int comparar_letras(char a, char b)
{
    if(a >= 'A' && a <= 'Z')
        a += 32;
    if(b >= 'B' && b <= 'Z')
        b += 32;

    if(a == b)
        return 1;

    return 0;
}

int procurar_letra(char nomes[50][50], int qte_lista)
{
    int i,
        contador=0;

    char letra;

    printf("\nQual letra deseja procurar?\n");

    scanf("%c", &letra);
    fflush(stdin);

    for(i=0; i<qte_lista; i++)
        if(comparar_letras(nomes[i][0], letra) == 1)
            contador++;

    return contador;
}

int pos_nome(char nomes[50][50], int qte_lista)
{
    int i;

    char procurar[50];

    printf("Qual nome deseja procurar?\n");
    fgets(procurar, 50, stdin);

    for(i=0; i<qte_lista; i++)
        if(strcmpi(nomes[i], procurar) == 0)
            return i;
}

int localizar_ocorrencia(char nomes[50][50], int qte_lista)
{
    int i,
        j,
        letra,
        contador=0;

    printf("Qual letra deseja localizar?\n");

    scanf("%c", &letra);
    fflush(stdin);

    for(i=0; i<qte_lista; i++)
        for(j=0; nomes[i][j] != '\0'; j++)
            if(comparar_letras(nomes[i][j], letra) == 1)
                contador++;

    return contador;
}

void apresentar_nome_string(char nomes[50][50], int qte_lista)
{
    int i,
        j,
        verifica=0;

    char procurar_nome[50];

    printf("Qual nome deseja pesquisar?\n");
    fgets(procurar_nome, 50, stdin);

    printf("\nApresentando nomes...\n\n");
    for(i=0; i<qte_lista; i++)
        if(strncmp(nomes[i], procurar_nome, strlen(procurar_nome)-1) == 0)
        {
            printf("- %s\n", nomes[i]);
            verifica = 1;
        }

    if(verifica == 0)
        printf("Nenhum nome encontrado.\n");
}

int pos_maior_nome(char nomes[50][50], int qte_lista)
{
    int i,
        pos=0,
        maior;

    maior = strlen(nomes[0]);
    for(i=1; i<qte_lista; i++)
        if(strlen(nomes[i]) > maior)
        {
            maior = strlen(nomes[i]);
            pos = i;
        }

    return pos;
}

void apresentar_primeiro_nome(char nomes[50][50], int qte_lista)
{
    int i,
        j;

    printf("\nApresentando os primeiros nomes...\n\n");
    for(i=0; i<qte_lista; i++)
    {
        for(j=0; nomes[i][j] != ' '; j++)
            printf("%c", nomes[i][j]);
        printf("\n");
    }
}

void apresentar_sobrenomes(char nomes[50][50], int qte_lista)
{
    int i,
        j,
        espaco=0;

    printf("\nApresentando os sobrenomes...\n\n");
    for(i=0; i<qte_lista; i++)
    {
        for(j=0; nomes[i][j] != '\0'; j++)
        {
            if(nomes[i][j] == ' ')
                espaco = 1;
            if(espaco == 1)
                printf("%c", nomes[i][j+1]);
        }
        espaco = 0;
        printf("\n");
    }
}

void contador_palavras(char nomes[50][50], int qte_lista, int qte_palavra[50])
{
    int i,
        j,
        espaco=0,
        palavras=0;

    for(i=0; i<qte_lista; i++)
    {
        for(j=0; nomes[i][j] != '\0'; j++)
        {
            if(nomes[i][j] != ' ' && espaco == 0)
            {
                palavras++;
                espaco = 1;
            }
            else if(nomes[i][j] == ' ')
                espaco = 0;
        }
        qte_palavra[i] = palavras;
        palavras = 0;
    }
}

int encontrar_maior_nome(char nomes[50][50], int qte_lista, int qte_palavra[50])
{
    int i,
        pos=0,
        maior;

    maior = qte_palavra[0];
    for(i=1; i<qte_lista; i++)
        if(qte_palavra[i] > maior)
        {
            maior = qte_palavra[i];
            pos = i;
        }

    return pos;
}

void main()
{
    char nomes[50][50];

    int op,
        pos,
        qte_lista,
        qte_palavra[50];

    do
    {
        menu(&op);

        switch(op)
        {
        case 0:
            printf("\nFim de programa.\n\n");
            break;

        case 1:
            qte_lista = ler_lista(nomes);
            break;

        case 2:
            printf("O nome de %d pessoas iniciam com essa letra.\n", procurar_letra(nomes, qte_lista));
            break;

        case 3:
            pos = pos_nome(nomes, qte_lista);
            printf("\nNome[%d]: %s\n", pos, nomes[pos]);
            break;

        case 4:
            printf("Ocorrem %d instancias dessa letra.\n", localizar_ocorrencia(nomes, qte_lista));
            break;

        case 5:
            apresentar_nome_string(nomes, qte_lista);
            break;

        case 6:
            pos = pos_maior_nome(nomes, qte_lista);
            printf("Nome[%d]: %s possui o maior nome.\n", pos, nomes[pos]);
            break;

        case 7:
            apresentar_primeiro_nome(nomes, qte_lista);
            break;

        case 8:
            apresentar_sobrenomes(nomes, qte_lista);
            break;

        case 9:
            contador_palavras(nomes, qte_lista, qte_palavra);
            pos = encontrar_maior_nome(nomes, qte_lista, qte_palavra);
            printf("\n- %s (possui %d palavras);\n", nomes[pos], qte_palavra[pos]);
            break;

        default:
            printf("Insira uma opcao valida...\n");
        }
    }
    while(op != 0);
}
