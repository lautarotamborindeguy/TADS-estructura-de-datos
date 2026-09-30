#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

typedef struct pilha Pilha;
typedef struct fila Fila;

/* Pila */
Pilha* criar_pilha(void);
void push(Pilha* p, int valor);
int pop(Pilha* p, int* sucesso);
void liberar_pilha(Pilha* p);

/* Cola */
Fila* criar_fila(void);
void enqueue(Fila* f, int valor);
int dequeue(Fila* f, int* sucesso);
void liberar_fila(Fila* f);

/* Lista doblemente enlazada */
void teste_lista_dupla(void);

#endif
