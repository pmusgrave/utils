#include <stdio.h>
#include "sorting.h"

double array[ARRAY_LENGTH];

void initialize(){
  array[0] = 8;
  array[1] = 2;
  array[3] = 4;
  array[4] = 9;
  array[5] = 3;
  array[6] = 6;
}

void insertionsort() {
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

void print_array(){
  for(int i = 0; i < ARRAY_LENGTH; i++) {
    printf("%f", array[i]);
    printf("\n");
  }
}
