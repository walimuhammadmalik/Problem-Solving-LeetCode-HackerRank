function numDistinct(s: string, t: string): number {
    const m = s.length;
    const n = t.length;

    // Create a 2D array to store the results of subproblems
    const dp: number[][] = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));

    // If t is an empty string, there is exactly one subsequence of s which equals t (the empty subsequence)
    for (let i = 0; i <= m; i++) {
        dp[i][0] = 1;
    }

    // Fill the DP table
    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            // If the characters match, we have two options:
            // 1. Consider the current character of s and move to the next character in both s and t
            // 2. Ignore the current character of s and keep looking for a match for the current character of t
            if (s[i - 1] === t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            } else {
                // If the characters don't match, we can only ignore the current character of s
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // The answer is in the bottom-right corner of the DP table
    return dp[m][n];
}

// Example usage:
const s = "rabbbit";
const t = "rabbit";
console.log(numDistinct(s, t));  // Output: 3
