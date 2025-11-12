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

void rotacaoLL(ArvoreAVL *raiz){
    struct NO *no;
    no = (*raiz)->esq;
    (*raiz)->esq = no->dir;
    no->dir = *raiz;
    (*raiz)->altura = maior(alturaNO((*raiz)->esq),
                            alturaNO((*raiz)->dir))
                            + 1;
    no->altura = maior(alturaNO(no->esq),
                        (*raiz)->altura) + 1;
    *raiz = no;
}

void rotacaoRR(ArvoreAVL *raiz){
    struct NO *no;
    no = (*raiz)->dir;
    (*raiz)->dir = no->esq;
    no->esq = *raiz;
    (*raiz)->altura = maior(alturaNO((*raiz)->esq),
                            alturaNO((*raiz)->dir))
                            + 1;
    no->altura = maior(alturaNO(no->dir),
                        (*raiz)->altura) + 1;
    *raiz = no;
}

void rotacaoLR(ArvoreAVL *raiz){
    rotacaoRR(&(*raiz)->esq);
    rotacaoLL(raiz);
}

void rotacaoRL(ArvoreAVL *raiz){
    rotacaoLL(&(*raiz)->dir);
    rotacaoRR(raiz);
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