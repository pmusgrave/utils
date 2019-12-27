#include <stdio.h>
#include "binary_search.h"

int binary_search(int *data, int key, int size) {
      int search_index = 0;
      int min_index = 0;
      int max_index = size-1;
      int found_index = -1;
      while ((max_index - min_index) > 1) {
          search_index = get_next_search_index(min_index, max_index);

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

int get_next_search_index(int min_index, int max_index) {
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
