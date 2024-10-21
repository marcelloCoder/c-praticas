/*P12) Faça um programa que leia n nomes e ordene-os pelo tamanho utilizando o algoritmo
selection sort.*/

#include <stdio.h>
#include <string.h>

void selectionSort(char nomes[][100], int n) {
    int i, j, minIndex;
    char temp[100];

    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (strlen(nomes[j]) < strlen(nomes[minIndex])) {
                minIndex = j;
            }
        }
        strcpy(temp, nomes[i]);
        strcpy(nomes[i], nomes[minIndex]);
        strcpy(nomes[minIndex], temp);
    }
}

int main() {
    int n;

    printf("Quantos nomes deseja inserir? ");
    scanf("%d", &n);
    getchar();

    char nomes[n][100];

    for (int i = 0; i < n; i++) {
        printf("Digite o nome %d: ", i + 1);
        fgets(nomes[i], sizeof(nomes[i]), stdin);
        nomes[i][strcspn(nomes[i], "\n")] = 0; 
    }

    selectionSort(nomes, n);

    printf("\nNomes ordenados pelo tamanho:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", nomes[i]);
    }

    return 0;
}
