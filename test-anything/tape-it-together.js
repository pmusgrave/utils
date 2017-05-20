var fancify = require(process.argv[2]);
var test = require('tape');

test('str wrapped in fancified text', function (t) {
  t.ok(fancify('Hello'), 'should return ~*~Hello~*~');
  t.ok(fancify('Hello', true), 'should return ~*~HELLO~*~');
  t.ok(fancify('Hello', false, '!'), 'should return ~!~Hello~!~');
  t.end();
})
