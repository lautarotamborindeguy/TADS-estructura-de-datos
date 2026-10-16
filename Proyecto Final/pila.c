#include <stdio.h>
#include <stdlib.h>
#include "estructuras.h"

// Cada nodo es una atencion terminada y apunta a la atencion anterior.
typedef struct nodo_pila {
    Cliente cliente;
    struct nodo_pila *siguiente;
} NodoPila;

struct pila {
    // El tope siempre es el registro mas reciente que todavia esta guardado.
    NodoPila *tope;
};

Pila *crear_pila(void) {
    Pila *pila = malloc(sizeof(Pila));

    if (pila != NULL) {
        // Todavia no hay atenciones en el historial.
        pila->tope = NULL;
    }
    return pila;
}

int apilar(Pila *pila, Cliente cliente) {
    // Cada atencion necesita un nodo propio, aunque el cliente ya este registrado.
    NodoPila *nuevo = malloc(sizeof(NodoPila));

    if (nuevo == NULL) {
        return 0;
    }

    // El nuevo queda arriba y apunta al que antes era el tope.
    nuevo->cliente = cliente;
    nuevo->siguiente = pila->tope;
    pila->tope = nuevo;
    return 1;
}

int desapilar(Pila *pila, Cliente *cliente) {
    NodoPila *retirado = pila->tope;

    if (retirado == NULL) {
        // No puedo sacar un registro de una pila vacia.
        return 0;
    }

    // Copio los datos para poder mostrarlos despues de liberar el nodo.
    *cliente = retirado->cliente;
    // El registro que estaba debajo pasa a ser el nuevo tope.
    pila->tope = retirado->siguiente;
    free(retirado);
    return 1;
}

int buscar_pila(Pila *pila, int codigo, Cliente *cliente) {
    NodoPila *actual = pila->tope;

    // Si el cliente vino varias veces, encuentro primero la mas reciente.
    // Recorro con actual para dejar el tope en su lugar.
    while (actual != NULL) {
        if (actual->cliente.codigo == codigo) {
            *cliente = actual->cliente;
            return 1;
        }
        actual = actual->siguiente;
    }
    return 0;
}

void mostrar_pila(Pila *pila) {
    NodoPila *actual = pila->tope;

    if (actual == NULL) {
        printf("El historial esta vacio.\n");
        return;
    }

    printf("\n--- HISTORIAL: MAS RECIENTE PRIMERO ---\n");
    // Mostrar recorre desde arriba, pero no va sacando los registros.
    while (actual != NULL) {
        printf("Codigo: %d | Nombre: %s | Equipo: %s\n",
               actual->cliente.codigo, actual->cliente.nombre,
               actual->cliente.equipo);
        actual = actual->siguiente;
    }
}

void liberar_pila(Pila *pila) {
    Cliente cliente;

    if (pila == NULL) {
        return;
    }

    // Cada llamada saca y libera un nodo; termino cuando desapilar devuelve 0.
    while (desapilar(pila, &cliente)) {
    }
    // Una vez vacia, libero tambien la cabecera de la pila.
    free(pila);
}
