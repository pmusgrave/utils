// const hashtable = require('./hashtable_chaining.js');
// let arr = [0,1,2,3,4,5,6,7,8,9];
// hashtable.setHashParameters(3,4,17);
// console.log(hashtable.arrayToHashTable(arr, arr.length));


const quicksort = require('./quicksort.js').quicksort;
var random_data = new Array();
var dataset_size = 1000000;
var i = 0
while (i < dataset_size) {
    random_data.push( Math.floor( Math.random() * dataset_size ) );
    i += 1;
}

quicksort(random_data, 0, random_data.length-1);
// console.log(random_data);
var success = true;
for (var i = 0; i < random_data.length - 1; i++) {
  if (random_data[i] > random_data[i+1]) {
    console.log("error");
    success = false;
  }
}
if (success == true){
  console.log("sort successful");
}
