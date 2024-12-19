#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"

typedef struct NO
{
    int info;
    struct NO *esq;
    struct NO* dir;
}NO;



ArvBin* criarArvBin(){
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if (raiz != NULL)
    {
        *raiz = NULL;
    }
    return raiz;   
}


void liberaNO(NO* no){
    if (no == NULL)
    {
        return;
    }
    liberaNO(no->esq);
    liberaNO(no->dir);
    free(no);
    no == NULL;
}

void liberaArvBin(ArvBin* raiz){
    if (raiz == NULL)
    {
        return;
    }
    liberaNO(*raiz);
    free(raiz);
}


int estaVaziaArvBin(ArvBin* raiz){
    if (raiz == NULL)
    {
        return 1;
    }
    if (*raiz == NULL)
    {
        return 1;
    }
    return 0;   
}

int alturaArvBin(ArvBin* raiz){
    if (raiz == NULL)
    {
        return 0;
    }
    if (*raiz == NULL)
    {
        return 0;
    }
    int altEsq = alturaArvBin(&((*raiz) -> esq));
    int altDir = alturaArvBin(&((*raiz) -> dir));
    if (altEsq > altDir)
    {
        return (altEsq + 1);
    }else{
        return(altDir + 1);
    }
    
    
}

int totalNOArvBin(ArvBin* raiz){
    if(raiz == NULL){
        return 0;
    }
    if (*raiz ==NULL)
    {
        return 0;
    }
    int altEsq = totalNOArvBin(&((*raiz)->esq));
    int altDir = totalNOArvBin(&((*raiz)->dir));
    return(altEsq  + altDir + 1);
}

void preOrdemArvBin(ArvBin *raiz){
    if (raiz == NULL)
    {
        return;
    }
    if (*raiz != NULL)
    {
        printf("%d\n", (*raiz)->info);
        preOrdemArvBin(&((*raiz)->esq));
        preOrdemArvBin(&((*raiz)->dir));
    }
    
    
}


int main(int argc, char const *argv[])
{

    ArvBin* raiz = criarArvBin();

    liberaArvBin(raiz);

    int x = estaVaziaArvBin(raiz);
    if (estaVaziaArvBin(raiz))
    {
    /* code */
    }

    int y = alturaArvBin(raiz);
    int z = totalNOArvBin(raiz);

    preOrdemArvBin(raiz);

    return 0;
}

