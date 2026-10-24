#include <stdio.h>
#include <stdlib.h>

// Estrutura do No da Arvore
typedef struct no {
    int valor;
    struct no *esq;
    struct no *dir;
} No;

// Funcao para criar um novo no
No* criar_no(int valor) {
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

// Insercao na Arvore Binaria de Busca (BST)
No* inserir(No *raiz, int valor) {
    if (raiz == NULL) {
        return criar_no(valor);
    }
    if (valor < raiz->valor) {
        raiz->esq = inserir(raiz->esq, valor);
    } else if (valor > raiz->valor) {
        raiz->dir = inserir(raiz->dir, valor);
    }
    return raiz;
}

// Imprime el arbol
void imprimir_visual(No *raiz, int nivel, char lado) {
    if (raiz == NULL) {
        return;
    }

    for (int i = 0; i < nivel; i++) {
        printf("    ");
    }
    printf("%c: %d\n", lado, raiz->valor);

    imprimir_visual(raiz->esq, nivel + 1, 'E');
    imprimir_visual(raiz->dir, nivel + 1, 'D');
}

// Retorna 1 si encuentra el valor y 0 si no lo hace
int buscar(No *raiz, int valor) {
    if (raiz == NULL) {
        return 0;
    }
    if (raiz->valor == valor) {
        return 1;
    }
    if (valor < raiz->valor) {
        return buscar(raiz->esq, valor);
    }
    return buscar(raiz->dir, valor);
}

int main() {
    No *raiz = NULL;

    // Insertar datos
    int valores[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++) {
        raiz = inserir(raiz, valores[i]);
    }

    // Imprimir arbol
    printf("Arvore Binaria de Busca:\n");
    imprimir_visual(raiz, 0, 'R');

    // Buscar valores presentes y ausentes
    int testes[] = {40, 70, 25, 90};
    printf("\nResultado das buscas:\n");
    for (int i = 0; i < 4; i++) {
        if (buscar(raiz, testes[i])) {
            printf("Valor %d encontrado.\n", testes[i]);
        } else {
            printf("Valor %d nao encontrado.\n", testes[i]);
        }
    }

    return 0;
}
