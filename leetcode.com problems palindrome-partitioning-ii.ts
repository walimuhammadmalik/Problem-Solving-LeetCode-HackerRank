function minCut(s: string): number {
    const n = s.length;
    if (n <= 1) return 0;

    // Initialize the dp array to store the minimum cuts needed for substring s[0:i]
    const dp = new Array(n).fill(0).map((_, i) => i);

    // Initialize the palindrome table to store whether s[i:j] is a palindrome
    const isPalindrome = new Array(n).fill(false).map(() => new Array(n).fill(false));

    for (let end = 0; end < n; end++) {
        for (let start = 0; start <= end; start++) {
            if (s[start] === s[end] && (end - start <= 2 || isPalindrome[start + 1][end - 1])) {
                isPalindrome[start][end] = true;
                if (start === 0) {
                    dp[end] = 0;
                } else {
                    dp[end] = Math.min(dp[end], dp[start - 1] + 1);
                }
            }
        }
    }

    return dp[n - 1];
}

// Example usage:
const s = "aab";
console.log(minCut(s)); // Output: 1
