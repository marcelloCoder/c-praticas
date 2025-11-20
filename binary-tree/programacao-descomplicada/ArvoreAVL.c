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
    // labs garante que o resultado será sempre positivo, ou seja, o valor absoluto da diferença.
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

int insereArvoreAVL(ArvoreAVL *raiz, int valor){
    int res;
    if(*raiz == NULL){
        struct NO *novo;
        novo = (struct NO*)malloc(sizeof(struct NO));
        if(novo == NULL){
            return 0;
        }
        novo->info = valor;
        novo->altura = 0;
        novo->esq = NULL;
        novo->dir = NULL;
        *raiz = novo;
        return 1;
    }
    struct NO *atual = *raiz;
    if(valor < atual->info){
        if((res = insereArvoreAVL(&(atual->esq), valor)) == 1){
            if(fatorBalanceamentoNO(atual) >= 2){
                if(valor < (*raiz)->esq->info){
                    rotacaoLL(raiz);
                }else{
                    rotacaoLR(raiz);
                }
            }
        }
    }else{
        if(valor > atual->info){
            if((res = insereArvoreAVL(&(atual->dir), valor)) == 1){
                if(fatorBalanceamentoNO(atual) >= 2){
                    if((*raiz)->dir->info < valor){
                        rotacaoRR(raiz);
                    }else{
                        rotacaoRL(raiz);
                    }
                }
            }
        }else{
            printf("Valor duplicado \n");
            return 0;
        }
    }
    atual->altura = maior(alturaNO(atual->esq), 
                        alturaNO(atual->dir)) + 1;
    return res;
}

int main(){
    ArvoreAVL* raiz;
    int x = insereArvoreAVL(raiz,valor);
}