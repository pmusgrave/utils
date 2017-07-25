// implementation of merge sort that returns items in ascending order

var random_data = new Array();
var dataset_size = 100000;
var i = 0
while (i < dataset_size) {
    random_data.push( Math.floor( Math.random() * dataset_size ) );
    i += 1;
}

module.exports = {
  merge : function (first_half, second_half) {
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

      // outside the while loop, any remaining items will already be sorted
      // comparison_pair must be added before anything in either half array
      if (comparison_pair[0] != null) {
        merged_subarray.push(comparison_pair[0]);
      }
      else if (comparison_pair[1] != null) {
        merged_subarray.push(comparison_pair[1]);
      }
      if (first_half[0] != null) {
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
  },

  mergeSort : function (data) {
    if (data.length === 1){
      return data;
    }
    else {
      var first_half_array = this.mergeSort(data.slice(0, Math.floor(data.length/2)));
      var second_half_array = this.mergeSort(data.slice(Math.floor(data.length/2)));
      return module.exports.merge(first_half_array, second_half_array);
    }
  }
}

var result = module.exports.mergeSort(random_data)

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
