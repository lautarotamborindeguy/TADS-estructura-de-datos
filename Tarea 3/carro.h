#ifndef CARRO_H
#define CARRO_H

typedef struct {
    char modelo[50];
    int ano;
    float preco;
} Carro;

typedef struct Frota Frota;

Frota *criar_frota(int capacidade);
void cadastrar_carro(Frota *f, char *modelo, int ano, float preco);
void listar_frota(Frota *f);
float calcular_valor_total(Frota *f);
void liberar_frota(Frota *f);

#endif
