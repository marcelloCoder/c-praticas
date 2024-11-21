#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define STRING_TAMANHO 200
#define STRING_CONTADOR 10

// Estruturas
typedef struct Node {
    int chave;
    struct Node *anterior;
    struct Node *proximo;
} Node;

typedef struct Registro {
    int chave;
    char strings[STRING_CONTADOR][STRING_TAMANHO];
    bool booleano;
    float valores[4];
} Registro;

// Variáveis globais para métricas
long comparacao = 0;
long contadorCopias = 0;

// Funções de tempo
double get_cpu_time() {
    return (double)clock() / CLOCKS_PER_SEC;
}

// -------------------- Vetor de Inteiros --------------------
void gerar_vetor_aleatorio(int *vetor, int N) {
    for (int i = 0; i < N; i++) {
        vetor[i] = rand() % 1000000;
    }
}

int particiona_vetor(int *vetor, int inicio, int fim) {
    int pivo = vetor[inicio];
    int esquerda = inicio;
    int direita = fim;

    while (esquerda < direita) {
        while (vetor[esquerda] <= pivo) {
            comparacao++;
            esquerda++;
        }
        while (vetor[direita] > pivo) {
            comparacao++;
            direita--;
        }
        if (esquerda < direita) {
            int temp = vetor[esquerda];
            vetor[esquerda] = vetor[direita];
            vetor[direita] = temp;
            contadorCopias += 3;
        }
    }
    vetor[inicio] = vetor[direita];
    vetor[direita] = pivo;
    contadorCopias += 3;

    return direita;
}

void quicksort_vetor(int *vetor, int inicio, int fim) {
    if (inicio < fim) {
        int pivo = particiona_vetor(vetor, inicio, fim);
        quicksort_vetor(vetor, inicio, pivo - 1);
        quicksort_vetor(vetor, pivo + 1, fim);
    }
}

// -------------------- Lista Duplamente Encadeada --------------------
Node* criar_no(int chave) {
    Node *novo = (Node *)malloc(sizeof(Node));
    novo->chave = chave;
    novo->anterior = NULL;
    novo->proximo = NULL;
    return novo;
}

void inserir_fim(Node **cabeca, int chave) {
    Node *novo = criar_no(chave);
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

void gerar_lista_dupla(Node **cabeca, int N) {
    for (int i = 0; i < N; i++) {
        inserir_fim(cabeca, rand() % 1000000);
    }
}

Node* particiona_lista(Node *inicio, Node *fim) {
    int pivo = inicio->chave;
    Node *esquerda = inicio;
    Node *direita = fim;

    while (esquerda != direita) {
        while (esquerda != fim && esquerda->chave <= pivo) {
            comparacao++;
            esquerda = esquerda->proximo;
        }
        while (direita != inicio && direita->chave > pivo) {
            comparacao++;
            direita = direita->anterior;
        }
        if (esquerda != direita) {
            int temp = esquerda->chave;
            esquerda->chave = direita->chave;
            direita->chave = temp;
            contadorCopias += 3;
        }
    }

    int temp = inicio->chave;
    inicio->chave = direita->chave;
    direita->chave = temp;
    contadorCopias += 3;

    return direita;
}

void quicksort_lista(Node *inicio, Node *fim) {
    if (inicio != fim && inicio != NULL && fim != NULL && inicio->anterior != fim) {
        Node *pivo = particiona_lista(inicio, fim);
        quicksort_lista(inicio, pivo->anterior);
        quicksort_lista(pivo->proximo, fim);
    }
}

// -------------------- Vetor de Registros --------------------
void gerar_registros_aleatorios(Registro *registros, int N) {
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

int particiona_registros(Registro *registros, int inicio, int fim) {
    Registro pivo = registros[inicio];
    int esquerda = inicio;
    int direita = fim;

    while (esquerda < direita) {
        while (registros[esquerda].chave <= pivo.chave) {
            comparacao++;
            esquerda++;
        }
        while (registros[direita].chave > pivo.chave) {
            comparacao++;
            direita--;
        }
        if (esquerda < direita) {
            Registro temp = registros[esquerda];
            registros[esquerda] = registros[direita];
            registros[direita] = temp;
            contadorCopias++;
        }
    }
    registros[inicio] = registros[direita];
    registros[direita] = pivo;
    contadorCopias++;

    return direita;
}

void quicksort_registros(Registro *registros, int inicio, int fim) {
    if (inicio < fim) {
        int pivo = particiona_registros(registros, inicio, fim);
        quicksort_registros(registros, inicio, pivo - 1);
        quicksort_registros(registros, pivo + 1, fim);
    }
}

// -------------------- Programa Principal --------------------
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

    // Teste para Vetor de Inteiros
    int *vetor = malloc(N * sizeof(int));
    gerar_vetor_aleatorio(vetor, N);
    comparacao = contadorCopias = 0;
    double inicio = get_cpu_time();
    quicksort_vetor(vetor, 0, N - 1);
    double fim = get_cpu_time();
    fprintf(saida, "Vetor de Inteiros - Comparações: %ld, Cópias: %ld, Tempo: %.6f segundos\n", comparacao, contadorCopias, fim - inicio);
    free(vetor);

    // Teste para Lista Duplamente Encadeada
    Node *lista = NULL;
    gerar_lista_dupla(&lista, N);
    comparacao = contadorCopias = 0;
    inicio = get_cpu_time();
    quicksort_lista(lista, lista->proximo);
    fim = get_cpu_time();
    fprintf(saida, "Lista Duplamente Encadeada - Comparações: %ld, Cópias: %ld, Tempo: %.6f segundos\n", comparacao, contadorCopias, fim - inicio);

    // Teste para Vetor de Registros
    Registro *registros = malloc(N * sizeof(Registro));
    gerar_registros_aleatorios(registros, N);
    comparacao = contadorCopias = 0;
    inicio = get_cpu_time();
    quicksort_registros(registros, 0, N - 1);
    fim = get_cpu_time();
    fprintf(saida, "Vetor de Registros - Comparações: %ld, Cópias: %ld, Tempo: %.6f segundos\n", comparacao, contadorCopias, fim - inicio);
    free(registros);

    fclose(saida);
    return 0;
}
