module.exports = {
  binarySearch: function (data, key) {
      var search_index = 0;
      var min_index = 0;
      var max_index = data.length;
      var found_index = null;
      while ((max_index - min_index) > 1) {
          search_index = getNextSearchIndex(min_index, max_index);

          if (data[min_index] == key ) {
              found_index = min_index
              break
          }
          else if (data[search_index] == key) {
              found_index = search_index
              break
          }
          else if (data[search_index] > key) {
              max_index = search_index
          }
          else if (data[search_index] < key) {
              min_index = search_index
          }
      }
      return found_index;
  }
};

function getNextSearchIndex(min_index, max_index) {
    var search_index = 0;
    if ((max_index - min_index) == 2) {
        search_index = min_index + 1
    }
    else {
        search_index = Math.floor( (max_index-min_index) / 2 ) + min_index
    }
    console.log("index: " + search_index);
    return search_index;
}

// testing
var random_data = new Array();
var dataset_size = 1001;
var i = 0
while (i <= dataset_size) {
    random_data.push(i);
    i += 1;
}

var key = process.argv[2];
if (!isNaN(key)) {
  var index = module.exports.binarySearch(random_data, key);
  if (index != null) {
      console.log("Value is located at index", index);
  }
  else {
      console.log("Value not found");
  }
}
else {
  console.log('Input was not a number');
}
