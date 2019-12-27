#include <stdio.h>
#define SIZE 10

double array[SIZE];

void initialize();
void insertionsort();

int main(void) {
  initialize();
  insertionsort();
  for(int i = 0; i < SIZE; i++) {
    printf("%f", array[i]);
    printf("\n");
  }
  return 0;
}

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

  for (int j = 1; j < SIZE; j++){
    key = array[j];
    int i = j-1;
    while(i >= 0 && array[i] > key) {
      array[i+1] = array[i];
      i--;
    }
    array[i+1] = key;
  }
}
