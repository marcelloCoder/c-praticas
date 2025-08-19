#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
	clock_t inicio, fim;
    double tempoGasto;
    int i;
    
    printf("argc: %d\n", argc);

    if (argc > 1)
    {
        printf("argv[0]: %s\n",argv[0]);	
		printf("argv[1]: %s\n",argv[1]);
    }
    
    inicio = clock(); // Captura o tempo inicial

    // Código que você quer medir (ex: um loop)
    for (i = 0; i < 10000000; i++) {
        // Operação qualquer
    }

    fim = clock(); // Captura o tempo final
    tempoGasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

	printf("Tempo gasto = %f", tempoGasto);
    return 0;
}
