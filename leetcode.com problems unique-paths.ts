function uniquePaths(m: number, n: number): number {
    // Create a 2D array to store the number of unique paths to each cell.
    const dp: number[][] = Array.from({ length: m }, () => Array(n).fill(1));
    
    // Iterate through the grid starting from (1, 1) (since (0, 0) is already initialized).
    for (let i = 1; i < m; i++) {
        for (let j = 1; j < n; j++) {
            // The number of unique paths to dp[i][j] is the sum of paths from the cell above and the cell to the left.
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    
    // The bottom-right corner will hold the number of unique paths to that cell.
    return dp[m - 1][n - 1];
}
