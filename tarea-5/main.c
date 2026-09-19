#include <stdio.h>
#include "lista.h"

int main() {
    Lista* minha_lista = criar_lista();
    int opcao = 0, valor;

    if (minha_lista == NULL) {
        printf("Erro ao criar a lista.\n");
        return 1;
    }

    do {
        printf("\n--- MENU DE LISTA DINAMICA ---\n");
        printf("1. Inserir no final\n");
        printf("2. Buscar elemento\n");
        printf("3. Imprimir lista\n");
        printf("4. Sair (e limpar memoria)\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch(opcao) {

            case 1:
                printf("Digite o valor para inserir: ");
                scanf("%d", &valor);

                inserir_final(minha_lista, valor);

                break;

            case 2:
                printf("Digite o valor para buscar: ");
                scanf("%d", &valor);

                if (buscar_elemento(minha_lista, valor)) {
                    printf("Elemento encontrado!\n");
                } else {
                    printf("Elemento nao encontrado.\n");
                }

                break;

            case 3:

                imprimir_lista(minha_lista);

                break;

            case 4:

                liberar_lista(minha_lista);

                printf("Memoria liberada. Encerrando...\n");

                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while(opcao != 4);

    return 0;
}
