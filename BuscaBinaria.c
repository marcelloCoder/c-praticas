#include <stdio.h>

#define MAXTAM 20


int buscaBinaria(int vetor[], int esquerda, int direita, int chave)
{
    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        if (vetor[meio] == chave)
            return meio;

        if (vetor[meio] < chave)
            esquerda = meio + 1;

        else
            direita = meio - 1;
    }
    return -1;
}

int main() {
    int vetor[] = {1,2,4,6,7,8,10,10,12,15,17,19,20,21};
    int meio = sizeof(vetor) / sizeof(vetor[0]);
    int chave = 19; 

    int resultado = buscaBinaria(vetor, 0, meio-1, chave);  
    if (resultado == -1) {
        printf("Element is not present in arrayo\n\n");
    } else {
        printf("Element is present at index %d\n\n", resultado);
    }

    return 0;
}
