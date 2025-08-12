#include <stdio.h>
#include <omp.h>

int main() {
    int v[1000], i, soma = 0;
    double t1, t2;

    for (i = 0; i < 1000; i++) v[i] = i + 1;

    t1 = omp_get_wtime();
    #pragma omp parallel for reduction(+:soma)
    for (i = 0; i < 1000; i++) {
        soma += v[i];
    }
    t2 = omp_get_wtime();

    printf("Soma com reduction: %d | Tempo: %f s\n", soma, t2 - t1);
    return 0;
}
