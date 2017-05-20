var emotify_dir = process.argv[2];
var test_string = process.argv[3];

var emotify = require(emotify_dir);
console.log(emotify(test_string));
