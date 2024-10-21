#include <stdio.h>

#define MAXTAM 10


int buscaSequencial(int vector[MAXTAM], int chave) {
    for (int i = 0; i < MAXTAM; i++) {
        if (vector[i] == chave) {
            return i;
        }
    }
    return -1;
}

int main() {
    int vetor[MAXTAM] = {10,12,11,6,7,8,3,4,2,1};
    int chave = 3; 

    int resultado = buscaSequencial(vetor, chave);  
    if (resultado != -1) {
        printf("Chave %d encontrada na posicao %d.\n", chave, resultado);
    } else {
        printf("Chave %d não encontrada.\n", chave);
    }

    return 0;
}
