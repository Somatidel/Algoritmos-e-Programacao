//Eduardo Viana PE3029387
//Rafael Luiz de Oliveira PE3028534

#include <stdio.h>
#include <string.h>

void substituir_caracter(char str[], char antigo, char novo) {
    for (int i = 0; str[i]; i++) {
        if (str[i] == antigo) {
            str[i] = novo;
        }
    }
}

void transformar_maiusculas(char str[]) {
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';
        }
    }
}

void transformar_minusculas(char str[]) {
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] - 'A' + 'a';
        }
    }
}

void remover_numeros(char str[]) {
    int j = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] < '0' || str[i] > '9') {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

void separar_em_maiusculas_e_minusculas(char str[], char maiusculas[], char minusculas[]) {
    int j1 = 0, j2 = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            maiusculas[j1++] = str[i];
        } else if (str[i] >= 'a' && str[i] <= 'z') {
            minusculas[j2++] = str[i];
        }
    }
    maiusculas[j1] = '\0';
    minusculas[j2] = '\0';
}

int main() {
    char texto[100];
    char maiusculas[100], minusculas[100];

    printf("Digite o texto: ");
    fgets(texto, 100, stdin);
    texto[strcspn(texto, "\n")] = 0;

    char antigo, novo;
    printf("Digite o caractere a ser substituido: ");
    scanf(" %c", &antigo);
    printf("Digite o novo caractere para substituicao: ");
    scanf(" %c", &novo);

    substituir_caracter(texto, antigo, novo);
    separar_em_maiusculas_e_minusculas(texto, maiusculas, minusculas);
    transformar_maiusculas(texto);
    remover_numeros(texto);

    printf("Texto (apos manipulacao): %s\n", texto);
    printf("Maiusculas: %s\n", maiusculas);
    printf("Minusculas: %s\n", minusculas);

    return 0;
}
