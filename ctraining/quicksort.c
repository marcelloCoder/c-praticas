#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define STRING_TAMANHO 200
#define STRING_CONTADOR 10

typedef struct Registro{
    int chave;
    char strings[STRING_CONTADOR][STRING_TAMANHO];
    bool booleano;
    float valorFloat[4];
}Registro;

// Variáveis globais para métricas
long comparacao= 0; // Contador de comparações
long contadorCopias = 0;      // Contador de cópias

// Função para medir o tempo de execução
double get_cpu_time() {
    return (double)clock() / CLOCKS_PER_SEC;
}


int particiona(int *vetor, int inicio, int final){
    int esquerda, direita, pivo, aux;
    esquerda = inicio;
    direita = final;
    pivo = vetor[inicio];

    while (esquerda<direita){
       
        while (vetor[esquerda] <= pivo){
            comparacao++; // ADICIONA COMPARACAO
            esquerda++;
        }
        while (vetor[direita] > pivo){
            comparacao++; // ADICIONA COMPARACAO
            direita--;
        }
        if (esquerda < direita){
            aux = vetor[esquerda];
            vetor[esquerda] = vetor[direita];
            vetor[direita] = aux;
            contadorCopias = contadorCopias + 3; // Cada troca envolve 3 cópias (leitura e escrita)
        }
    }
    vetor[inicio] = vetor[direita];
    vetor[direita] = pivo;
    contadorCopias = contadorCopias + 3; // Troca final do pivô

    return direita;
}

void quickSort(int *vetor, int inicio, int fim){
    int pivo;

    if(fim > inicio){
        pivo =  particiona(vetor, inicio, fim);
        quickSort(vetor, inicio, pivo-1);
        quickSort(vetor, pivo+1, fim);
    }
}

int main(int argc, char const *argv[])
{
    int array[] = {34, 7, 23, 32, 5, 62, 32, 23, 12, 9, 55, 31, 78, 19, 4};
    int n = sizeof(array) / sizeof(array[0]);

    // Medir tempo inicial
    double inicio = get_cpu_time();

    quickSort(array, 0, n - 1);

     // Medir tempo final
    double fim = get_cpu_time();


    printf("\nARRAY ORDENADO\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("");

    // Exibir métricas
    printf("\n-METRICAS-\n");
    printf("NUMERO DE COMPARACOES: %ld\n", comparacao);
    printf("NUMERO DE COPIAS: %ld\n", contadorCopias);
    printf("TEMPO DE EXECUCAO: %.6f SEGUNDOS\n", fim - inicio);

    
    return 0;
}
