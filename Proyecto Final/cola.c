#include <stdio.h>
#include <stdlib.h>
#include "estructuras.h"

// La cola tiene sus propios nodos, separados de los de la lista de clientes.
typedef struct nodo_cola {
    Cliente cliente;
    struct nodo_cola *siguiente;
} NodoCola;

struct cola {
    // inicio es el proximo a atender y final es el ultimo que llego.
    NodoCola *inicio;
    NodoCola *final;
};

Cola *crear_cola(void) {
    Cola *cola = malloc(sizeof(Cola));

    if (cola != NULL) {
        // Cuando no hay nadie esperando, los dos punteros quedan en NULL.
        cola->inicio = NULL;
        cola->final = NULL;
    }
    return cola;
}

int encolar(Cola *cola, Cliente cliente) {
    // Reservo un nodo por cada cliente que entra a esperar.
    NodoCola *nuevo = malloc(sizeof(NodoCola));

    if (nuevo == NULL) {
        return 0;
    }

    // Es una copia del cliente, no un puntero al nodo de la lista.
    nuevo->cliente = cliente;
    // El nuevo sera el ultimo, asi que no tiene otro nodo despues.
    nuevo->siguiente = NULL;

    if (cola->inicio == NULL) {
        // Si estaba vacia, el nuevo tambien pasa a ser el primero.
        cola->inicio = nuevo;
    } else {
        // Si ya habia gente, conecto el ultimo anterior con el nuevo.
        cola->final->siguiente = nuevo;
    }
    // En los dos casos el nuevo termina siendo el ultimo de la cola.
    cola->final = nuevo;
    return 1;
}

int consultar_primero(Cola *cola, Cliente *cliente) {
    if (cola->inicio == NULL) {
        return 0;
    }

    // Solo copio los datos: esta funcion no modifica ni libera la cola.
    *cliente = cola->inicio->cliente;
    return 1;
}

int desencolar(Cola *cola, Cliente *cliente) {
    // Guardo el primero porque su nodo se va a liberar al final.
    NodoCola *retirado = cola->inicio;

    if (retirado == NULL) {
        return 0;
    }

    // Devuelvo los datos antes de liberar y dejo al segundo como nuevo primero.
    *cliente = retirado->cliente;
    cola->inicio = retirado->siguiente;

    // Al sacar al unico cliente, el final tampoco puede seguir apuntandolo.
    if (cola->inicio == NULL) {
        cola->final = NULL;
    }

    // El nodo salio de la cola y ya no se necesita.
    free(retirado);
    return 1;
}

int buscar_cola(Cola *cola, int codigo, Cliente *cliente) {
    NodoCola *actual = cola->inicio;

    // Buscar recorre la espera, pero no cambia el orden de llegada.
    while (actual != NULL) {
        if (actual->cliente.codigo == codigo) {
            *cliente = actual->cliente;
            return 1;
        }
        actual = actual->siguiente;
    }
    return 0;
}

void mostrar_cola(Cola *cola) {
    NodoCola *actual = cola->inicio;
    int posicion = 1;

    if (actual == NULL) {
        printf("La cola esta vacia.\n");
        return;
    }

    printf("\n--- COLA: PRIMERO AL ULTIMO ---\n");
    // La posicion 1 corresponde al proximo cliente que sera atendido.
    while (actual != NULL) {
        printf("%d. Codigo: %d | Nombre: %s | Equipo: %s\n",
               posicion, actual->cliente.codigo, actual->cliente.nombre,
               actual->cliente.equipo);
        posicion++;
        actual = actual->siguiente;
    }
}

void liberar_cola(Cola *cola) {
    Cliente cliente;

    if (cola == NULL) {
        return;
    }

    // Desencolar ya libera cada nodo, asi aprovecho la misma funcion.
    while (desencolar(cola, &cliente)) {
        // Repito hasta que la cola quede vacia y desencolar devuelva 0.
    }
    // Por ultimo libero la cabecera que guardaba inicio y final.
    free(cola);
}
