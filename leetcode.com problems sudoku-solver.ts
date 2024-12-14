/**
 Do not return anything, modify board in-place instead.
 */
// function solveSudoku(board: string[][]): void {
    
// };

function solveSudoku(board: string[][]): void {
    function backtrack(): boolean {
        for (let row = 0; row < 9; row++) {
            for (let col = 0; col < 9; col++) {
                if (board[row][col] === '.') {  // Find an empty cell
                    for (let num = 1; num <= 9; num++) {
                        const numStr = num.toString();
                        if (isValid(board, row, col, numStr)) {
                            board[row][col] = numStr;  // Try this number

                            if (backtrack()) {  // Recursively try to solve
                                return true;
                            }

                            board[row][col] = '.';  // Backtrack if no solution
                        }
                    }

                    return false;  // No valid number found, backtrack
                }
            }
        }

        return true;  // If all cells are filled correctly
    }

    backtrack();
}

function isValid(board: string[][], row: number, col: number, num: string): boolean {
    // Check row
    for (let c = 0; c < 9; c++) {
        if (board[row][c] === num) {
            return false;
        }
    }

    // Check column
    for (let r = 0; r < 9; r++) {
        if (board[r][col] === num) {
            return false;
        }
    }

    // Check 3x3 subgrid
    const startRow = Math.floor(row / 3) * 3;
    const startCol = Math.floor(col / 3) * 3;
    for (let r = startRow; r < startRow + 3; r++) {
        for (let c = startCol; c < startCol + 3; c++) {
            if (board[r][c] === num) {
                return false;
            }
        }
    }

    return true;
}
