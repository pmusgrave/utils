// implementation of merge sort that returns items in ascending order
#include <stdio.h>

#define ARRAY_LENGTH 15

void merge (int* , int*);

void merge (int* first_half, int* second_half) {
    int merged_subarray = new Array();
    int comparison_pair = new Array(2);
    comparison_pair[0] = first_half.shift();
    comparison_pair[1] = second_half.shift();
    while (comparison_pair[0] != null && comparison_pair[1] != null) {
      if (comparison_pair[0] < comparison_pair[1]){
        merged_subarray.push(comparison_pair[0]);
        if (first_half[0] == null) {
          comparison_pair[0] = null;
        }
        else {
          comparison_pair[0] = first_half.shift();
        }
      }
      else if (comparison_pair[0] > comparison_pair[1]){
        merged_subarray.push(comparison_pair[1]);
        if (second_half[0] == null) {
          comparison_pair[1] = null;
        }
        else {
          comparison_pair[1] = second_half.shift();
        }
      }
      else {
        merged_subarray.push(comparison_pair[0]);
        merged_subarray.push(comparison_pair[1]);
        if (first_half[0] == null) {
          comparison_pair[0] = null;
        }
        else {
          comparison_pair[0] = first_half.shift();
        }

        if (second_half[0] == null) {
          comparison_pair[1] = null;
        }
        else {
          comparison_pair[1] = second_half.shift();
        }
      }
    }

    // outside the while loop, any remaining items will already be sorted
    // comparison_pair must be added before anything in either half array
    if (comparison_pair[0] != null) {
      merged_subarray.push(comparison_pair[0]);
    }
    else if (comparison_pair[1] != null) {
      merged_subarray.push(comparison_pair[1]);
    }
    if (first_half[0] != null) {
      for (int i = 0; i < first_half.length; i++) {
        merged_subarray.push(first_half[i]);
      }
    }
    else if (second_half[0] != null) {
      for (int j = 0; j < second_half.length; j++) {
        merged_subarray.push(second_half[j]);
      }
    }
    return merged_subarray;
},

void mergeSort (data) {
  if (data.length === 1){
    return data;
  }
  else {
    int first_half_array = this.mergeSort(data.slice(0, Math.floor(data.length/2)));
    int second_half_array = this.mergeSort(data.slice(Math.floor(data.length/2)));
    return module.exports.merge(first_half_array, second_half_array);
  }
}
