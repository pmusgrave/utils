// converts an array to a hash table, using hashing with chaining
module.exports = function()
{
    function setHashParameters (a=3,b=4,p=17) {
        this.a = a; // a and b are coefficients for a linear transformation
        this.b = b;
        this.p = p; // p must be a prime number >= max value in array - 1
    }

    function hash (key, arraySize) {
      return ((this.a * key + this.b) % this.p);
    }

    function arrayToHashTable(arr) {
        let hashtable = [];
        for (let i = 0; i < arr.length; i++) {
          hashInsert(arr[i]);
        }
        return hashtable;
    }

    function hashInsert(hashtable, key) {
        let current_hash = hash(key);
        if (hashtable[current_hash] == null){
          hashtable[current_hash] = key;
        }
        else if (Array.isArray(hashtable[current_hash])){
          hashtable[current_hash].push(key);
        }
        else {
          hashtable[current_hash] = [hashtable[current_hash], key];
        }
    }

    function hashSearch(hashtable, key) {

    }

    function hashDelete(hashtable, key) {

    }

    return {
        setHashParameters: setHashParameters,
        arrayToHashTable: arrayToHashTable,
        hashSearch: hashSearch,
        deleteFromHashTable: deleteFromHashTable
    };
}();
