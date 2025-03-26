#include <stdio.h>

struct Alunos {
    char nome[40];
    float nota;
    int matricula;
};

// Função para transformar um array em um Max-Heap

void heapify(struct Alunos arr[], int n, int i) {
    int largest = i; // Assume que a raiz é o maior elemento
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].nota > arr[largest].nota)
        largest = left;

    if (right < n && arr[right].nota > arr[largest].nota)
        largest = right;

    if (largest != i) {
        struct Alunos temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
    }

    // Função principal do Heap Sort

    void heapSort(struct Alunos arr[], int n) {
    // Construção do Heap

    for (int i = n / 2 - 1; i >= 0; i--)

    heapify(arr, n, i);

    // Extração do maior elemento do heap

    for (int i = n - 1; i > 0; i--) {
    struct Alunos temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;

    heapify(arr, i, 0);

    }
    }

int main(){
    struct Alunos alunos[] = {
        {"Guilherme", 9.3, 23200199},
        {"Josias", 8.7, 23201198},
        {"Pedro", 4.9, 22200178},
        {"Cancelo", 9.9, 23200167},
        {"Carlos", 3.2, 24300199}
    };

    int size = sizeof(alunos) / sizeof(alunos[0]);

    heapSort(alunos, size);

    printf("Alunos ordenados pela menor nota ate a maior nota: \n");
        for(int i = 0; i < size; i++){
            printf("%s (%.1f) - %d\n", alunos[i].nome, alunos[i].nota, alunos[i].matricula);
    }

    return 0;
}