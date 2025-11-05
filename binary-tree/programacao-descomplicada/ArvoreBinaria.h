typedef struct NO* ArvoreBinaria;

ArvoreBinaria* criaArvoreBinaria();

void liberaArvoreBinaria(ArvoreBinaria* raiz);

int estaVaziaArvoreBinaria(ArvoreBinaria* raiz);

int alturaArvoreBinaria(ArvoreBinaria* raiz);

int totalNOArvoreBinaria(ArvoreBinaria* raiz);

void preOrdemArvoreBinaria(ArvoreBinaria* raiz);

void emOrdemArvoreBinaria(ArvoreBinaria* raiz);

void posOrdemArvoreBinaria(ArvoreBinaria* raiz);