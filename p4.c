/*P4) Escreva um algoritmo que receba um vetor ordenado e um número extra e insira esse
número na sua posição correta no vetor ordenado, deslocando os outros números se necessário.
Quais são suas funções de custo e ordens de complexidade O e Ω?*/

/*Pior caso (O): No pior caso, o número deve ser inserido no início do vetor, o que requer
 que todos os elementos sejam deslocados. Nesse caso, o número de operações é proporcional ao tamanho do vetor,
  resultando em uma complexidade de O(n), onde n é o tamanho do vetor.
Melhor caso (Ω): No melhor caso, o número já é o maior do vetor e deve ser inserido no final,
 o que significa que não é necessário deslocar nenhum elemento. Nesse caso, a complexidade é Ω(1), 
 pois apenas uma inserção é feita sem deslocamentos.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXTAM 10

void insert(int vetor[], int numero)
{
    for (int i = 0; i < MAXTAM; i++)
    {
        if (vetor[i] == NULL)
        {
            vetor[i] = numero;
            printf("\nE");
        }
    }
}

void ordenado(int vetor[])
{
    int i, j, a;
    for (i = 0; i < MAXTAM; ++i)
    {
        for (j = i + 1; j < MAXTAM; ++j)
        {
            if (vetor[i] > vetor[j])
            {
                a = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = a;
                printf("\nORDENADO");
            }
        }
    }
}

void imprimir(int vetor[]){
    for (int i = 0; i < MAXTAM; i++)
    {
        printf("\nVETOR POSICAO %d VALOR %d", i, vetor[i]);
    }
    
}

int main(int argc, char const *argv[])
{
    int vetor[MAXTAM] = {11,21,24,31,33,39,40,60,66};
    int numero = 6;
    insert(vetor, numero);
    imprimir(vetor);
    ordenado(vetor);
    imprimir(vetor);
    return 0;
}
