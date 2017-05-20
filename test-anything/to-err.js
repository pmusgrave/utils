var feedCat = require(process.argv[2]);
var test = require('tape');

test('feedCat', function(t) {
  t.ok(feedCat('str'), 'should return yum');
  t.throws(function () {
    feedCat('chocolate');
  })
  t.end();
})
