#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define STRING_TAMANHO 200
#define STRING_CONTADOR 10

typedef struct Registro{
    int chave;
    char strings[STRING_CONTADOR][STRING_TAMANHO];
    bool booleano;
    float valorFloat[4];
}Registro;


int particiona(int *vetor, int inicio, int final){
    int esquerda, direita, pivo, aux;
    esquerda = inicio;
    direita = final;
    pivo = vetor[inicio];

    while (esquerda<direita){
       
        while (vetor[esquerda] <= pivo){
            esquerda++;
        }
        while (vetor[direita] > pivo){
            direita--;
        }
        if (esquerda < direita){
            aux = vetor[esquerda];
            vetor[esquerda] = vetor[direita];
            vetor[direita] = aux;
        }
    }
    vetor[inicio] = vetor[direita];
    vetor[direita] = pivo;

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

    quickSort(array, 0, n - 1);

    printf("\nARRAY ORDENADO\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d , ", array[i]);
    }
    
    return 0;
}
