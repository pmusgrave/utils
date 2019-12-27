#include <stdio.h>
#include "sorting.h"

void quicksort(int *array, int low, int high) {
    // for (int i = 0; i < ARRAY_LENGTH; i++){
    //   printf("%d ", array[i]);
    // }
    // printf("\n");

    if (low < high) {
        int q = partition(array, low, high);
        quicksort(array, low, q - 1);
        quicksort(array, q + 1, high);
    }
}

int partition(int *array, int low, int high) {
    int pivot = array[high];
    int i = low - 1;
    for (int j = low; j <= (high-1); j++) {
        if (array[j] <= pivot) {
            i++;
            int temp = array[j];
            array[j] = array[i];
            array[i] = temp;
        }
    }

    if (array[high] < array[i + 1]) {
        int temp = array[high];
        array[high] = array[i+1];
        array[i+1] = temp;
    }

    return (i+1);
}
