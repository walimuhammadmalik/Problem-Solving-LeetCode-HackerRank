function solveNQueens(n: number): string[][] {
    const results: string[][] = [];
    const board: string[] = new Array(n).fill(".").map(() => ".".repeat(n));

    // Helper arrays to track columns and diagonals
    const columns: boolean[] = new Array(n).fill(false);
    const diag1: boolean[] = new Array(2 * n - 1).fill(false);  // For diagonals from top-left to bottom-right
    const diag2: boolean[] = new Array(2 * n - 1).fill(false);  // For diagonals from top-right to bottom-left

    function backtrack(row: number): void {
        if (row === n) {
            // We have placed all queens, add the current board configuration to results
            results.push([...board]); // Using spread to make a copy of the board
            return;
        }

        for (let col = 0; col < n; col++) {
            // Check if the column or diagonals are already occupied
            if (columns[col] || diag1[row - col + n - 1] || diag2[row + col]) {
                continue;
            }

            // Place the queen
            columns[col] = diag1[row - col + n - 1] = diag2[row + col] = true;
            board[row] = board[row].substr(0, col) + 'Q' + board[row].substr(col + 1);

            // Recurse to the next row
            backtrack(row + 1);

            // Backtrack: remove the queen and mark the column and diagonals as free
            columns[col] = diag1[row - col + n - 1] = diag2[row + col] = false;
            board[row] = board[row].substr(0, col) + '.' + board[row].substr(col + 1);
        }
    }

    // Start the backtracking process from the first row
    backtrack(0);
    return results;
}
