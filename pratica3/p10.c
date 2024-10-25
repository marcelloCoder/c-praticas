/*P10) No método InsertionSort, a cada passo, o novo elemento é utilizado para que seja
inserido na sequência já ordenada. Proponha uma abordagem mais interessante que a busca
sequencial para encontrar o local correto para inserção.*/

#include <stdio.h>

int buscaBinaria(int array[], int item, int baixo, int alto) {
    if (alto <= baixo) {
        return (item > array[baixo]) ? (baixo + 1) : baixo;
    }

    int meio = (baixo + alto) / 2;

    if (item == array[meio]) {
        return meio + 1;
    }

    if (item > array[meio]) {
        return buscaBinaria(array, item, meio + 1, alto);
    }

    return buscaBinaria(array, item, baixo, meio - 1);
}

void insertionSortComBuscaBinaria(int array[], int n) {
    int i, j, chave, posicao;

    for (i = 1; i < n; i++) {
        chave = array[i];
        
        posicao = buscaBinaria(array, chave, 0, i - 1);

        for (j = i; j > posicao; j--) {
            array[j] = array[j - 1];
        }

        array[posicao] = chave;
    }
}

int main() {
    int array[] = {2, 3, 1, 5, 4, 8, 1, 9, 2, 0};
    int n = sizeof(array) / sizeof(array[0]);

    insertionSortComBuscaBinaria(array, n);

    printf("Vetor ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}
