#include <stdio.h>
#include <string.h>

struct Carros {
    char nome[30];
    int potencia;
    char marca[15];
};

// Função para dividir o array em torno do pivô

int partition(struct Carros arr[], int low, int high) {
    struct Carros pivot = arr[high]; // Pivô é o último elemento
    int i = low - 1; // Índice do menor elemento
    for (int j = low; j < high; j++) {
        if (arr[j].potencia < pivot.potencia) { // Compara pela potencia
            i++;
            struct Carros temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    // Coloca o pivô na posição correta
    
    struct Carros temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
    }

    // Função recursiva do Quick Sort

    void quickSort(struct Carros arr[], int low, int high) {
    if (low < high) {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
    }
    }

int main(){
    struct Carros carros[] = {
        {"F40", 800, "Ferrari"},
        {"Honda Civic", 140, "Honda"},
        {"Bmw M4", 900, "Bmw"},
        {"Uno", 80, "Fiat"},
        {"McQueen", 1000, "Rusteze"}

    };

    int size = sizeof(carros) / sizeof(carros[0]);

    quickSort(carros, 0, size - 1);

    printf("Carros ordenados pela potencia: \n");
    for (int i = 0; i < size; i++)
    printf("%s (%d) - %s\n", carros[i].nome, carros[i].potencia, carros[i].marca);

    return 0;
}