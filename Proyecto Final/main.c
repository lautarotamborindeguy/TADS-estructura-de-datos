/*
   Asistencia tecnica - lista, cola y pila.
   Para compilar dentro de esta carpeta:
   gcc -std=c99 -Wall -Wextra main.c lista.c cola.c pila.c -o asistencia

   La lista guarda los clientes, la cola ordena la espera y la pila
   guarda las atenciones de la mas reciente a la mas antigua.
   Los datos duran mientras el programa esta abierto.
*/

#include <stdio.h>
#include "estructuras.h"

int leer_numero(char mensaje[], int minimo, int maximo, int *numero) {
    int valor;
    int resultado;
    int caracter;
    int resto_valido;

    // Repito la pregunta hasta recibir un numero valido o terminar la entrada.
    while (1) {
        printf("%s", mensaje);

        // Leo hasta 6 caracteres para no desbordar el int con un numero enorme.
        resultado = scanf("%6d", &valor);
        // EOF significa que ya no hay datos para leer desde la terminal.
        if (resultado == EOF) {
            return 0;
        }

        // Reviso el resto: entradas como 2abc o 1.5 tampoco son opciones validas.
        resto_valido = 1;
        while ((caracter = getchar()) != '\n' && caracter != EOF) {
            // Los espacios al final se permiten; las letras y otros signos no.
            if (caracter != ' ' && caracter != '\t' && caracter != '\r') {
                resto_valido = 0;
            }
        }

        if (resultado == 1 && resto_valido && valor >= minimo && valor <= maximo) {
            // numero apunta a la variable del main, por eso uso * para cambiarla.
            *numero = valor;
            return 1;
        }

        printf("Entrada invalida. Ingresa un entero entre %d y %d.\n",
               minimo, maximo);
        if (caracter == EOF) {
            return 0;
        }
    }
}

int leer_texto(char mensaje[], char texto[], int tamano) {
    int caracter;
    int indice;
    int demasiado_largo;
    int tiene_texto;

    while (1) {
        printf("%s", mensaje);
        indice = 0;
        demasiado_largo = 0;
        tiene_texto = 0;

        // Leo la linea completa, incluso si escriben mas de lo que entra.
        while ((caracter = getchar()) != '\n' && caracter != EOF) {
            // Dejo la ultima posicion libre para el caracter de fin de cadena.
            if (indice < tamano - 1) {
                texto[indice] = (char) caracter;
                indice++;
            } else {
                demasiado_largo = 1;
            }

            // Un campo formado solo por espacios tambien se considera vacio.
            if (caracter != ' ' && caracter != '\t' && caracter != '\r') {
                tiene_texto = 1;
            }
        }
        // Sin este final, printf no sabria donde termina el texto.
        texto[indice] = '\0';

        if (!demasiado_largo && tiene_texto) {
            return 1;
        }
        if (caracter == EOF) {
            return 0;
        }
        printf("Ingresa de 1 a %d caracteres, sin dejar el campo vacio.\n",
               tamano - 1);
    }
}

void mostrar_cliente(Cliente cliente) {
    printf("Codigo: %d | Nombre: %s | Equipo: %s\n",
           cliente.codigo, cliente.nombre, cliente.equipo);
}

