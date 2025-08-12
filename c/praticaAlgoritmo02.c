#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void algoritmo2(int n) {
    int soma = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < i; j++) {
            soma += 1;
        }
    }
}

int main(int argc, char const *argv[])
{

    printf("argc: %d\n", argc);

    if (argc > 1)
    {
        printf("argv[0]: %s\n",argv[0]);	
		printf("argv[1]: %s\n",argv[1]);
    }

    clock_t inicio, fim;
    unsigned long int tempo;
    inicio = clock();
    int n =100000;
    algoritmo2(n);
    fim = clock();
    tempo = (fim - inicio)*n/CLOCKS_PER_SEC;
	printf("tempo: %lu milissegundos\n",tempo);

    return 0;
}
