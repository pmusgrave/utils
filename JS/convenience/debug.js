require('dotenv').config();
function dlog(str) {
    if (process.env.DEBUG) {
        console.log(`${(new Date).toISOString()}: ${str}}`);
    }
}

module.exports = {
    dlog,
};
