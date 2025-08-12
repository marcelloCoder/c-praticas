#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void algoritmo3(int n) {
    int soma = n * (n + 1) / 2;
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
    int n =100000000;
    algoritmo3(n);
    fim = clock();
    tempo = (fim - inicio)*n/CLOCKS_PER_SEC;
	printf("tempo: %lu milissegundos\n",tempo);

    return 0;
}
