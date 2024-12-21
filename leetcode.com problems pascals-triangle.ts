function generate(numRows: number): number[][] {
    // Initialize an array to hold the rows of Pascal's Triangle
    const triangle: number[][] = [];

    // Loop through each row
    for (let row = 0; row < numRows; row++) {
        // Initialize the current row with 1s
        const newRow: number[] = new Array(row + 1).fill(1);

        // Fill in the non-border values
        for (let col = 1; col < row; col++) {
            newRow[col] = triangle[row - 1][col - 1] + triangle[row - 1][col];
        }

        // Add the current row to the triangle
        triangle.push(newRow);
    }

    return triangle;
}

// Example usage:
const numRows = 5;
const result = generate(numRows);
console.log(result);
