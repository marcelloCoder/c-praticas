#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Algoritmo 1: Soma dos números de 0 a n
void algoritmo1(int n) {
    int soma = 0;
    for (int i = 0; i <= n; i++) {
        soma += i;
    }
}

// Algoritmo 2: Soma de pares i, j
void algoritmo2(int n) {
    int soma = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < i; j++) {
            soma += 1;
        }
    }
}

// Algoritmo 3: Fórmula fechada para a soma de 0 a n
void algoritmo3(int n) {
    int soma = n * (n + 1) / 2;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <valor_de_n>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);

    clock_t inicio, fim;
    unsigned long int tempo;

    // Algoritmo 1
    inicio = clock();
    algoritmo1(n);
    fim = clock();
    tempo = (fim - inicio) * 1000 / CLOCKS_PER_SEC;
    printf("N = %d | Alg1 (ms): %lu\n", n, tempo);

    // Algoritmo 2
    inicio = clock();
    algoritmo2(n);
    fim = clock();
    tempo = (fim - inicio) * 1000 / CLOCKS_PER_SEC;
    printf("N = %d | Alg2 (ms): %lu\n", n, tempo);

    // Algoritmo 3
    inicio = clock();
    algoritmo3(n);
    fim = clock();
    tempo = (fim - inicio) * 1000 / CLOCKS_PER_SEC;
    printf("N = %d | Alg3 (ms): %lu\n", n, tempo);

    return 0;
}
