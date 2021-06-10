let debug = require('./debug.js');

test("Print string", () => {
    process.env.DEBUG="true";
    console.log = jest.fn();
    debug.dlog("This should only print when I want it to.");
    expect(console.log.mock.calls[0][0]).not.toBe(undefined);
});

test("Don't print string", () => {
    process.env.DEBUG="";
    console.log = jest.fn();
    debug.dlog("This should only print when I want it to.");
    expect(console.log.mock.calls[0]).toBe(undefined);
});

test("Print object", () => {
    process.env.DEBUG="true";
    console.log = jest.fn();
    debug.dlog({ id: 42 });
    expect(console.log.mock.calls[0][0]).not.toBe(undefined);
});

test("Don't print object", () => {
    process.env.DEBUG="";
    console.log = jest.fn();
    debug.dlog({ id: 42 });
    expect(console.log.mock.calls[0]).toBe(undefined);
});
