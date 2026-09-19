#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

// Estrutura de cada "caixa" da lista
struct no {
    int info;
    struct no* prox;
};

// Estrutura de controle da lista
struct lista {
    No* inicio;
};

// Cria a lista e inicializa o ponteiro de inicio como NULL
Lista* criar_lista() {
    Lista* l = (Lista*) malloc(sizeof(Lista));

    if (l != NULL) {
        l->inicio = NULL;
    }

    return l;
}

void inserir_final(Lista* l, int valor) {
    if (l == NULL) {
        return;
    }

    No* novo = (No*) malloc(sizeof(No));

    if (novo == NULL) {
        printf("Erro ao alocar memoria.\n");
        return;
    }

    novo->info = valor;
    novo->prox = NULL;

    // Caso 1: lista vazia
    if (l->inicio == NULL) {
        l->inicio = novo;
        return;
    }

    // Caso 2: lista ja possui elementos
    No* atual = l->inicio;

    while (atual->prox != NULL) {
        atual = atual->prox;
    }

    atual->prox = novo;
}

int buscar_elemento(Lista* l, int alvo) {
    if (l == NULL) {
        return 0;
    }

    No* atual = l->inicio;

    while (atual != NULL) {
        if (atual->info == alvo) {
            return 1;
        }

        atual = atual->prox;
    }

    return 0;
}

void imprimir_lista(Lista* l) {
    if (l == NULL) {
        return;
    }

    No* atual = l->inicio;

    while (atual != NULL) {
        printf("[%d] -> ", atual->info);
        atual = atual->prox;
    }

    printf("NULL\n");
}

void liberar_lista(Lista* l) {
    if (l == NULL) {
        return;
    }

    No* atual = l->inicio;

    while (atual != NULL) {
        No* proximo = atual->prox;

        free(atual);

        atual = proximo;
    }

    free(l);
}
