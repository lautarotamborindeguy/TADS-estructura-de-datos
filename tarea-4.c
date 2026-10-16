// Ejercicio 1
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *vetor;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Tamanho invalido.\n");
        return 1;
    }

    vetor = (int *)malloc(n * sizeof(int));

    if (vetor == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Digite o valor da posicao %d: ", i);
        scanf("%d", &vetor[i]);
    }

    printf("Vetor: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\n");

    free(vetor);

    return 0;
}

// Ejercicio 2
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *vetor;
    int soma = 0;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Tamanho invalido.\n");
        return 1;
    }

    vetor = (int *)malloc(n * sizeof(int));

    if (vetor == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Digite o valor da posicao %d: ", i);
        scanf("%d", &vetor[i]);

        soma += vetor[i];
    }

    printf("Soma dos elementos: %d\n", soma);

    free(vetor);

    return 0;
}

// Ejercicio 3
#include <stdio.h>
#include <stdlib.h>

int main() {
    int tamanho;
    char *texto;

    printf("Digite o tamanho maximo da string: ");
    scanf("%d", &tamanho);

    if (tamanho <= 0) {
        printf("Tamanho invalido.\n");
        return 1;
    }

    texto = (char *)malloc((tamanho + 1) * sizeof(char));

    if (texto == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    getchar();

    printf("Digite a string: ");
    fgets(texto, tamanho + 1, stdin);

    printf("String digitada: %s\n", texto);

    free(texto);

    return 0;
}

// Ejercicio 4
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *vetor;
    int *duplicado;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Tamanho invalido.\n");
        return 1;
    }

    vetor = (int *)malloc(n * sizeof(int));
    duplicado = (int *)malloc((2 * n) * sizeof(int));

    if (vetor == NULL || duplicado == NULL) {
        printf("Erro ao alocar memoria.\n");

        free(vetor);
        free(duplicado);

        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Digite o valor da posicao %d: ", i);
        scanf("%d", &vetor[i]);
    }

    for (int i = 0; i < n; i++) {
        duplicado[2 * i] = vetor[i];
        duplicado[2 * i + 1] = vetor[i];
    }

    printf("Novo vetor: ");

    for (int i = 0; i < 2 * n; i++) {
        printf("%d ", duplicado[i]);
    }

    printf("\n");

    free(vetor);
    free(duplicado);

    return 0;
}

// Ejercicio 5
#include <stdio.h>
#include <stdlib.h>

int *inverterVetor(int *vetor, int n) {
    int *invertido;

    invertido = (int *)malloc(n * sizeof(int));

    if (invertido == NULL) {
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        invertido[i] = vetor[n - 1 - i];
    }

    return invertido;
}

int main() {
    int n;
    int *vetor;
    int *invertido;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Tamanho invalido.\n");
        return 1;
    }

    vetor = (int *)malloc(n * sizeof(int));

    if (vetor == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Digite o valor da posicao %d: ", i);
        scanf("%d", &vetor[i]);
    }

    invertido = inverterVetor(vetor, n);

    if (invertido == NULL) {
        printf("Erro ao alocar memoria para o vetor invertido.\n");

        free(vetor);

        return 1;
    }

    printf("Vetor invertido: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", invertido[i]);
    }

    printf("\n");

    free(vetor);
    free(invertido);

    return 0;
}

// Ejercicio 6
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int tam1, tam2;

    char *str1;
    char *str2;
    char *resultado;

    printf("Digite o tamanho maximo da primeira string: ");
    scanf("%d", &tam1);

    printf("Digite o tamanho maximo da segunda string: ");
    scanf("%d", &tam2);

    if (tam1 <= 0 || tam2 <= 0) {
        printf("Tamanho invalido.\n");
        return 1;
    }

    str1 = (char *)malloc((tam1 + 1) * sizeof(char));
    str2 = (char *)malloc((tam2 + 1) * sizeof(char));

    resultado =
        (char *)malloc((tam1 + tam2 + 1) * sizeof(char));

    if (str1 == NULL ||
        str2 == NULL ||
        resultado == NULL) {

        printf("Erro ao alocar memoria.\n");

        free(str1);
        free(str2);
        free(resultado);

        return 1;
    }

    getchar();

    printf("Digite a primeira string: ");
    fgets(str1, tam1 + 1, stdin);

    str1[strcspn(str1, "\n")] = '\0';

    printf("Digite a segunda string: ");
    fgets(str2, tam2 + 1, stdin);

    str2[strcspn(str2, "\n")] = '\0';

    strcpy(resultado, str1);
    strcat(resultado, str2);

    printf("String concatenada: %s\n", resultado);

    free(str1);
    free(str2);
    free(resultado);

    return 0;
}

// Ejercicio 7
#include <stdio.h>
#include <stdlib.h>

int main() {
    int tamanho;
    int vogais = 0;

    char *texto;

    printf("Digite o tamanho maximo da string: ");
    scanf("%d", &tamanho);

    if (tamanho <= 0) {
        printf("Tamanho invalido.\n");
        return 1;
    }

    texto = (char *)malloc((tamanho + 1) * sizeof(char));

    if (texto == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    getchar();

    printf("Digite a string: ");
    fgets(texto, tamanho + 1, stdin);

    for (int i = 0; texto[i] != '\0'; i++) {

        if (
            texto[i] == 'a' || texto[i] == 'A' ||
            texto[i] == 'e' || texto[i] == 'E' ||
            texto[i] == 'i' || texto[i] == 'I' ||
            texto[i] == 'o' || texto[i] == 'O' ||
            texto[i] == 'u' || texto[i] == 'U'
        ) {
            vogais++;
        }
    }

    printf("Quantidade de vogais: %d\n", vogais);

    free(texto);

    return 0;
}

// Ejercicio 8
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *nome;
    int idade;
    float altura;
} Pessoa;

int main() {
    Pessoa *pessoa;
    int tamanhoNome;

    pessoa = (Pessoa *)malloc(sizeof(Pessoa));

    if (pessoa == NULL) {
        printf("Erro ao alocar memoria para a pessoa.\n");
        return 1;
    }

    printf("Digite o tamanho maximo do nome: ");
    scanf("%d", &tamanhoNome);

    if (tamanhoNome <= 0) {
        printf("Tamanho invalido.\n");

        free(pessoa);

        return 1;
    }

    pessoa->nome =
        (char *)malloc((tamanhoNome + 1) * sizeof(char));

    if (pessoa->nome == NULL) {
        printf("Erro ao alocar memoria para o nome.\n");

        free(pessoa);

        return 1;
    }

    getchar();

    printf("Digite o nome: ");
    fgets(pessoa->nome, tamanhoNome + 1, stdin);

    printf("Digite a idade: ");
    scanf("%d", &pessoa->idade);

    printf("Digite a altura: ");
    scanf("%f", &pessoa->altura);

    printf("\nDados da pessoa:\n");

    printf("Nome: %s", pessoa->nome);
    printf("Idade: %d\n", pessoa->idade);
    printf("Altura: %.2f\n", pessoa->altura);

    free(pessoa->nome);
    free(pessoa);

    return 0;
}
