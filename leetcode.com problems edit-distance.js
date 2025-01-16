/**
 * @param {string} word1
 * @param {string} word2
 * @return {number}
 */
var minDistance = function(word1, word2) {
    const m = word1.length;
    const n = word2.length;

    // Create a DP table with dimensions (m+1) x (n+1)
    const dp = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));

    // Initialize the base cases
    for (let i = 0; i <= m; i++) {
        dp[i][0] = i; // Deleting all characters from word1
    }
    for (let j = 0; j <= n; j++) {
        dp[0][j] = j; // Inserting all characters into word1
    }

    // Fill the DP table
    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            if (word1[i - 1] === word2[j - 1]) {
                // Characters match; no operation needed
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                // Characters don't match; take the minimum of the three operations
                dp[i][j] = 1 + Math.min(
                    dp[i - 1][j],    // Delete
                    dp[i][j - 1],    // Insert
                    dp[i - 1][j - 1] // Replace
                );
            }
        }
    }

    // Return the value in the bottom-right corner
    return dp[m][n];
};
