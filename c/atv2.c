#include <stdio.h>
#include <omp.h>

int main() {
    int v[1000], i, soma_seq = 0, soma_par = 0;
    double t1, t2;

    for (i = 0; i < 1000; i++) v[i] = i + 1;

    // Soma sequencial
    t1 = omp_get_wtime();
    for (i = 0; i < 1000; i++) soma_seq += v[i];
    t2 = omp_get_wtime();
    printf("Soma sequencial: %d | Tempo: %f s\n", soma_seq, t2 - t1);

    // Soma paralela
    soma_par = 0;
    t1 = omp_get_wtime();
    #pragma omp parallel for
    for (i = 0; i < 1000; i++) {
        #pragma omp atomic
        soma_par += v[i];
    }
    t2 = omp_get_wtime();
    printf("Soma paralela (com atomic): %d | Tempo: %f s\n", soma_par, t2 - t1);

    return 0;
}
