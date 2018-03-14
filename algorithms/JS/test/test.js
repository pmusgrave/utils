const chai = require("chai");
const assert = chai.assert;
const expect = chai.expect; // preference and tested with expect

chai.use(require("chai-sorted"));

/******************************************************************************
BINARY SEARCH
******************************************************************************/
//console.log("Testing binary_search.js...");
const binary_search = require('../binary_search.js').binarySearch;

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
    assert.equal(binary_search(random_data, key), key);
  })
})


/******************************************************************************
MERGESORT
******************************************************************************/
const mergesort = require('../mergesort.js');

describe('mergesort', function() {
  it('merge sort result should be sorted', function() {
    var random_data = new Array();
    var dataset_size = 100000;
    var i = 0;
    while (i < dataset_size) {
        random_data.push( Math.floor( Math.random() * dataset_size ) );
        i += 1;
    }
    var result = mergesort.mergeSort(random_data)
    expect(result).to.be.sorted()

  })
})


/*
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
*/

/******************************************************************************
QUICKSORT
******************************************************************************/
/*
console.log(random_data);
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
*/

const quicksort = require('../quicksort.js').quicksort;

describe('quicksort', function() {
  it('random_data should be sorted after calling quicksort (sorted in place)', function() {
    const quicksort = require('../quicksort.js').quicksort;
    var random_data = new Array();
    var dataset_size = 1000000;
    var i = 0;
    while (i < dataset_size) {
        random_data.push( Math.floor( Math.random() * dataset_size ) );
        i += 1;
    }

    quicksort(random_data, 0, random_data.length-1);
    expect(random_data).to.be.sorted()

  })
})

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
