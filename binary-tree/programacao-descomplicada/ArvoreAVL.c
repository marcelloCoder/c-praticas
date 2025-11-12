#include <stdio.h>
#include <stdlib.h>
#include "ArvoreAVL.h"

struct NO {
    int info;
    int altura;
    struct NO* esq;
    struct NO* dir;
};

int alturaNO(struct NO* no){
    if(no == NULL){
        return -1;
    }
    return no->altura;
}

int fatorBalanceamentoNO(struct NO* no){
    return labs(alturaNO(no->esq) - alturaNO(no->dir));
} 

int maior(int x, int y){
    if(x > y){
        return x;
    }else{
        return y;
    }
}

int main(){
    ArvoreAVL* raiz;
}