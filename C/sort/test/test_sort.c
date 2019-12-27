#include <stdio.h>
#include <unity.h>
#include "sorting.h"

void setUp(void) {}
void tearDown(void) {}

void test_insertionsort() {
  int array[ARRAY_LENGTH];
  initialize(array);
  printf("Original array:\n");
  print_array(array);
  insertionsort(array);
  printf("Sorted array:\n");
  print_array(array);
}

void test_quicksort() {
  printf("Testing quicksort...\n");

  int random_data[ARRAY_LENGTH] = {0,1,5,9,4,6,7,2,3,4,8,1,9,5,4};
  printf("Original array:\n");
  for (int i = 0; i < ARRAY_LENGTH; i++) {
    printf("%d ", random_data[i]);
  }
  printf("\n");

  quicksort(random_data, 0, ARRAY_LENGTH - 1);

  printf("Sorted array:\n");
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
}

int main(void) {
  RUN_TEST(test_insertionsort);
  RUN_TEST(test_quicksort);
}
