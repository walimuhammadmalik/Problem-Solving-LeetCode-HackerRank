/**
 * @param {string} s
 * @return {number}
 */
var maxDifference = function(s) {
    // Step 1: Count frequency of each character in the string
    const freq = {};
    for (let char of s) {
        freq[char] = (freq[char] || 0) + 1;
    }

    // Step 2: Separate characters with odd and even frequencies
    let oddFreq = [];
    let evenFreq = [];
    for (let count of Object.values(freq)) {
        if (count % 2 === 0) {
            evenFreq.push(count);
        } else {
            oddFreq.push(count);
        }
    }

    // Step 3: Calculate the maximum difference
    let maxDiff = -Infinity;
    for (let odd of oddFreq) {
        for (let even of evenFreq) {
            maxDiff = Math.max(maxDiff, odd - even);
        }
    }

    return maxDiff;
};

// Example 1:
console.log(maxDifference("aaaaabbc")); // Output: 3

// Example 2:
console.log(maxDifference("abcabcab")); // Output: 1
