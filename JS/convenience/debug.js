function dlog(str) {
    if (process.env.DEBUG) {
        console.log(`${(new Date).toISOString()}: \n${JSON.stringify(str, null, "  ")}`);
    }
}

module.exports = {
    dlog,
};
