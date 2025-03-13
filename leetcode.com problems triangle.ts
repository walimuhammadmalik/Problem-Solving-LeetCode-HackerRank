function minimumTotal(triangle: number[][]): number {
    let n = triangle.length;
    let dp = triangle[n - 1].slice(); // Copy the last row

    // Start from the second last row and move upwards
    for (let row = n - 2; row >= 0; row--) {
        for (let col = 0; col < triangle[row].length; col++) {
            dp[col] = triangle[row][col] + Math.min(dp[col], dp[col + 1]);
        }
    }

    return dp[0]; // The top element contains the minimum path sum
}
