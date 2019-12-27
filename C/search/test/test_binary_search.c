#include <stdio.h>
#include "binary_search.h"

#define ARRAY_LENGTH 1001

int main(int argc, char *argv[]) {
  /******************************************************************************
  TESTING BINARY SEARCH
  ******************************************************************************/
  printf("Testing binary_search.js...\n");

  int dataset_size = 1001;
  int random_data[dataset_size];
  int i = 0;
  while (i <= dataset_size) {
      random_data[i] = i;
      i += 1;
  }

  printf("Searching for 42...\n");
  int key = 42;
  int index = binary_search(random_data, key, ARRAY_LENGTH);
  if (index != -1) {
    printf("Value is located at index %d", index);
    printf("\n");
  }
  else {
    printf("Value not found\n");
  }
  printf("Done\n");

  return 0;
}
