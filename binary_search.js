var random_data = new Array();
var dataset_size = 1001;
var i = 0
while (i <= dataset_size) {
    random_data.push(i);
    i += 1;
}

function binarySearch (data, key) {
    var min_index = 0;
    var max_index = data.length;
    var found_index = null;
    while ((max_index - min_index) > 1) {
        if (key == data[min_index]) {
            found_index = min_index
            break
        }

        if ((max_index - min_index) == 2) {
            search_index = min_index + 1
        }
        else {
            search_index = Math.floor( (max_index-min_index) / 2 ) + min_index
        }
        console.log("index: " + search_index);

        if (key == data[search_index]) {
            found_index = search_index
            break
        }
        else if (key < data[search_index]) {
            max_index = search_index
        }
        else if (key > data[search_index]) {
            min_index = search_index
        }
    }
    return found_index;
}

var key = process.argv[2];
var index = binarySearch(random_data, key);
if (index != null) {
    console.log("Value is located at index", index);
}
else {
    console.log("Value not found");
}
