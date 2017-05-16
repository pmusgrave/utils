// converts an array to a hash table, using hashing with chaining
var arr = [0,1,2,3,4,5,6,7,8,9];
var hashtable = [];

function hash (key) {
  var a = 3; // a and b are coefficients for a linear transformation
  var b = 4;
  var m = arr.length;
  var p = 17; // p must be a prime number >= max value in array - 1
  var hash_value = (((a * key + b) % p) % m);
  return hash_value;
}

for (var i = 0; i < arr.length; i++) {
  var current_hash = hash(arr[i]);
  if (hashtable[current_hash] == null){
    hashtable[current_hash] = arr[i];
  }
  else if (Array.isArray(hashtable[current_hash])){
    hashtable[current_hash].push(arr[i]);
  }
  else {
    hashtable[current_hash] = [hashtable[current_hash], arr[i]];
  }
}

console.log(hashtable);
