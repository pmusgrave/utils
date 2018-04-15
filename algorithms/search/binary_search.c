#include <stdio.h>

#define ARRAY_LENGTH 1001

int binarySearch(int *data, int key);
int getNextSearchIndex(int min_index, int max_index);

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
  int index = binarySearch(random_data, key);
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

int binarySearch(int *data, int key) {
      int search_index = 0;
      int min_index = 0;
      int max_index = ARRAY_LENGTH-1;
      int found_index = -1;
      while ((max_index - min_index) > 1) {
          search_index = getNextSearchIndex(min_index, max_index);

          if (data[min_index] == key ) {
              found_index = min_index;
              break;
          }
          else if (data[search_index] == key) {
              found_index = search_index;
              break;
          }
          else if (data[search_index] > key) {
              max_index = search_index;
          }
          else if (data[search_index] < key) {
              min_index = search_index;
          }
      }
      return found_index;
}

int getNextSearchIndex(int min_index, int max_index) {
    int search_index = 0;
    if ((max_index - min_index) == 2) {
        search_index = min_index + 1;
    }
    else {
        search_index = ( (max_index-min_index) / 2 ) + min_index;
    }
    printf("index: %d\n", search_index);
    return search_index;
}
