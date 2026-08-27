#include <stdio.h>

#include <stdlib.h>

 

int main() {

    int cantAlunos;

    float soma = 0;

    float media;

 

    // 1. Perguntar quantidade de alunos

    printf("Quantos alunos existem na turma? ");

    scanf("%d", &cantAlunos);

 

    // 2. Criar array dinamicamente

    float *notas = malloc(cantAlunos * sizeof(float));

 

    // 3. Verificar se a alocacao funcionou

    if (notas == NULL) {

        printf("Erro ao alocar memoria.\n");

        return 1;

    }

 

    // 4. Ler as notas

    for (int i = 0; i < cantAlunos; i++) {

        printf("Digite a nota do aluno %d: ", i + 1);

        scanf("%f", &notas[i]);

 

        soma += notas[i];

    }

 

    // 5. Calcular e mostrar a media

    media = soma / cantAlunos;

 

    printf("Cantidade de alumnos: %d\n", cantAlunos);

    printf("Media da turma: %.2f\n", media);

 

    // 6. Liberar memoria e anular o ponteiro

    free(notas);

    notas = NULL;

 

    return 0;

}




#include <stdio.h>

#include <stdlib.h>

 

int main() {

 

    int cantidad = 1;

    char continuar;

 

    // Alocar memoria para una nota

    float *notas = malloc(cantidad * sizeof(float));

 

    // Verificar si malloc funciono

    if (notas == NULL) {

        printf("Erro ao alocar memoria.\n");

        return 1;

    }

 

    do {

 

        // Pedir la nota al usuario

        printf("Digite a nota do aluno %d: ", cantidad);

        scanf("%f", &notas[cantidad - 1]);

 

        // Preguntar si quiere agregar otra

        printf("Deseja cadastrar outra nota? (s/n): ");

        scanf(" %c", &continuar);

 

        if (continuar == 's' || continuar == 'S') {

 

            cantidad++;

 

            // Aumentar el espacio de memoria

            float *temp = realloc(notas, cantidad * sizeof(float));

 

            // Verificar si realloc funciono

            if (temp == NULL) {

                printf("Erro ao realocar memoria.\n");

 

                free(notas);

                notas = NULL;

 

                return 1;

            }

 

            notas = temp;

        }

 

    } while (continuar == 's' || continuar == 'S');

 

    // Mostrar las notas registradas

    printf("\nNotas cadastradas:\n");

 

    for (int i = 0; i < cantidad; i++) {

        printf("Aluno %d: %.2f\n", i + 1, notas[i]);

    }

 

    // Liberar la memoria

    free(notas);

 

    // Anular el puntero

    notas = NULL;

 

    return 0;

}