/***********************************************************************
* INSERTION SORT
* Time complexity: O(n^2)
***********************************************************************/
#include <stdio.h>
#include "sorting.h"

void initialize(int* array){
  int random_data[ARRAY_LENGTH] = {0,1,5,9,4,6,7,2,3,4,8,1,9,5,4};

  for(int i = 0; i < ARRAY_LENGTH; i++) {
    array[i] = random_data[i];
  }
}

void insertionsort(int* array) {
  int key;

  for (int j = 1; j < ARRAY_LENGTH; j++){
    key = array[j];
    int i = j-1;
    while(i >= 0 && array[i] > key) {
      array[i+1] = array[i];
      i--;
    }
    array[i+1] = key;
  }
}

void print_array(int* array){
  for(int i = 0; i < ARRAY_LENGTH; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}
