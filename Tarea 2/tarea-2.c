#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Cantidad de números que tendrá cada array.
#define QUANTIDADE_PRIMOS 10000
#define QUANTIDADE_SORTEADA 25

// Comprueba si "numero" es primo usando los primos encontrados anteriormente.
// Retorna 1 si es primo y 0 si no lo es.
int ehPrimo(int numero, const int primos[], int quantidadeEncontrada) {
    // Por definición, los números menores que 2 no son primos.
    if (numero < 2) {
        return 0;
    }

    // Solo es necesario buscar divisores hasta la raíz cuadrada del número.
    // La expresión "primos[i] <= numero / primos[i]" evita calcular la raíz.
    for (int i = 0;
         i < quantidadeEncontrada && primos[i] <= numero / primos[i];
         i++) {
        // Si la división es exacta, el número tiene un divisor y no es primo.
        if (numero % primos[i] == 0) {
            return 0;
        }
    }

    // No se encontró ningún divisor.
    return 1;
}

// Encuentra los primeros 10.000 números primos y los guarda en el array.
void gerarPrimos(int primos[]) {
    int quantidadeEncontrada = 0;
    int candidato = 2;

    while (quantidadeEncontrada < QUANTIDADE_PRIMOS) {
        // Si el candidato es primo, se guarda en la siguiente posición libre.
        if (ehPrimo(candidato, primos, quantidadeEncontrada)) {
            primos[quantidadeEncontrada] = candidato;
            quantidadeEncontrada++;
        }

        // Se prueba el siguiente número entero.
        candidato++;
    }
}

// Retorna un índice aleatorio válido, desde 0 hasta 9999.
int sortearIndice(void) {
    return rand() % QUANTIDADE_PRIMOS;
}

int main(void) {
    // Primer array: contiene los 10.000 números primos generados.
    int primos[QUANTIDADE_PRIMOS];

    // Segundo array: contiene los 25 primos elegidos al azar.
    int primosSorteados[QUANTIDADE_SORTEADA];

    // Inicializa rand() usando la hora actual para variar cada ejecución.
    srand((unsigned int) time(NULL));

    // Llena el primer array con los números primos.
    gerarPrimos(primos);

    // Sortea 25 índices y copia los primos correspondientes al segundo array.
    for (int i = 0; i < QUANTIDADE_SORTEADA; i++) {
        int indiceSorteado = sortearIndice();
        primosSorteados[i] = primos[indiceSorteado];
    }

    printf("Numeros primos sorteados:\n");

    // Muestra en pantalla los 25 números primos seleccionados.
    for (int i = 0; i < QUANTIDADE_SORTEADA; i++) {
        printf("%d\n", primosSorteados[i]);
    }

    return 0;
}
