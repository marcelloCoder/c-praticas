/*P4) Altere a implementação visto em sala do Heap Sort para permitir que apenas os k
maiores elementos do vetor sejam ordenados e armazenados em uma nova lista, onde k é
informado pelo usuário. Em comparação à implementação vista em sala, existe mudança na
complexidade do algoritmo?*/

#include <stdio.h>

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

void kLargestElements(int arr[], int n, int k) {
    heapSort(arr, n);
    printf("Os %d maiores elementos: ", k);
    for (int i = n - k; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {34, 7, 23, 32, 5, 62, 32, 23, 12, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    kLargestElements(arr, n, k);

    return 0;
}
