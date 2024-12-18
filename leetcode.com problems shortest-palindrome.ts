function shortestPalindrome(s: string): string {
    // Reverse the string
    const rev_s = s.split('').reverse().join('');
    
    // Combine the string with its reverse using a separator
    const combined = s + '#' + rev_s;
    
    // KMP algorithm to compute the partial match table (LPS array)
    const lps = computeLPS(combined);
    
    // The length of the longest palindrome suffix
    const len = lps[lps.length - 1];
    
    // Prepend the characters from rev_s that are not part of the palindrome suffix
    return rev_s.substring(0, rev_s.length - len) + s;
}

function computeLPS(str: string): number[] {
    const lps = new Array(str.length).fill(0);
    let len = 0; // length of the previous longest prefix suffix
    let i = 1;
    
    while (i < str.length) {
        if (str[i] === str[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len !== 0) {
                len = lps[len - 1]; // Fall back to the previous longest prefix suffix
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    
    return lps;
}
