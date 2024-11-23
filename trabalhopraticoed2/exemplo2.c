#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define STRING_SIZE 200
#define STRING_COUNT 10

// Estrutura do Registro
typedef struct {
    int key;
    char strings[STRING_COUNT][STRING_SIZE];
    bool flag;
    float values[4];
} Record;

// Função de geração de tempo para medição de execução
double get_cpu_time() {
    return (double)clock() / CLOCKS_PER_SEC;
}

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

// Função QuickSort para vetor de inteiros
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

// Estrutura para lista duplamente encadeada
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

// Função MergeSort para vetor de inteiros
void merge(int arr[], int left, int mid, int right, long *comparisons, long *copies) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        (*comparisons)++;
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
        (*copies)++;
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

void mergesort_recursive(int arr[], int left, int right, long *comparisons, long *copies) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergesort_recursive(arr, left, mid, comparisons, copies);
        mergesort_recursive(arr, mid + 1, right, comparisons, copies);
        merge(arr, left, mid, right, comparisons, copies);
    }
}

// Função Heapify para HeapSort
void heapify(int arr[], int n, int i, long *comparisons, long *copies) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        (*comparisons)++;
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        (*comparisons)++;
        largest = right;
    }

    if (largest != i) {
        int swap = arr[i];
        arr[i] = arr[largest];
        arr[largest] = swap;
        (*copies)++;
        heapify(arr, n, largest, comparisons, copies);
    }
}

// Função HeapSort
void heapsort(int arr[], int n, long *comparisons, long *copies) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, comparisons, copies);
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        (*copies)++;
        heapify(arr, i, 0, comparisons, copies);
    }
}

// Função AlunoSort (BubbleSort)
void aluno_sort(int arr[], int n, long *comparisons, long *copies) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            (*comparisons)++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                (*copies)++;
            }
        }
    }
}

// Função Principal
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Uso: %s <N> <arquivo_saida>\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);
    FILE *output = fopen(argv[2], "w");
    if (!output) {
        perror("Erro ao abrir o arquivo de saída");
        return 1;
    }

    srand(time(NULL));

    int *array = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) array[i] = rand() % 1000000;

    long comparisons = 0, copies = 0;
    double start_time, end_time;

    // QuickSort
    comparisons = 0;
    copies = 0;
    start_time = get_cpu_time();
    quicksort_int(array, 0, N - 1, &comparisons, &copies);
    end_time = get_cpu_time();
    fprintf(output, "QuickSort - Comparações: %ld, Cópias: %ld, Tempo: %.6f\n", comparisons, copies, end_time - start_time);

    // MergeSort Recursivo
    for (int i = 0; i < N; i++) array[i] = rand() % 1000000;
    comparisons = 0;
    copies = 0;
    start_time = get_cpu_time();
    mergesort_recursive(array, 0, N - 1, &comparisons, &copies);
    end_time = get_cpu_time();
    fprintf(output, "MergeSort Recursivo - Comparações: %ld, Cópias: %ld, Tempo: %.6f\n", comparisons, copies, end_time - start_time);

    // HeapSort
    for (int i = 0; i < N; i++) array[i] = rand() % 1000000;
    comparisons = 0;
    copies = 0;
    start_time = get_cpu_time();
    heapsort(array, N, &comparisons, &copies);
    end_time = get_cpu_time();
    fprintf(output, "HeapSort - Comparações: %ld, Cópias: %ld, Tempo: %.6f\n", comparisons, copies, end_time - start_time);

    // AlunoSort
    for (int i = 0; i < N; i++) array[i] = rand() % 1000000;
    comparisons = 0;
    copies = 0;
    start_time = get_cpu_time();
    aluno_sort(array, N, &comparisons, &copies);
    end_time = get_cpu_time();
    fprintf(output, "AlunoSort (BubbleSort) - Comparações: %ld, Cópias: %ld, Tempo: %.6f\n", comparisons, copies, end_time - start_time);

    fclose(output);
    free(array);
    return 0;
}
