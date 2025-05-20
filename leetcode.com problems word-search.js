/**
 * @param {character[][]} board
 * @param {string} word
 * @return {boolean}
 */
var exist = function(board, word) {
    const rows = board.length;
    const cols = board[0].length;

    const dfs = (i, j, index) => {
        // If all characters are matched
        if (index === word.length) return true;

        // If out of bounds or character doesn't match
        if (i < 0 || i >= rows || j < 0 || j >= cols || board[i][j] !== word[index]) return false;

        // Mark the current cell as visited
        const temp = board[i][j];
        board[i][j] = '#';

        // Explore all 4 directions
        const found = dfs(i+1, j, index+1) ||
                      dfs(i-1, j, index+1) ||
                      dfs(i, j+1, index+1) ||
                      dfs(i, j-1, index+1);

        // Restore the current cell
        board[i][j] = temp;

        return found;
    };

    // Start DFS from each cell
    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            if (dfs(i, j, 0)) return true;
        }
    }

    return false;
};
