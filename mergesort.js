// implementation of merge sort that returns items in ascending order

var random_data = new Array();
var dataset_size = 10;
var i = 0
while (i <= dataset_size) {
    random_data.push( Math.floor( Math.random() * dataset_size ) );
    i += 1;
}

function merge(first_half, second_half) {
    var merged_subarray = new Array();
    var comparison_pair = new Array(2);
    comparison_pair[0] = first_half.shift();
    comparison_pair[1] = second_half.shift();

    if (first_half.length == 1 && second_half.length == 1) {
      if (comparison_pair[0] < comparison_pair[1]){
        merged_subarray.push(comparison_pair[0]);
        merged_subarray.push(comparison_pair[1]);
        console.log("merged " + merged_subarray);
        return merged_subarray;
      }
      else {
        merged_subarray.push(comparison_pair[1]);
        merged_subarray.push(comparison_pair[0]);
        console.log("merged " + merged_subarray);
        return merged_subarray;
      }
    }
    else {
      //
      while (first_half.length != 0 && second_half.length != 0) {

        if (comparison_pair[0] < comparison_pair[1]){
          merged_subarray.push(comparison_pair[0]);
          comparison_pair[0] = first_half.shift();
          console.log("merged " + merged_subarray);
        }
        else if (comparison_pair[0] > comparison_pair[1]){
          merged_subarray.push(comparison_pair[1]);
          comparison_pair[1] = second_half.shift();
        }
        else {
          merged_subarray.push(comparison_pair[0]);
          merged_subarray.push(comparison_pair[1]);
          comparison_pair[0] = first_half.shift();
          comparison_pair[1] = second_half.shift();
        }
      }

      if (first_half.length >= 1) {
        merged_subarray.push(first_half);
      }
      if (second_half.length >= 1) {
        merged_subarray.push(second_half);
      }
      console.log("merged " + merged_subarray);

    }
    return merged_subarray;
}

function mergeSort(data) {
  console.log(data);
  if (data.length === 1){
    return data;
  }
  else {
    var first_half_array = mergeSort(data.slice(0, Math.floor(data.length/2)));
    var second_half_array = mergeSort(data.slice(Math.floor(data.length/2)));
    return merge(first_half_array, second_half_array);
  }
}

console.log(random_data);
console.log(mergeSort(random_data));
