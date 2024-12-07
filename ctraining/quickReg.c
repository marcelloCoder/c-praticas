#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define STRING_TAMANHO 200
#define STRING_CONTADOR 10

// Estrutura do Registro
typedef struct {
    int chave;
    char strings[STRING_CONTADOR][STRING_TAMANHO];
    bool booleano;
    float valores[4];
} Registro;

// Node para Lista Duplamente Encadeada
typedef struct Node {
    int chave;
    struct Node *anterior;
    struct Node *proximo;
} Node;

// Contadores globais para métricas
long comparacoes = 0;
long copias = 0;

// Função para medir tempo de execução
double tempoExecucao() {
    return (double)clock() / CLOCKS_PER_SEC;
}

// Criar nó para a lista encadeada
Node *criarNode(int chave) {
    Node *novo = (Node *)malloc(sizeof(Node));
    if (novo) {
        novo->chave = chave;
        novo->anterior = NULL;
        novo->proximo = NULL;
        return novo;
    } else {
        printf("Erro ao alocar memória\n");
        exit(EXIT_FAILURE);
    }
}

// Inserir no final da lista encadeada
void inserirFim(Node **cabeca, int chave) {
    Node *novo = criarNode(chave);
    if (*cabeca == NULL) {
        *cabeca = novo;
        return;
    }
    Node *atual = *cabeca;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }
    atual->proximo = novo;
    novo->anterior = atual;
}

// Imprimir lista encadeada
void imprimirLista(Node *cabeca) {
    Node *atual = cabeca;
    while (atual != NULL) {
        printf("%d ", atual->chave);
        atual = atual->proximo;
    }
    printf("\n");
}

// Função para gerar registros aleatórios
void geraRegistrosRandom(Registro *registros, int N) {
    for (int i = 0; i < N; i++) {
        registros[i].chave = rand() % 1000000;
        for (int j = 0; j < STRING_CONTADOR; j++) {
            snprintf(registros[i].strings[j], STRING_TAMANHO, "String%d", rand() % 100);
        }
        registros[i].booleano = rand() % 2;
        for (int k = 0; k < 4; k++) {
            registros[i].valores[k] = (float)(rand() % 10000) / 100.0;
        }
    }
}

// Função de particionamento para vetor de inteiros
int particiona(int *vetor, int inicio, int fim) {
    int pivo = vetor[inicio];
    int esquerda = inicio + 1;
    int direita = fim;

    while (esquerda <= direita) {
        while (esquerda <= fim && vetor[esquerda] <= pivo) {
            comparacoes++;
            esquerda++;
        }
        while (direita > inicio && vetor[direita] > pivo) {
            comparacoes++;
            direita--;
        }
        if (esquerda < direita) {
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

// QuickSort para vetor de inteiros
void quicksort(int *vetor, int inicio, int fim) {
    if (inicio < fim) {
        int pivo = particiona(vetor, inicio, fim);
        quicksort(vetor, inicio, pivo - 1);
        quicksort(vetor, pivo + 1, fim);
    }
}

// QuickSort para vetor de registros
void quicksortRegistros(Registro *registros, int inicio, int fim) {
    if (inicio < fim) {
        int pivo = registros[inicio].chave;
        int esquerda = inicio + 1;
        int direita = fim;

        while (esquerda <= direita) {
            while (esquerda <= fim && registros[esquerda].chave <= pivo) {
                comparacoes++;
                esquerda++;
            }
            while (direita > inicio && registros[direita].chave > pivo) {
                comparacoes++;
                direita--;
            }
            if (esquerda < direita) {
                Registro temp = registros[esquerda];
                registros[esquerda] = registros[direita];
                registros[direita] = temp;
                copias += 1; // Consideramos cada troca de registro como uma cópia
            }
        }
        Registro temp = registros[inicio];
        registros[inicio] = registros[direita];
        registros[direita] = temp;
        copias += 1;

        quicksortRegistros(registros, inicio, direita - 1);
        quicksortRegistros(registros, direita + 1, fim);
    }
}

// Função principal
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Uso: %s <N> <arquivo_saida>\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);
    char *arquivo_saida = argv[2];
    FILE *saida = fopen(arquivo_saida, "w");
    if (!saida) {
        perror("Erro ao abrir o arquivo de saída");
        return 1;
    }

    srand(time(NULL));

    // Teste com vetor de inteiros
    int *vetor = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        vetor[i] = rand() % 1000000;
    }

    comparacoes = 0;
    copias = 0;
    double inicio = tempoExecucao();
    quicksort(vetor, 0, N - 1);
    double fim = tempoExecucao();
    fprintf(saida, "Vetor de Inteiros:\nComparacoes: %ld\nCopias: %ld\nTempo: %f segundos\n\n", comparacoes, copias, fim - inicio);

    // Teste com lista encadeada
    Node *lista = NULL;
    for (int i = 0; i < N; i++) {
        inserirFim(&lista, rand() % 1000000);
    }

    comparacoes = 0;
    copias = 0;
    int *vetorLista = malloc(N * sizeof(int));
    Node *atual = lista;
    for (int i = 0; i < N; i++) {
        vetorLista[i] = atual->chave;
        atual = atual->proximo;
    }
    inicio = tempoExecucao();
    quicksort(vetorLista, 0, N - 1);
    fim = tempoExecucao();
    fprintf(saida, "Lista Encadeada:\nComparacoes: %ld\nCopias: %ld\nTempo: %f segundos\n\n", comparacoes, copias, fim - inicio);

    // Teste com vetor de registros
    Registro *registros = malloc(N * sizeof(Registro));
    geraRegistrosRandom(registros, N);

    comparacoes = 0;
    copias = 0;
    inicio = tempoExecucao();
    quicksortRegistros(registros, 0, N - 1);
    fim = tempoExecucao();
    fprintf(saida, "Vetor de Registros:\nComparacoes: %ld\nCopias: %ld\nTempo: %f segundos\n", comparacoes, copias, fim - inicio);

    fclose(saida);
    free(vetor);
    free(vetorLista);
    free(registros);
    while (lista != NULL) {
        Node *temp = lista;
        lista = lista->proximo;
        free(temp);
    }

    return 0;
}
