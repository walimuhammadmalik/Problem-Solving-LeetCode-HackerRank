function largestRectangleArea(heights: number[]): number {
    // Initialize maximum area as 0
    let maxArea = 0;
    // Stack to store indices of the histogram bars
    const stack: number[] = [];

    // Iterate through all bars of the histogram
    for (let i = 0; i <= heights.length; i++) {
        // Get the current height or 0 if we are at the end
        const currentHeight = (i === heights.length) ? 0 : heights[i];

        // If the stack is not empty and the current height is less than the height of the bar at the top of the stack
        while (stack.length > 0 && currentHeight < heights[stack[stack.length - 1]]) {
            // Pop the top of the stack
            const height = heights[stack.pop()!];
            // Determine the width of the rectangle
            const width = stack.length === 0 ? i : i - stack[stack.length - 1] - 1;
            // Calculate the area and update the maximum area
            maxArea = Math.max(maxArea, height * width);
        }
        // Push current index to the stack
        stack.push(i);
    }

    return maxArea;
}

// Example usage
const heights = [2, 1, 5, 6, 2, 3];
console.log(largestRectangleArea(heights)); // Output: 10
