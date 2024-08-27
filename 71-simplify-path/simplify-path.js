/**
 * @param {string} path
 * @return {string}
 */
var simplifyPath = function(path) {
    const c = path.split('/').filter(x => x !== '' && x !== '.');
    const t = [];
    for (const x of c) {
        if (x === '..') {
            if (t.length > 0) {
                t.pop();
            }
        } else {
            t.push(x);
        }
    }
    return '/' + t.join('/');
};