/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    let maxLength = 0;
    let start = 0;
    let charMap = new Map();

    for (let end = 0; end < s.length; end++) {
        let char = s[end];
        
        // If the character is found in the map and is within the current window
        if (charMap.has(char) && charMap.get(char) >= start) {
            start = charMap.get(char) + 1; // Move the start right after the last occurrence
        }
        
        // Update the map with the current character and its index
        charMap.set(char, end);
        
        // Update the maxLength
        maxLength = Math.max(maxLength, end - start + 1);
    }
    
    return maxLength;
};
