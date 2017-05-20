var import_function_dir = process.argv[2];
var isCoolNumber = require(import_function_dir);
var assert = require('assert');

assert(isCoolNumber(42) === true);