int main(void) {
    // Cada funcion devuelve la direccion de una estructura inicialmente vacia.
    Lista *clientes = crear_lista();
    Cola *espera = crear_cola();
    Pila *historial = crear_pila();
    // Esta variable temporal recibe los datos al leer, buscar o retirar un cliente.
    Cliente cliente;
    int opcion = -1;
    int codigo;

    // Antes de usar las estructuras reviso que las tres se hayan podido crear.
    if (clientes == NULL || espera == NULL || historial == NULL) {
        printf("No se pudo iniciar el sistema por falta de memoria.\n");
        // Alguna de las otras estructuras pudo haberse creado bien.
        liberar_lista(clientes);
        liberar_cola(espera);
        liberar_pila(historial);
        return 1;
    }

    // El menu se vuelve a mostrar despues de cada operacion hasta elegir 0.
    do {
        printf("\n===== ASISTENCIA TECNICA =====\n");
        printf("\nCLIENTES (LISTA)\n");
        printf("1. Registrar cliente\n");
        printf("2. Listar clientes\n");
        printf("3. Buscar cliente por codigo\n");
        printf("4. Eliminar registro del cliente\n");
        printf("\nESPERA (COLA)\n");
        printf("5. Agregar cliente a la cola\n");
        printf("6. Mostrar cola de espera\n");
        printf("7. Buscar cliente en la cola\n");
        printf("8. Atender al siguiente cliente\n");
        printf("9. Cancelar la espera del primer cliente\n");
        printf("\nATENCIONES (PILA)\n");
        printf("10. Mostrar historial de atenciones\n");
        printf("11. Buscar cliente en el historial\n");
        printf("12. Borrar el ultimo registro del historial\n");
        printf("\n0. Salir\n");

        // Si termina la entrada, salgo por la misma limpieza que la opcion 0.
        if (!leer_numero("Elige una opcion: ", 0, 12, &opcion)) {
            opcion = 0;
        }

        // Cada case llama al TAD que corresponde; aqui no cambio enlaces de nodos.
        switch (opcion) {
            case 1:
                // Pido primero el codigo para revisar si el cliente ya existe.
                if (!leer_numero("Codigo del cliente (1 a 999999): ",
                                1, 999999, &codigo)) {
                    opcion = 0;
                    break;
                }
                // &cliente pasa su direccion para que la busqueda pueda copiar el dato.
                if (buscar_cliente(clientes, codigo, &cliente)) {
                    printf("Ya existe un cliente con ese codigo.\n");
                    break;
                }

                // Cargo los campos de la variable temporal antes de insertarla.
                cliente.codigo = codigo;
                if (!leer_texto("Nombre: ", cliente.nombre, sizeof(cliente.nombre)) ||
                    !leer_texto("Equipo: ", cliente.equipo, sizeof(cliente.equipo))) {
                    opcion = 0;
                    break;
                }

                // La lista reserva el nodo y guarda una copia del cliente.
                if (insertar_cliente(clientes, cliente)) {
                    printf("Cliente registrado.\n");
                } else {
                    printf("No se pudo registrar por falta de memoria.\n");
                }
                break;

            case 2:
                mostrar_lista(clientes);
                break;

            case 3:
                if (!leer_numero("Codigo: ", 1, 999999, &codigo)) {
                    opcion = 0;
                    break;
                }
                if (buscar_cliente(clientes, codigo, &cliente)) {
                    mostrar_cliente(cliente);
                } else {
                    printf("Cliente no encontrado.\n");
                }
                break;

            case 4:
                if (!leer_numero("Codigo para eliminar: ", 1, 999999, &codigo)) {
                    opcion = 0;
                    break;
                }
                // Mantengo el registro mientras el cliente este esperando atencion.
                if (buscar_cola(espera, codigo, &cliente)) {
                    printf("Ese cliente sigue en la cola. Atiende o cancela su espera primero.\n");
                    break;
                }

                // El historial conserva su copia aunque se borre el cliente.
                if (eliminar_cliente(clientes, codigo)) {
                    printf("Registro eliminado.\n");
                } else {
                    printf("Cliente no encontrado.\n");
                }
                break;

            case 5:
                if (!leer_numero("Codigo para entrar en la cola: ", 1, 999999, &codigo)) {
                    opcion = 0;
                    break;
                }
                // Evito que un mismo cliente ocupe dos lugares en la espera.
                if (buscar_cola(espera, codigo, &cliente)) {
                    printf("Ese cliente ya esta en la cola.\n");
                    break;
                }
                // Busco sus datos en la lista para no tener que pedirlos de nuevo.
                if (!buscar_cliente(clientes, codigo, &cliente)) {
                    printf("Registra al cliente antes de agregarlo a la cola.\n");
                    break;
                }

                if (encolar(espera, cliente)) {
                    printf("Cliente agregado al final de la cola.\n");
                } else {
                    printf("No se pudo agregar a la cola por falta de memoria.\n");
                }
                break;

            case 6:
                mostrar_cola(espera);
                break;

            case 7:
                if (!leer_numero("Codigo para buscar en la cola: ", 1, 999999, &codigo)) {
                    opcion = 0;
                    break;
                }
                if (buscar_cola(espera, codigo, &cliente)) {
                    mostrar_cliente(cliente);
                } else {
                    printf("Cliente no encontrado en la cola.\n");
                }
                break;

            case 8:
                // Miro al primero sin sacarlo todavia de la cola.
                if (!consultar_primero(espera, &cliente)) {
                    printf("La cola esta vacia.\n");
                    break;
                }

                // Primero guardo el historial. Si falla malloc, sigue en espera.
                if (!apilar(historial, cliente)) {
                    printf("Falta memoria. El cliente sigue en la cola.\n");
                    break;
                }
                // Ya guarde la atencion en la pila; ahora lo retiro de la espera.
                desencolar(espera, &cliente);
                printf("Atencion finalizada:\n");
                mostrar_cliente(cliente);
                break;

            case 9:
                // Cancelar tambien saca solo al primero, manteniendo FIFO.
                if (desencolar(espera, &cliente)) {
                    printf("Espera cancelada:\n");
                    mostrar_cliente(cliente);
                } else {
                    printf("La cola esta vacia.\n");
                }
                break;

            case 10:
                mostrar_pila(historial);
                break;

            case 11:
                if (!leer_numero("Codigo para buscar en el historial: ", 1, 999999, &codigo)) {
                    opcion = 0;
                    break;
                }
                // La busqueda empieza en el tope, donde esta lo mas reciente.
                if (buscar_pila(historial, codigo, &cliente)) {
                    printf("Atencion mas reciente de ese cliente:\n");
                    mostrar_cliente(cliente);
                } else {
                    printf("Cliente no encontrado en el historial.\n");
                }
                break;

            case 12:
                // Esto borra el registro del tope, no vuelve a ponerlo en espera.
                if (desapilar(historial, &cliente)) {
                    printf("Ultimo registro borrado:\n");
                    mostrar_cliente(cliente);
                } else {
                    printf("El historial esta vacio.\n");
                }
                break;

            case 0:
                break;
        }
    } while (opcion != 0);

    // Tambien llego aqui si se termina la entrada mientras estoy usando el menu.
    // Cada estructura libera sus nodos y despues su propia cabecera.
    liberar_cola(espera);
    liberar_pila(historial);
    liberar_lista(clientes);
    printf("Sistema cerrado.\n");
    return 0;
}
