/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function(s) {
    // Step 1: Remove non-alphanumeric characters and convert to lowercase
    s = s.replace(/[^a-zA-Z0-9]/g, '').toLowerCase();
    
    // Step 2: Check if the string is equal to its reverse
    let reversed = s.split('').reverse().join('');
    
    return s === reversed;
};
