#include <stdio.h>
#include <stdlib.h>

typedef struct Node // nó
{
    int valor;
    struct Node *proximo;
}Node;

void inserirNoInicio(Node **lista, int numero){
    Node *novoNode = malloc(sizeof(Node));

    if (novoNode)
    {
        novoNode->valor = numero;
        novoNode->proximo = *lista;
        *lista = novoNode;
    }else{
        printf("Erro ao alocar memória\n");
    }
    
}

int main(int argc, char const *argv[])
{
    return 0;
}

