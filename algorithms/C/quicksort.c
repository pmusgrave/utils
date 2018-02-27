#include <stdio.h>

#define ARRAY_LENGTH 15

void quicksort(int *, int, int);
int partition(int *, int, int);
void array_testing(int *, int length);

int main() {
  /******************************************************************************
  TESTING QUICKSORT
  ******************************************************************************/
  printf("Testing quicksort...\n");

  int random_data[ARRAY_LENGTH] = {0,1,5,9,4,6,7,2,3,4,8,1,9,5,4};

  quicksort(random_data, 0, ARRAY_LENGTH - 1);

  int success = 1;
  for (int i = 0; i < ARRAY_LENGTH - 1; i++) {
    if (random_data[i] > random_data[i+1]) {
      printf("error");
      success = 0;
    }
  }
  if (success == 1){
    for (int i = 0; i < ARRAY_LENGTH; i++){
      printf("%d ", random_data[i]);
    }
    printf("\n");
    printf("sort successful\n");
  }
  printf("Done\n");

  return 0;
}


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
