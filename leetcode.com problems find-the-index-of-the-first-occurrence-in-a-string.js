/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
var strStr = function(haystack, needle) {
    // If needle is an empty string, return 0
    if (needle === "") return 0;

    // Find the index of the first occurrence of needle in haystack
    return haystack.indexOf(needle);
};
