#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>
#include <string.h>

#define STRING_SIZE 200
#define STRING_COUNT 10

typedef struct {
    int key;
    char strings[STRING_COUNT][STRING_SIZE];
    bool flag;
    float values[4];
} Record;

// Função para gerar registros aleatórios
void generate_random_record(Record *record) {
    record->key = rand() % 1000000;
    for (int i = 0; i < STRING_COUNT; i++) {
        snprintf(record->strings[i], STRING_SIZE, "String%d", rand() % 100);
    }
    record->flag = rand() % 2;
    for (int j = 0; j < 4; j++) {
        record->values[j] = (float)(rand() % 100) / 10;
    }
}

// Função para obter o tempo de CPU no Windows
double get_cpu_time() {
    FILETIME creationTime, exitTime, kernelTime, userTime;
    if (GetProcessTimes(GetCurrentProcess(), &creationTime, &exitTime, &kernelTime, &userTime)) {
        ULARGE_INTEGER uKernelTime, uUserTime;
        uKernelTime.LowPart = kernelTime.dwLowDateTime;
        uKernelTime.HighPart = kernelTime.dwHighDateTime;
        uUserTime.LowPart = userTime.dwLowDateTime;
        uUserTime.HighPart = userTime.dwHighDateTime;
        return (uKernelTime.QuadPart + uUserTime.QuadPart) * 1e-7;  // Converte para segundos
    }
    return 0;
}

void quicksort_int(int arr[], int low, int high, long *comparisons, long *copies) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            (*comparisons)++;
            if (arr[j] < pivot) {
                i++;
                (*copies)++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        (*copies)++;
        arr[high] = arr[i + 1];
        arr[i + 1] = pivot;

        quicksort_int(arr, low, i, comparisons, copies);
        quicksort_int(arr, i + 2, high, comparisons, copies);
    }
}

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

// Função para inserir elementos na lista duplamente encadeada
void insert(Node **head, int value) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = *head;
    new_node->prev = NULL;

    if (*head != NULL)
        (*head)->prev = new_node;
    *head = new_node;
}

// Função para ordenar a lista com QuickSort
// (Pseudocódigo para ilustrar abordagem, detalhamento é longo)
void quicksort_list(Node *head, Node *tail, long *comparisons, long *copies) {
    // Similar ao QuickSort em vetor, adaptado para ponteiros
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Uso: %s <N> <arquivo_saida>\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);
    char *output_file = argv[2];

    srand((unsigned) time(NULL)); // Inicializa o gerador de números aleatórios

    FILE *output = fopen(output_file, "w");
    if (!output) {
        perror("Erro ao abrir o arquivo de saída");
        return 1;
    }

    // Vetor de inteiros
    int *int_array = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) int_array[i] = rand() % 1000000;

    long comparisons = 0, copies = 0;
    double start_time = get_cpu_time();
    quicksort_int(int_array, 0, N - 1, &comparisons, &copies);
    double end_time = get_cpu_time();

    fprintf(output, "Vetor de inteiros - Comparações: %ld, Cópias: %ld, Tempo: %.6f segundos\n",
            comparisons, copies, end_time - start_time);

    // Outras implementações (lista duplamente encadeada, vetor de registros)...

    fclose(output);
    free(int_array);

    return 0;
}
