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

void preOrdemArvoreBinaria(ArvoreBinaria* raiz) {
    if(raiz == NULL || *raiz == NULL){
        return;
    }
    if(*raiz == NULL){
        printf("%d ", (*raiz)->info);
        preOrdemArvoreBinaria(&((*raiz)->esq));
        preOrdemArvoreBinaria(&((*raiz)->dir));;
    }
}

void emOrdemArvoreBinaria(ArvoreBinaria* raiz) {
    if(raiz == NULL || *raiz == NULL){
        return;
    }
    if(*raiz != NULL){
        emOrdemArvoreBinaria(&((*raiz)->esq));
        printf("%d ", (*raiz)->info);
        emOrdemArvoreBinaria(&((*raiz)->dir));;
    }
}

void posOrdemArvoreBinaria(ArvoreBinaria* raiz) {
    if(raiz == NULL || *raiz == NULL){
        return;
    }
    if(*raiz != NULL){
        posOrdemArvoreBinaria(&((*raiz)->esq));
        posOrdemArvoreBinaria(&((*raiz)->dir));;
        printf("%d ", (*raiz)->info);
    }
}

int insereArvoreBinaria(ArvoreBinaria* raiz, int valor) {
    if(raiz == NULL){
        return 0;
    }
    struct NO* novoNo = (struct NO*)malloc(sizeof(struct NO));
    if(novoNo == NULL){
        return 0;
    }
    novoNo->info = valor;
    novoNo->esq = NULL;
    novoNo->dir = NULL;

    if (*raiz == NULL){
        *raiz = novo;
    }else{
        struct NO* atual = *raiz;
        struct NO* anterior = NULL;
        while (atual != NULL){
            anterior = atual;
            if(valor == atual->info){
                free(novo);
                return 0; 
            }
            if(valor > atual->info){
                atual = atual->dir;
            }else{
                atual = atual->esq;
            }
        }
        if(valor > anterior->info){
            anterior->dir = novo;
        }else{
            anterior->esq = novo;
        }
    }
    return 1;
}

int main() {
    ArvoreBinaria* raiz = criaArvoreBinaria();
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
    preOrdemArvoreBinaria(raiz);
    printf("\n");
    printf("Pre ordem: %d\n", raiz);
    emOrdemArvoreBinaria(raiz);
    printf("\n");
    printf("Em ordem: %d\n", raiz);
    posOrdemArvoreBinaria(raiz);
    printf("\n");
    printf("Pos ordem: %d\n", raiz);

    x = insereArvoreBinaria(raiz, 10);

    return 0;
}
