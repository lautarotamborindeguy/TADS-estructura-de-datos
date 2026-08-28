#include "carro.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Frota {
    Carro *carros;
    int quantidade;
    int capacidade;
};

Frota *criar_frota(int capacidade) {
    Frota *f = malloc(sizeof(Frota));
    f->carros = malloc(capacidade * sizeof(Carro));

    f->quantidade = 0;
    f->capacidade = capacidade;

    return f;
}

void cadastrar_carro(Frota *f, char *modelo, int ano, float preco) {
    if (f->quantidade >= f->capacidade) {
        printf("A frota esta cheia.\n");
        return;
    }

    Carro *novo_carro = &f->carros[f->quantidade];

    strcpy(novo_carro->modelo, modelo);
    novo_carro->ano = ano;
    novo_carro->preco = preco;

    f->quantidade++;

    printf("Carro cadastrado com sucesso.\n");
}

void listar_frota(Frota *f) {
    printf("\n--- Carros da frota ---\n");

    for (int i = 0; i < f->quantidade; i++) {
        printf("Carro %d\n", i + 1);
        printf("Modelo: %s\n", f->carros[i].modelo);
        printf("Ano: %d\n", f->carros[i].ano);
        printf("Preco: R$ %.2f\n\n", f->carros[i].preco);
    }
}

float calcular_valor_total(Frota *f) {
    float total = 0.0f;

    for (int i = 0; i < f->quantidade; i++) {
        total += f->carros[i].preco;
    }

    return total;
}

void liberar_frota(Frota *f) {
    free(f->carros);
    free(f);
}
