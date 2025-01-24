/**
 * @param {number} n
 * @return {boolean}
 */
var isPowerOfTwo = function (n) {
    if (n == 1) return true;
    let two = 2;
    let no = 1;
    let power = 2;
    while (power < n) {
        power = 2;
        for (let i = 0; i < no; i++) {
            power = power * two;
        }
        no++;
    }
    if (power == n) {
        return true
    }
    return false;
};
