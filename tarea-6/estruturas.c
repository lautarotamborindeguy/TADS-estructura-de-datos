#include <stdio.h>
#include <stdlib.h>
#include "estruturas.h"

/* Nó usado na Pilha e na Fila */
typedef struct no {
    int info;
    struct no* prox;
} No;

/* Estrutura da Pilha */
struct pilha {
    No* topo;
};

/* Estrutura da Fila */
struct fila {
    No* inicio;
    No* fim;
};

/* Nó da Lista Dupla */
typedef struct no_duplo {
    int info;
    struct no_duplo* ant;
    struct no_duplo* prox;
} NoDuplo;


/* =========================
   PILHA
   ========================= */

Pilha* criar_pilha(void) {
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));

    if (p != NULL) {
        p->topo = NULL;
    }

    return p;
}

void push(Pilha* p, int valor) {
    if (p == NULL) {
        return;
    }

    No* novo = (No*) malloc(sizeof(No));

    if (novo == NULL) {
        printf("Erro ao alocar memoria.\n");
        return;
    }

    novo->info = valor;
    novo->prox = p->topo;

    p->topo = novo;
}

int pop(Pilha* p, int* sucesso) {
    if (p == NULL || p->topo == NULL) {
        *sucesso = 0;
        return 0;
    }

    No* removido = p->topo;
    int valor = removido->info;

    p->topo = removido->prox;

    free(removido);

    *sucesso = 1;

    return valor;
}

void liberar_pilha(Pilha* p) {
    if (p == NULL) {
        return;
    }

    No* atual = p->topo;

    while (atual != NULL) {
        No* proximo = atual->prox;

        free(atual);

        atual = proximo;
    }

    free(p);
}


/* =========================
   FILA
   ========================= */

Fila* criar_fila(void) {
    Fila* f = (Fila*) malloc(sizeof(Fila));

    if (f != NULL) {
        f->inicio = NULL;
        f->fim = NULL;
    }

    return f;
}

void enqueue(Fila* f, int valor) {
    if (f == NULL) {
        return;
    }

    No* novo = (No*) malloc(sizeof(No));

    if (novo == NULL) {
        printf("Erro ao alocar memoria.\n");
        return;
    }

    novo->info = valor;
    novo->prox = NULL;

    if (f->inicio == NULL) {
        f->inicio = novo;
        f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
}

int dequeue(Fila* f, int* sucesso) {
    if (f == NULL || f->inicio == NULL) {
        *sucesso = 0;
        return 0;
    }

    No* removido = f->inicio;
    int valor = removido->info;

    f->inicio = removido->prox;

    if (f->inicio == NULL) {
        f->fim = NULL;
    }

    free(removido);

    *sucesso = 1;

    return valor;
}

void liberar_fila(Fila* f) {
    if (f == NULL) {
        return;
    }

    No* atual = f->inicio;

    while (atual != NULL) {
        No* proximo = atual->prox;

        free(atual);

        atual = proximo;
    }

    free(f);
}


/* =========================
   LISTA DUPLAMENTE ENCADEADA
   ========================= */

void teste_lista_dupla(void) {
    NoDuplo* A = (NoDuplo*) malloc(sizeof(NoDuplo));
    NoDuplo* B = (NoDuplo*) malloc(sizeof(NoDuplo));
    NoDuplo* C = (NoDuplo*) malloc(sizeof(NoDuplo));

    if (A == NULL || B == NULL || C == NULL) {
        printf("Erro ao alocar memoria.\n");

        free(A);
        free(B);
        free(C);

        return;
    }

    A->info = 10;
    B->info = 20;
    C->info = 30;

    A->ant = NULL;
    A->prox = B;

    B->ant = A;
    B->prox = C;

    C->ant = B;
    C->prox = NULL;

    printf("A -> B -> C: %d -> %d -> %d\n",
           A->info, B->info, C->info);

    printf("Valor de A acessado a partir de C: %d\n",
           C->ant->ant->info);

    free(A);
    free(B);
    free(C);
}
