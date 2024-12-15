function maximalRectangle(matrix: string[][]): number {
    if (matrix.length === 0 || matrix[0].length === 0) return 0;

    const rows = matrix.length;
    const cols = matrix[0].length;
    
    // Create an array to store heights of histograms for each row
    let heights = new Array(cols).fill(0);
    let maxArea = 0;

    // Function to calculate the maximal rectangle in a histogram
    function largestRectangleInHistogram(heights: number[]): number {
        let stack: number[] = [];
        let maxAreaInHistogram = 0;

        for (let i = 0; i <= heights.length; i++) {
            while (stack.length > 0 && (i === heights.length || heights[i] < heights[stack[stack.length - 1]])) {
                let height = heights[stack.pop()!];
                let width = stack.length === 0 ? i : i - stack[stack.length - 1] - 1;
                maxAreaInHistogram = Math.max(maxAreaInHistogram, height * width);
            }
            stack.push(i);
        }
        
        return maxAreaInHistogram;
    }

    // Iterate over each row
    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            // If the current cell is '1', increase the height, otherwise reset to 0
            heights[j] = matrix[i][j] === '1' ? heights[j] + 1 : 0;
        }
        
        // Calculate the maximal rectangle for this row as the base using histogram method
        maxArea = Math.max(maxArea, largestRectangleInHistogram(heights));
    }

    return maxArea;
}
