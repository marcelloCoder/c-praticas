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

int removeArvoreAVL(ArvoreAVL *raiz, int valor){
    if(*raiz == NULL){
        printf("Valor não existe!!");
        return 0;
    }
    int res;
    if(valor < (*raiz)->info){
        if((res=removeArvoreAVL(&(*raiz)->esq,valor))==1){
            if(fatorBalanceamentoNO(*raiz) >= 2){
                if(alturaNO((*raiz)->dir->esq) <= alturaNO((*raiz)->dir->dir)){
                    rotacaoRR(raiz);
                }else{
                    rotacaoRL(raiz);
                }
            }
        }
    }
    if((*raiz)->info < valor){
        if((res=removeArvoreAVL(&(*raiz)->dir, valor))==1){
            if(fatorBalanceamentoNO(*raiz) >= 2){
                if(alturaNO((*raiz)->esq->dir) <= alturaNO((*raiz)->esq->esq)){
                    rotacaoLL(raiz);
                }else{
                    rotacaoLR(raiz);
                }
            }
        }
    }

    if((*raiz)->info == valor){
        if(((*raiz)->esq==NULL || (*raiz)->dir==NULL)){
            struct NO *oldNode = (*raiz);
            if((*raiz)->esq != NULL){
                *raiz = (*raiz)->esq;
            }else{
                *raiz = (*raiz)->dir;
            }
            free(oldNode);
        }else{
            struct NO* temp = procuraMenor((*raiz)->dir);
            (*raiz)->info = temp->info;
            removeArvoreAVL(&(*raiz)->dir, (*raiz)->info);
            if(fatorBalanceamentoNO(*raiz) >= 2){
                if(alturaNO((*raiz)->esq->dir) <= alturaNO((*raiz)->esq->esq)){
                    rotacaoLL(raiz);
                }else{
                    rotacaoLR(raiz);
                }
            }
        }
        return 1;
    }
    return res;
}

struct NO* procuraMenor(struct NO* atual){
    struct NO *no1 = atual;
    struct NO *no2 = atual->esq;
    while (no2 != NULL)
    {
        no1 = no2;
        no2 = no2->esq;
    }
    return no1;
}

void imprimir(struct NO *raiz, int nivel){
    int i;
    if(raiz){
        imprimir(raiz->dir, nivel + 1);
        printf("\n\n");

        for (i = 0; i < nivel; i++)
        {
            printf("\t");
        }
        printf("%d", raiz->info);
        imprimir(raiz->esq, nivel + 1);
        
    }
}

int main(){
    int opcao, valor;
    struct NO *raiz = NULL;

    do{
        printf("\n\n\t0 - SAir\n\t1 - INSERIR\n\t2 - Remover\n\t3 - IMPRIMIR\n\t 4 - BUSCAR\n\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:
            printf("SAINDO!!");
            break;
        
        default:
            break;
        }
    }while (opcao != 0);
    
    return 0;
}