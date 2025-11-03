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

int main() {
    ArvoreBinaria* raiz;
    *raiz = criaArvoreBinaria();
    return 0;
}
