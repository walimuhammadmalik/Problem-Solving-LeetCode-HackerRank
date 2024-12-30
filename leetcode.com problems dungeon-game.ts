function calculateMinimumHP(dungeon: number[][]): number {
    const rows = dungeon.length;
    const cols = dungeon[0].length;
    
    // Create a 2D array to store the minimum health needed at each cell
    const dp = Array.from({ length: rows }, () => Array(cols).fill(0));

    // Start from the bottom-right corner of the dungeon
    dp[rows - 1][cols - 1] = Math.max(1, 1 - dungeon[rows - 1][cols - 1]);

    // Fill the last column
    for (let i = rows - 2; i >= 0; i--) {
        dp[i][cols - 1] = Math.max(1, dp[i + 1][cols - 1] - dungeon[i][cols - 1]);
    }

    // Fill the last row
    for (let j = cols - 2; j >= 0; j--) {
        dp[rows - 1][j] = Math.max(1, dp[rows - 1][j + 1] - dungeon[rows - 1][j]);
    }

    // Fill the rest of the dp array
    for (let i = rows - 2; i >= 0; i--) {
        for (let j = cols - 2; j >= 0; j--) {
            const minHealthOnExit = Math.min(dp[i + 1][j], dp[i][j + 1]);
            dp[i][j] = Math.max(1, minHealthOnExit - dungeon[i][j]);
        }
    }

    // The answer is the minimum health needed at the start cell
    return dp[0][0];
}

// Example usage:
const dungeon = [
    [-2, -3, 3],
    [-5, -10, 1],
    [10, 30, -5]
];
console.log(calculateMinimumHP(dungeon)); // Output: 7
