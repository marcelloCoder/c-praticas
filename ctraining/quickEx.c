#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define STRING_TAMANHO 200
#define STRING_CONTADOR 10

// Estrutura do Registro
typedef struct
{
    int chave;
    char strings[STRING_CONTADOR][STRING_TAMANHO];
    bool booleano;
    float valores[4];
} Registro;

// Node = nó : LISTA ENCADEADA
typedef struct Node
{
    int chave;             // Dado principal
    struct Node *anterior; // Ponteiro para o nó anterior
    struct Node *proximo;  // Ponteiro para o próximo nó
} Node;

// Contadores globais para métricas
long comparacoes = 0;
long copias = 0;

// Função para medir tempo de execução
// Função para medir o tempo de execução em segundos
double tempoExecucao()
{
    return (double)clock() / CLOCKS_PER_SEC;
}

Node *criarNode(int chave)
{
    Node *novo = (Node *)malloc(sizeof(Node));
    if (novo)
    {
        novo->chave = chave;
        novo->anterior = NULL;
        novo->proximo = NULL;
        return novo;
    }else{
        printf("Erro ao alocar memória\n");
    }
}

void inserirFim(Node **cabeca, int chave)
{ // A função inserirFim é chamada para adicionar
    // um novo nó com o valor gerado ao final da lista.
    Node *novo = criarNode(chave); /*Um novo nó é criado usando a função criarNode,
    que aloca memória para o nó e define seus campos (chave, anterior, proximo).*/
    if (*cabeca == NULL)
    {
        *cabeca = novo; /*Se a lista estiver vazia, o novo nó se torna a cabeça da lista.*/
        return;
    }
    Node *atual = *cabeca; //Caso contrário, percorre a lista até encontrar o último nó.
    while (atual->proximo != NULL)
    {
        atual = atual->proximo;//Caso contrário, percorre a lista até encontrar o último nó.
    }
    atual->proximo = novo;
    novo->anterior = atual;/*O novo nó é inserido no final da lista, com o ponteiro proximo do nó atual
     apontando para o novo nó e o ponteiro anterior do novo nó apontando para o nó atual.*/
}

void imprimirLista(Node *cabeca)
{
    Node *atual = cabeca;
    while (atual != NULL)
    {
        printf("%d ", atual->chave);
        atual = atual->proximo;
    }
    printf("\n");
}

// Função para gerar registros aleatórios
void geraRegistrosRandom(Registro *registros, int N)
{
    for (int i = 0; i < N; i++)
    {
        registros[i].chave = rand() % 1000000;
        for (int j = 0; j < STRING_CONTADOR; j++)
        {
            snprintf(registros[i].strings[j], STRING_TAMANHO, "String%d", rand() % 100);
        }
        registros[i].booleano = rand() % 2;
        for (int k = 0; k < 4; k++)
        {
            registros[i].valores[k] = (float)(rand() % 10000) / 100.0;
        }
    }
}

// Função de particionamento do QuickSort
int particiona(int *vetor, int inicio, int fim)
{
    int pivo = vetor[inicio];
    int esquerda = inicio + 1;
    int direita = fim;

    while (esquerda <= direita)
    {
        while (esquerda <= fim && vetor[esquerda] <= pivo)
        {
            comparacoes++;
            esquerda++;
        }
        while (direita > inicio && vetor[direita] > pivo)
        {
            comparacoes++;
            direita--;
        }
        if (esquerda < direita)
        {
            int aux = vetor[esquerda];
            vetor[esquerda] = vetor[direita];
            vetor[direita] = aux;
            copias += 3;
        }
    }
    vetor[inicio] = vetor[direita];
    vetor[direita] = pivo;
    copias += 3;

    return direita;
}

// Implementação do QuickSort
// RECURSIVO
void quicksort(int *vetor, int inicio, int fim)
{
    if (inicio < fim)
    {
        int pivo = particiona(vetor, inicio, fim);
        quicksort(vetor, inicio, pivo - 1);
        quicksort(vetor, pivo + 1, fim);
    }
}

// Função principal
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Uso: %s <N> <arquivo_saida>\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);
    char *arquivo_saida = argv[2];

    FILE *saida = fopen(arquivo_saida, "w");
    if (!saida)
    {
        perror("Erro ao abrir o arquivo de saída");
        return 1;
    }

    srand(time(NULL)); /*utiliza o relógio interno do computador para controlar a escolha da semente.*/

    // Lista duplamente encadeada
    Node *lista = NULL; // inicia a lista NULL indicando que a lista está vazia.
    for (int i = 0; i < N; i++)
    {                                         // executa N interações
        inserirFim(&lista, rand() % 1000000); // Insere o número gerado no final da lista duplamente encadeada.
        // Gera um número aleatório entre 0 e 999999.
    }

    printf("Lista original:\n");
    imprimirLista(lista);
    // Métricas
    comparacoes = 0;
    copias = 0;
    double inicio = tempoExecucao();

    // Ordenar lista (conversão para vetor)
    int *vetor = malloc(N * sizeof(int));
    Node *atual = lista;
    for (int i = 0; i < N; i++)
    {
        vetor[i] = atual->chave;
        atual = atual->proximo;
    }

    quicksort(vetor, 0, N - 1);

    // Reconstruir lista
    atual = lista;
    for (int i = 0; i < N; i++)
    {
        atual->chave = vetor[i];
        atual = atual->proximo;
    }
    free(vetor);

    double fim = tempoExecucao();

    printf("Lista ordenada:\n");
    imprimirLista(lista);

    // Gerar e ordenar registros aleatórios
    Registro *registros = malloc(N * sizeof(Registro));
    geraRegistrosRandom(registros, N);

    fprintf(saida, "QuickSort - Performance COM Lista Duplamente Encadeada:\n");
    fprintf(saida, "Comparações: %ld\n", comparacoes);
    fprintf(saida, "Cópias: %ld\n", copias);
    fprintf(saida, "Tempo de execução: %f segundos\n\n", fim - inicio);

    // Liberar memória
    while (lista != NULL)
    {
        Node *temp = lista;
        lista = lista->proximo;
        free(temp);
    }

    fclose(saida);
    return 0;

    /*
    ./quickEx 10000 saida10000k.txt
    ./quickEx 100000 saida100000k.txt
    ./quickEx 1000000 saida10k.txt
    ./quickEx 10000000 saida10k.txt
    */
}