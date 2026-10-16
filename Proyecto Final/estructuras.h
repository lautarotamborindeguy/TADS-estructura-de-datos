#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

// Estas dos primeras lineas evitan declarar todo dos veces si se repite el include.
// Cada cliente lleva un equipo y se identifica con un codigo que no se repite.
typedef struct {
    int codigo;
    // Dejo una posicion para el '\0' que marca el final de cada texto.
    char nombre[60];
    char equipo[60];
} Cliente;

// Desde el main usamos estas funciones, sin tocar los enlaces de los nodos.
// Los campos internos de Lista, Cola y Pila se definen en sus archivos .c.
typedef struct lista Lista;
typedef struct cola Cola;
typedef struct pila Pila;

// Lista de clientes registrados.
Lista *crear_lista(void);
int insertar_cliente(Lista *lista, Cliente cliente);
// cliente recibe una copia del registro encontrado mediante su direccion.
int buscar_cliente(Lista *lista, int codigo, Cliente *cliente);
int eliminar_cliente(Lista *lista, int codigo);
void mostrar_lista(Lista *lista);
void liberar_lista(Lista *lista);

// En la cola se entra por el final y se sale por el inicio.
Cola *crear_cola(void);
int encolar(Cola *cola, Cliente cliente);
// Consultar mira el primero; desencolar lo saca y libera su nodo.
int consultar_primero(Cola *cola, Cliente *cliente);
int desencolar(Cola *cola, Cliente *cliente);
int buscar_cola(Cola *cola, int codigo, Cliente *cliente);
void mostrar_cola(Cola *cola);
void liberar_cola(Cola *cola);

// El historial es una pila: lo mas reciente queda arriba.
// Apilar se usa al terminar una atencion. Desapilar borra el ultimo registro.
Pila *crear_pila(void);
int apilar(Pila *pila, Cliente cliente);
int desapilar(Pila *pila, Cliente *cliente);
int buscar_pila(Pila *pila, int codigo, Cliente *cliente);
void mostrar_pila(Pila *pila);
void liberar_pila(Pila *pila);

// Las funciones int devuelven 1 si pudieron hacer la operacion y 0 si no.
// Las busquedas copian el dato al parametro cliente, sin sacar el nodo.
// Cada liberar recorre sus nodos y despues libera la estructura que los organiza.

#endif
