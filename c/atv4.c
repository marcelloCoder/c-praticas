#include <stdio.h>
#include <omp.h>

int main() {
    int v[1000], i;

    #pragma omp parallel for
    for (i = 0; i < 1000; i++) {
        v[i] = i * i;
    }

    printf("Primeiros 10 elementos:\n");
    for (i = 0; i < 10; i++) {
        printf("v[%d] = %d\n", i, v[i]);
    }

    return 0;
}
