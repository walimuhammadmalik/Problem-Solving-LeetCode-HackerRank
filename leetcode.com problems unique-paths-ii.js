/**
 * @param {number[][]} obstacleGrid
 * @return {number}
 */
var uniquePathsWithObstacles = function(obstacleGrid) {
    let m = obstacleGrid.length, n = obstacleGrid[0].length;
    
    // Edge case: If the start or end cell has an obstacle, no paths exist
    if (obstacleGrid[0][0] === 1 || obstacleGrid[m-1][n-1] === 1) return 0;
    
    let dp = new Array(n).fill(0);
    dp[0] = 1; // Starting point

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (obstacleGrid[i][j] === 1) {
                dp[j] = 0; // No paths can go through an obstacle
            } else if (j > 0) {
                dp[j] += dp[j - 1]; // Sum of top (previous row) and left (previous column)
            }
        }
    }

    return dp[n - 1]; // The bottom-right cell contains the total paths
};
