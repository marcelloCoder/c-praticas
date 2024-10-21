/*P11) Crie um programa que dado uma string, coloque as letras dela em ordem crescente
pelo algoritmo bubble sort.*/
#include <stdio.h>
#include <string.h>

void bubbleSort(char str[]) {
    int n = strlen(str);
    int i, j;
    char temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (str[j] > str[j + 1]) {
                temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
}

int main() {
    char str[100];

    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);
    
    str[strcspn(str, "\n")] = 0;

    bubbleSort(str);
    
    printf("String ordenada: %s\n", str);
    
    return 0;
}
