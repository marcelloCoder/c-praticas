#include <stdio.h>
#include <stdlib.h>

typedef struct NO{
    int valor;
    struct NO *esq, *dir;
    short altura;
}NO;

NO* novoNO(int x){
    NO *novo = malloc(sizeof(NO));

    if(novo){
        novo->valor = x;
        novo->esq = NULL;
        novo->dir = NULL;
        novo->altura = 0;
    }else{
        printf("\nERRO AO ALOCAR NO EM NOVONO!\n");
    }
    return novo;
}

short maior(short a, short b){
    return (a > b)? a: b;
}

short alturaDoNo(NO *no){
    if(no == NULL){
        return -1;
    }else{
        return no->altura;
    }
}

short fatorBalanceamento(NO *no){
    if(no){
        return (alturaDoNo(no->esq) - alturaDoNo(no->dir));
    }else{
        return 0;
    }
}

NO* rotacaoEsq(NO *r){
	if(r == NULL || r->dir == NULL) return r;
	
    NO *y, *f;

    y = r->dir;
    f = y->esq;

    y->esq = r;
    r->dir = f;

    r->altura = maior(alturaDoNo(r->esq), alturaDoNo(r->dir)) + 1;
    y->altura = maior(alturaDoNo(y->esq), alturaDoNo(y->dir)) + 1;

    return y;
}

NO* rotacaoDir(NO *r){
	if(r == NULL || r->esq == NULL) return r;
	
    NO *y, *f;

    y = r->esq;
    f = y->dir;

    y->dir = r;
    r->esq = f;

    r->altura = maior(alturaDoNo(r->esq), alturaDoNo(r->dir)) + 1;
    y->altura = maior(alturaDoNo(y->esq), alturaDoNo(y->dir)) + 1;

    return y;
}

NO* rotacaoDirEsq(NO *r){
    r->dir = rotacaoDir(r->dir);
    return rotacaoEsq(r);
}

NO* rotacaoEsqDir(NO *r){
    r->esq = rotacaoEsq(r->esq);
    return rotacaoDir(r);
}

NO* balancear(NO *raiz){
	if(raiz == NULL) return raiz;
	
    short fb = fatorBalanceamento(raiz);

    if(fb < -1 && fatorBalanceamento(raiz->dir) <= 0){
        raiz = rotacaoEsq(raiz);
    }else if(fb > 1 && fatorBalanceamento(raiz->esq) >= 0){
        raiz = rotacaoDir(raiz);
    }else if(fb > 1 && fatorBalanceamento(raiz->esq) < 0){
        raiz = rotacaoEsqDir(raiz);
    }else if(fb < -1 && fatorBalanceamento(raiz->dir) > 0){
        raiz = rotacaoDirEsq(raiz);
    }

    return raiz;
}




NO* inserir(NO *raiz, int x){
    if(raiz == NULL){
        return novoNO(x);
    }else{
        if(x < raiz->valor){
            raiz->esq = inserir(raiz->esq, x);
        }else if(x > raiz->valor){
            raiz->dir = inserir(raiz->dir, x);
        }else{
            printf("\nInsercao nao realizada!\n O elemento %d a existe!\n", x);
        }
    }

    raiz->altura = maior(alturaDoNo(raiz->esq), alturaDoNo(raiz->dir)) + 1;

    raiz = balancear(raiz);

    return raiz;
}

NO* remover(NO *raiz, int chave){
    if(raiz == NULL){
        printf("Valor não existe!!");
        return NULL;
    }else{
        if(raiz->valor == chave){
            if(raiz->esq == NULL && raiz->dir == NULL){
                free(raiz);
                printf("Elemento folha removido: %d !\n",chave);
                return NULL;
            }
            else{
                if(raiz->esq != NULL && raiz->dir != NULL){
                    NO *aux = raiz->esq;
                    while (aux->dir != NULL)
                    {
                        aux = aux->dir;
                    }
                    raiz->valor = aux->valor;
                    aux->valor = chave;
                    printf("ELEMENTO TROCADO: %d !\n", chave);
                    raiz->esq = remover(raiz->esq, chave);
                    return raiz;
                }
                else{
                    NO *aux;
                    if(raiz->esq != NULL){
                        aux = raiz->esq;
                    }else{
                        aux = raiz->dir;
                    }
                    free(raiz);
                    printf("ELEMENTO COM 1 FILHO REMOVIDO: %d !\n", chave);
                    return aux;
                }
            }
        }else{
            if(chave < raiz->valor){
                raiz->esq = remover(raiz->esq, chave);
            }else{
                raiz->dir = remover(raiz->dir, chave);
            }
        }

        raiz->altura = maior(alturaDoNo(raiz->esq), alturaDoNo(raiz->dir)) + 1;

        raiz = balancear(raiz);

        return raiz;
    }
}

void imprimir(NO *raiz, int nivel){
    int i;
    if(raiz){
        imprimir(raiz->dir, nivel + 1);
        printf("\n\n");

        for (i = 0; i < nivel; i++)
        {
            printf("\t");
        }
        printf("%d(%d)", raiz->valor, nivel - 1);
        imprimir(raiz->esq, nivel + 1);
    }
}

NO* buscar(NO *raiz, int num, int nivel){
    if(raiz){
        if(num == raiz->valor){
            printf("\n Nivel de %d: %d\n", num, nivel);
            return raiz;
        }
        else if(num < raiz->valor){
            return buscar(raiz->esq, num, nivel + 1);
        }else{
            return buscar(raiz->dir, num, nivel + 1);
        }
    }
    return NULL;
}


int main(){

    int opcao, valor;
    NO *raiz = NULL;

    do{
        printf("\n\n\t0 - SAir\n\t1 - INSERIR\n\t2 - Remover\n\t3 - IMPRIMIR\n\t4 - BUSCAR\n\n");
        scanf("%d", &opcao);

        switch (opcao){
        case 0:
            printf("SAINDO!!");
            break;
        case 1:
            printf("\tDigite o valor a ser inserido: ");
            scanf("%d", &valor);
            raiz = inserir(raiz, valor);
            break;
        case 2:
            printf("\tDigite o valor a ser removido: ");
            scanf("%d", &valor);
            raiz = remover(raiz, valor);
            break;
        case 3:
            imprimir(raiz, 1);
            break;
        case 4:
            printf("\tDigite o valor a ser procurado: ");
            scanf("%d", &valor);
            buscar(raiz, valor, 0);
            break;
        default:
            printf("\nOpcao Invalida!\n");
        }
    }while (opcao != 0);
    
    return 0;
}
