//Eduardo Viana PE3029387
//Rafael Luiz de Oliveira PE3028534

#include <stdio.h>
#include <string.h>

void obterDados(char *campo, char *valor) {
    printf("Digite o %s: ", campo);
    gets(valor);
}

void separarNome(char *nomeCompleto, char *sobrenome, char *nome) {
    char *ultimoEspaco = strrchr(nomeCompleto, ' ');
    if (ultimoEspaco != NULL) {
        strcpy(sobrenome, ultimoEspaco + 1);
        strncpy(nome, nomeCompleto, ultimoEspaco - nomeCompleto);
        nome[ultimoEspaco - nomeCompleto] = '\0';
    } else {
        strcpy(sobrenome, nomeCompleto);
        nome[0] = '\0';
    }

    for (int i = 0; sobrenome[i]; i++) {
        sobrenome[i] = toupper(sobrenome[i]);
    }
}

void formatarReferencia(char *sobrenome, char *nome, char *titulo, char *editora, char *cidade, int ano) {
    printf("%s, %s. %s. %s: %s, %d.\n", sobrenome, nome, titulo, editora, cidade, ano);
}

int main() {
    char nomeCompleto[100], sobrenome[50], nome[50], titulo[100], editora[50], cidade[50];
    int ano;

    obterDados("nome completo", nomeCompleto);
    obterDados("título da publicação", titulo);
    obterDados("editora", editora);
    obterDados("cidade", cidade);

    printf("Digite o ano: ");
    scanf("%d", &ano);
    fflush(stdin);

    separarNome(nomeCompleto, sobrenome, nome);
    formatarReferencia(sobrenome, nome, titulo, editora, cidade, ano);

    return 0;
}
