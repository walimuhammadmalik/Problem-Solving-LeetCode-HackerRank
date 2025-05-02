/**
 * @param {character[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
var solve = function(board) {
    if (board.length === 0 || board[0].length === 0) return;

    const rows = board.length;
    const cols = board[0].length;

    const dfs = (r, c) => {
        if (r < 0 || c < 0 || r >= rows || c >= cols || board[r][c] !== 'O') return;
        board[r][c] = '#'; // Temporarily mark the safe 'O'
        dfs(r + 1, c);
        dfs(r - 1, c);
        dfs(r, c + 1);
        dfs(r, c - 1);
    };

    // Step 1: Run DFS from all 'O's on the border
    for (let i = 0; i < rows; i++) {
        dfs(i, 0);
        dfs(i, cols - 1);
    }
    for (let j = 0; j < cols; j++) {
        dfs(0, j);
        dfs(rows - 1, j);
    }

    // Step 2: Flip all 'O's to 'X' and all '#' back to 'O'
    for (let r = 0; r < rows; r++) {
        for (let c = 0; c < cols; c++) {
            if (board[r][c] === 'O') {
                board[r][c] = 'X';
            } else if (board[r][c] === '#') {
                board[r][c] = 'O';
            }
        }
    }
};
