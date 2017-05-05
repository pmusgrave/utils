// implementation of merge sort that returns items in ascending order

var random_data = new Array();
var dataset_size = 100000;
var i = 0
while (i < dataset_size) {
    random_data.push( Math.floor( Math.random() * dataset_size ) );
    i += 1;
}

function merge(first_half, second_half) {
    var merged_subarray = new Array();
    var comparison_pair = new Array(2);
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


    if (comparison_pair[0] != null) {
      merged_subarray.push(comparison_pair[0]);
    }
    else if (comparison_pair[1] != null) {
      merged_subarray.push(comparison_pair[1]);
    }
    if (first_half[0] != null) {
      // merged_subarray.push(first_half);
      for (var i = 0; i < first_half.length; i++) {
        merged_subarray.push(first_half[i]);
      }
    }
    else if (second_half[0] != null) {
      for (var j = 0; j < second_half.length; j++) {
        merged_subarray.push(second_half[j]);
      }
    }
    return merged_subarray;
}

function mergeSort(data) {
  //console.log(data);
  if (data.length === 1){
    return data;
  }
  else {
    var first_half_array = mergeSort(data.slice(0, Math.floor(data.length/2)));
    var second_half_array = mergeSort(data.slice(Math.floor(data.length/2)));
    return merge(first_half_array, second_half_array);
  }
}

var t0 = performance.now();
//console.log(random_data);
var result = mergeSort(random_data)
//console.log(result);
var t1 = performance.now();
console.log("Merge sort took " + (t1 - t0) + " milliseconds.")


var success = true;
for (var i = 0; i < result.length - 1; i++) {
  if (result[i] > result[i+1]) {
    console.log("error");
    success = false;
  }
}
if (success == true){
  console.log("sort successful");
}
