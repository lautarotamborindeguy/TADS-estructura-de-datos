#include "carro.h"

#include <stdio.h>

int main(void) {
    int capacidade;
    int opcao;

    printf("Quantos carros a locadora comporta? ");
    scanf("%d", &capacidade);

    Frota *frota = criar_frota(capacidade);

    do {
        printf("\n--- Menu ---\n");
        printf("1. Cadastrar Carro\n");
        printf("2. Listar Todos\n");
        printf("3. Ver Valor Total da Frota\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                char modelo[50];
                int ano;
                float preco;

                printf("Modelo: ");
                scanf(" %49[^\n]", modelo);

                printf("Ano: ");
                scanf("%d", &ano);

                printf("Preco: R$ ");
                scanf("%f", &preco);

                cadastrar_carro(frota, modelo, ano, preco);
                break;
            }

            case 2:
                listar_frota(frota);
                break;

            case 3:
                printf("Valor total da frota: R$ %.2f\n",
                       calcular_valor_total(frota));
                break;

            case 4:
                printf("Encerrando o programa.\n");
                break;
        }
    } while (opcao != 4);

    liberar_frota(frota);

    return 0;
}
