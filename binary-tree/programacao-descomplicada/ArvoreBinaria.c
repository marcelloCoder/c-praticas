#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"

struct NO {
    int info;
    struct NO* esq;
    struct NO* dir;
};

ArvoreBinaria* criaArvoreBinaria() {
    ArvoreBinaria* raiz = (ArvoreBinaria*)malloc(sizeof(ArvoreBinaria));
    if(raiz != NULL){
        *raiz = NULL;
    }
    return raiz;
}

void liberaNO(struct NO* no) {
    if(no == NULL){
        return;
    }
    liberaNO(no->esq);
    liberaNO(no->dir);  
    free(no);
    no = NULL;
}

void liberaArvoreBinaria(ArvoreBinaria* raiz) {
    if(raiz == NULL){
        return;
    }
    liberaArvoreBinaria(*raiz); 
    free(raiz);
}

int estaVaziaArvoreBinaria(ArvoreBinaria* raiz) {
    if(raiz == NULL){
        return 1;
    }
    if(*raiz == NULL){
        return 1;
    }
    return 0;
}

int alturaArvoreBinaria(ArvoreBinaria* raiz) {
    if(raiz == NULL || *raiz == NULL){
        return 0;
    }
    int alturaEsq = alturaArvoreBinaria(&((*raiz)->esq));
    int alturaDir = alturaArvoreBinaria(&((*raiz)->dir));
    if(alturaEsq > alturaDir){
        return alturaEsq + 1;
    } else {
        return alturaDir + 1;
    }
}

int totalNOArvoreBinaria(ArvoreBinaria* raiz) {
    if(raiz == NULL || *raiz == NULL){
        return 0;
    }
    int totalEsq = totalNOArvoreBinaria(&((*raiz)->esq));
    int totalDir = totalNOArvoreBinaria(&((*raiz)->dir));
    return totalEsq + totalDir + 1;
}

int main() {
    ArvoreBinaria* raiz;
    *raiz = criaArvoreBinaria();
    liberaArvoreBinaria(raiz);
    int x = estaVaziaArvoreBinaria(raiz);
    if(estaVaziaArvoreBinaria(raiz)){
        printf("A arvore esta vazia!\n");
    } else {
        printf("A arvore nao esta vazia!\n");
    }

    x = alturaArvoreBinaria(raiz);
    printf("Altura da arvore: %d\n", x);
    x = totalNOArvoreBinaria(raiz);
    printf("Total de nos na arvore: %d\n", x);

    return 0;
}
