#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

int main() {
    int v[1000], i, pares = 0;
    srand(time(NULL));

    for (i = 0; i < 1000; i++) v[i] = rand() % 1001;

    #pragma omp parallel for reduction(+:pares)
    for (i = 0; i < 1000; i++) {
        if (v[i] % 2 == 0) pares++;
    }

    printf("Quantidade de números pares: %d\n", pares);
    printf("Hello from process: %d\n", omp_get_thread_num());

    return 0;
}
