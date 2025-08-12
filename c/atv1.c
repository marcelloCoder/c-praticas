#include <stdio.h>

int main() {
    int v[1000], i, soma_seq = 0, soma_par = 0;

    for (i = 0; i < 1000; i++) v[i] = i + 1;

    // Soma sequencial
    for (i = 0; i < 1000; i++) soma_seq += v[i];

    // Soma paralela
    #pragma omp parallel for
    for (i = 0; i < 1000; i++) {
        #pragma omp atomic
        soma_par += v[i];
    }

    printf("Soma sequencial: %d\n", soma_seq);
    printf("Soma paralela (com atomic): %d\n", soma_par);
    return 0;
}
