// Tarea 1
#include <stdio.h>

int main() {
    int idade;
    int anoAtual;
    int anoNascimento;

    printf("Digite sua idade: ");
    scanf("%d", &idade);

    printf("Digite o ano atual: ");
    scanf("%d", &anoAtual);

    anoNascimento = anoAtual - idade;

    printf("Seu ano de nascimento e: %d\n", anoNascimento);

    return 0;
}

// Tarea 2
#include <stdio.h>

int main() {
    int numero;
    int contador = 0;

    for (int i = 0; i < 5; i++) {
        printf("Digite o numero %d: ", i + 1);
        scanf("%d", &numero);

        if (numero > 10) {
            contador++;
        }
    }

    printf("Quantidade de numeros maiores que 10: %d\n", contador);

    return 0;
}

// Tarea 3
#include <stdio.h>

int main() {
    int vet[5];
    int soma = 0;

    for (int i = 0; i < 5; i++) {
        printf("Digite o valor da posicao %d: ", i);
        scanf("%d", &vet[i]);
    }

    for (int i = 0; i < 5; i++) {
        soma = soma + vet[i];
    }

    printf("Soma dos elementos: %d\n", soma);

    return 0;
}

// Tarea 4
#include <stdio.h>

int main() {
    int numero;

    printf("Digite um numero: ");
    scanf("%d", &numero);

    int *ponteiro = &numero;

    *ponteiro = *ponteiro + 10;

    printf("Valor final: %d\n", numero);

    return 0;
}
