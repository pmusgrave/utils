function dlog(str) {
    if (process.env.DEBUG) {
        if (typeof str === 'object' && str !== null) {
            console.log(`${(new Date).toISOString()}: \n${JSON.stringify(str, null, "  ")}`);
        } else {
            console.log(`${(new Date).toISOString()}: ${str}`);
        }
    }
}

module.exports = {
    dlog,
};
