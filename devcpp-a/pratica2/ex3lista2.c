#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

#define n 10

void fillAleatory(int vet[]){
	int i;
	for(i = 0; i < n; i++){
		vet[i] = rand() % n;
		printf("%d\n", vet[i]);
	}
}

void searchSeq(int vet[], int key){
	int i = 0;
	while(key != vet[i]){
		i = i + 1;
	}
	printf("Chave %d encontrada na posicao %d\n", vet[i], i);	
}

void searchBin(int vetor[], int key){
	int dir,esq,meio;
	bool encontrado;
	dir = n - 1;
	esq = 0;
	encontrado = false;
	
	while(esq <= dir && encontrado == false){
		meio = (esq + dir) / 2;
		if(vetor[meio] == key){
			encontrado = true;
			printf("\nElemento %d encontrado na posição %d", key, meio);;
		}else if(key < vetor[meio]){
			dir = meio - 1;
		}else{	
			esq = meio + 1;
		}
		printf("\nIMPRIMINDO BIN meio %d", meio);
		
		if (!encontrado) {
        	printf("\nElemento %d nao encontrado", key);
    	}
	}	
}

int main(){
	int vetor[n];
	int key = 2;
	fillAleatory(vetor);
	searchSeq(vetor, key);
	searchBin(vetor, key);
	
	int i;
	for(i = 0; i < n; i++){
		printf("\nlista %d", vetor[i]);
	}
	
	return 0;
}
