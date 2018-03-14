const assert = require("chai").assert;

/******************************************************************************
BINARY SEARCH
******************************************************************************/
//console.log("Testing binary_search.js...");
const binary_search = require('../binary_search.js');

describe('binary_search', function() {
  it('binary search should return 42', function() {
    var random_data = new Array();
    var dataset_size = 1001;
    var i = 0;
    while (i <= dataset_size) {
        random_data.push(i);
        i += 1;
    }
    var key = 42;
    assert.equal(binary_search.binarySearch(random_data, key), key);
  })
})


/******************************************************************************
MERGESORT
******************************************************************************/
console.log('Testing merge sort...');
const mergesort = require('../mergesort.js');
var random_data = new Array();
var dataset_size = 100000;
var i = 0;
while (i < dataset_size) {
    random_data.push( Math.floor( Math.random() * dataset_size ) );
    i += 1;
}

var result = mergesort.mergeSort(random_data)

var success = true;
for (let i = 0; i < result.length - 1; i++) {
  if (result[i] > result[i+1]) {
    console.log("error");
    success = false;
  }
}
if (success == true){
  console.log("sort successful");
}
console.log('Done\n');

/******************************************************************************
QUICKSORT
******************************************************************************/
console.log('Testing quicksort...');
const quicksort = require('../quicksort.js').quicksort;
var random_data = new Array();
var dataset_size = 1000000;
var i = 0;
while (i < dataset_size) {
    random_data.push( Math.floor( Math.random() * dataset_size ) );
    i += 1;
}

quicksort(random_data, 0, random_data.length-1);
// console.log(random_data);
var success = true;
for (let i = 0; i < random_data.length - 1; i++) {
  if (random_data[i] > random_data[i+1]) {
    console.log("error");
    success = false;
  }
}
if (success == true){
  console.log("sort successful");
}
console.log('Done\n');

/******************************************************************************
BINARY SEARCH TREE
******************************************************************************/
console.log('Testing Binary Search Tree...');
const bst = require('../binarysearchtree.js');
console.log('Done\n');



// const hashtable = require('../hashtable_chaining.js');
// let arr = [0,1,2,3,4,5,6,7,8,9];
// hashtable.setHashParameters(3,4,17);
// console.log(hashtable.arrayToHashTable(arr, arr.length));
