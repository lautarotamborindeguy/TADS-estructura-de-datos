#include <stdio.h>
#include "estruturas.h"

int main(void) {
    Pilha* pilha = criar_pilha();
    Fila* fila = criar_fila();

    int opcao = 0;
    int valor;
    int sucesso;

    /* Verifica si las estructuras fueron creadas correctamente */
    if (pilha == NULL || fila == NULL) {
        printf("Erro ao criar as estruturas.\n");

        liberar_pilha(pilha);
        liberar_fila(fila);

        return 1;
    }

    do {
        printf("\n--- MENU ---\n");
        printf("1. Push na Pilha\n");
        printf("2. Pop na Pilha\n");
        printf("3. Enqueue na Fila\n");
        printf("4. Dequeue na Fila\n");
        printf("5. Teste de Lista Dupla\n");
        printf("6. Sair\n");

        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:
                /* Inserta un valor en el tope de la pila */
                printf("Digite o valor: ");
                scanf("%d", &valor);

                push(pilha, valor);

                break;

            case 2:
                /* Elimina el elemento que está en el tope de la pila */
                valor = pop(pilha, &sucesso);

                if (sucesso) {
                    printf("Valor removido da pilha: %d\n", valor);
                } else {
                    printf("A pilha esta vazia.\n");
                }

                break;

            case 3:
                /* Inserta un valor al final de la cola */
                printf("Digite o valor: ");
                scanf("%d", &valor);

                enqueue(fila, valor);

                break;

            case 4:
                /* Elimina el primer elemento de la cola */
                valor = dequeue(fila, &sucesso);

                if (sucesso) {
                    printf("Valor removido da fila: %d\n", valor);
                } else {
                    printf("A fila esta vazia.\n");
                }

                break;

            case 5:
                /* Ejecuta la prueba de la lista doblemente enlazada */
                teste_lista_dupla();

                break;

            case 6:
                /* Libera todos los nodos antes de finalizar */
                liberar_pilha(pilha);
                liberar_fila(fila);

                printf("Memoria liberada. Encerrando...\n");

                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 6);

    return 0;
}
