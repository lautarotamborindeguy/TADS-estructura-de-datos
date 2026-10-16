#include <stdio.h>
#include <stdlib.h>
#include "estructuras.h"

// Cada nodo guarda un cliente y la direccion del siguiente nodo.
// siguiente vale NULL en el ultimo, porque ya no hay otro despues.
typedef struct nodo_lista {
    Cliente cliente;
    struct nodo_lista *siguiente;
} NodoLista;

struct lista {
    // Con conocer el primero puedo llegar a todos los demas.
    NodoLista *inicio;
};

Lista *crear_lista(void) {
    // Primero reservo la cabecera. Los nodos se crean al registrar clientes.
    Lista *lista = malloc(sizeof(Lista));

    if (lista != NULL) {
        // Al empezar no hay ningun cliente, por eso el inicio esta vacio.
        lista->inicio = NULL;
    }
    return lista;
}

int insertar_cliente(Lista *lista, Cliente cliente) {
    Cliente encontrado;
    NodoLista *nuevo;

    // Reviso el codigo antes de reservar memoria para evitar duplicados.
    if (buscar_cliente(lista, cliente.codigo, &encontrado)) {
        return 0;
    }

    nuevo = malloc(sizeof(NodoLista));
    if (nuevo == NULL) {
        // Si malloc falla, salgo sin cambiar los enlaces de la lista.
        return 0;
    }

    // Inserto al principio, asi no necesito recorrer toda la lista.
    nuevo->cliente = cliente;
    // Primero conecto el nuevo con el inicio anterior y despues cambio el inicio.
    nuevo->siguiente = lista->inicio;
    lista->inicio = nuevo;
    return 1;
}

int buscar_cliente(Lista *lista, int codigo, Cliente *cliente) {
    // actual sirve para recorrer sin mover el inicio de la lista.
    NodoLista *actual = lista->inicio;

    while (actual != NULL) {
        if (actual->cliente.codigo == codigo) {
            // Con *cliente escribo en la variable cuya direccion recibio la funcion.
            *cliente = actual->cliente;
            return 1;
        }
        actual = actual->siguiente;
    }
    return 0;
}

int eliminar_cliente(Lista *lista, int codigo) {
    NodoLista *actual = lista->inicio;
    NodoLista *anterior = NULL;

    // Guardo tambien el anterior para poder unirlo al nodo que venga despues.
    while (actual != NULL && actual->cliente.codigo != codigo) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == NULL) {
        // Llegue al final sin encontrar ese codigo.
        return 0;
    }

    // Si era el primero, cambia el inicio; en otro caso uno sus vecinos.
    if (anterior == NULL) {
        lista->inicio = actual->siguiente;
    } else {
        anterior->siguiente = actual->siguiente;
    }

    // Los enlaces ya lo saltan, asi que ahora puedo liberar su memoria.
    free(actual);
    return 1;
}

void mostrar_lista(Lista *lista) {
    NodoLista *actual = lista->inicio;

    if (actual == NULL) {
        printf("No hay clientes registrados.\n");
        return;
    }

    printf("\n--- CLIENTES REGISTRADOS ---\n");
    // Como inserto al principio, se muestran primero los ultimos registrados.
    while (actual != NULL) {
        printf("Codigo: %d | Nombre: %s | Equipo: %s\n",
               actual->cliente.codigo, actual->cliente.nombre,
               actual->cliente.equipo);
        actual = actual->siguiente;
    }
}

void liberar_lista(Lista *lista) {
    NodoLista *actual;
    NodoLista *siguiente;

    if (lista == NULL) {
        // Esto tambien permite limpiar si hubo un fallo al iniciar el sistema.
        return;
    }

    actual = lista->inicio;
    while (actual != NULL) {
        // Guardo el siguiente antes de liberar el nodo actual.
        siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
    // Ademas de los nodos, la cabecera tambien se habia creado con malloc.
    free(lista);
}
