#ifndef LISTA_H
#define LISTA_H

typedef struct no No;
typedef struct lista Lista;

Lista* criar_lista();
void inserir_final(Lista* l, int valor);
int buscar_elemento(Lista* l, int alvo);
void imprimir_lista(Lista* l);
void liberar_lista(Lista* l);

#endif
