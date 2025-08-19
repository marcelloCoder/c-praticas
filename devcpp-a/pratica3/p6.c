// P6) Escreva um algoritmo que ordene de maneira descrescente um determinado vetor (do
// maior para o menor).

#include <stdio.h>

void ordenarDecrescente(int vetor[], int n)
{
    int i, j, maxIndex, temp;

    for (i = 0; i < n - 1; i++)
    {
        maxIndex = i;

        for (j = i + 1; j < n; j++)
        {
            if (vetor[j] > vetor[maxIndex])
            {
                maxIndex = j;
            }
        }

        temp = vetor[i];
        vetor[i] = vetor[maxIndex];
        vetor[maxIndex] = temp;
    }
}

int main()
{
    int vetor[] = {12, 45, 23, 89, 10, 67};
    int n = sizeof(vetor) / sizeof(vetor[0]);

    ordenarDecrescente(vetor, n);

    printf("Vetor ordenado de forma decrescente:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vetor[i]);
    }

    return 0;
}
