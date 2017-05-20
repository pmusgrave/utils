var repeatCallback = require(process.argv[2]);
var test = require('tape');
test('repeatCallback(n, cb)', function (t) {
  t.plan(10);
  repeatCallback(10, function () {
    t.pass('callback called');
  })
})
