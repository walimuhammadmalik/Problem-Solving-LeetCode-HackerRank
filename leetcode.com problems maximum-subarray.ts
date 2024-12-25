function maxSubArray(nums: number[]): number {
    // Initialize the maximum sum to the first element
    let maxSum = nums[0];
    // Initialize the current sum to the first element
    let currentSum = nums[0];

    // Iterate through the array starting from the second element
    for (let i = 1; i < nums.length; i++) {
        // Update the current sum by taking the maximum of the current element
        // and the sum of the current element and the current sum
        currentSum = Math.max(nums[i], currentSum + nums[i]);
        // Update the maximum sum if the current sum is greater
        maxSum = Math.max(maxSum, currentSum);
    }

    // Return the maximum sum found
    return maxSum;
}

// Example usage:
const nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4];
console.log(maxSubArray(nums)); // Output: 6
