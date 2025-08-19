/*P8) Implemente o algoritmo de ordenação por inserção visto em aula e execute-o para o
seguinte vetor?
2 3 1 5 4 8 1 9 2 0*/
#include <stdio.h>

void insertionSort(int array[], int n)
{
    int i, j, chave;

    for (i = 1; i < n; i++)
    {
        chave = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > chave)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = chave;
    }
}

int main()
{

    int array[] = {2, 3, 1, 5, 4, 8, 1, 9, 2, 0};
    int n = sizeof(array) / sizeof(array[0]);

    insertionSort(array, n);

    printf("Vetor ordenado:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }

    return 0;
}
