/*1. Crie um programa que calcula a soma dos elementos de um vetor e, em paralelo, 
imprime os elementos pares desse vetor. 
Use nowait para que a impressão dos pares não espere o término da soma.*/
#include <stdio.h>
#include <omp.h>

int main() {
    int vetor[100];
    int soma = 0;
    int i;

    // Inicializa o vetor
    for (i = 0; i < 100; i++) {
        vetor[i] = i + 1;
    }

    #pragma omp parallel
    {
        #pragma omp for reduction(+:soma) nowait
        for (i = 0; i < 100; i++) {
            soma += vetor[i];
        }

        #pragma omp for nowait
        for (i = 0; i < 100; i++) {
            if (vetor[i] % 2 == 0) {
                printf("Par: %d\n", vetor[i]);
            }
        }
    }

    printf("Soma total: %d\n", soma);
    return 0;
}

