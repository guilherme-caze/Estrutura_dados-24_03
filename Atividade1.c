#include <stdio.h>
#include <string.h>

struct Produto{

    char nome[30];
    int quantidade;
    float preco;

};

// Função para mesclar dois subarrays
void merge(struct Produto arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    struct Produto L[n1], R[n2];

    // Copiando dados para arrays temporários
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0; j = 0; k = left;

    // Mesclando os arrays de volta no array principal
    while (i < n1 && j < n2) {
        if (strcmp(L[i].nome, R[j].nome) <= 0) { // Comparação alfabética
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiando os elementos restantes
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Função para implementar o Merge Sort
void mergeSort(struct Produto arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Ordenando as metades
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Mesclando as metades ordenadas
        merge(arr, left, mid, right);
    }
}

int main() {
    struct Produto produto[] = {
        {"Agua", 30, 2.99},
        {"Sucrilhos", 20, 7.99},
        {"Coca-cola", 10, 6.99},
        {"Tomate", 70, 3.99}
    };
    int n = sizeof(produto) / sizeof(produto[0]);

    mergeSort(produto, 0, n - 1);

    printf("\nProdutos apos a ordenacao (por nome):\n");
    for (int i = 0; i < n; i++) {
        printf("%s - Quantidade: %d - Preco: %.2f\n", produto[i].nome, produto[i].quantidade, produto[i].preco);
    }

    return 0;
}
