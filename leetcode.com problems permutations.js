/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permute = function(nums) {
    const result = [];

    const backtrack = (start) => {
        if (start === nums.length) {
            result.push([...nums]);
            return;
        }

        for (let i = start; i < nums.length; i++) {
            // Swap the current element with the start element
            [nums[start], nums[i]] = [nums[i], nums[start]];
            
            // Recursively generate permutations for the next part of the array
            backtrack(start + 1);
            
            // Swap back to restore the original array
            [nums[start], nums[i]] = [nums[i], nums[start]];
        }
    };

    backtrack(0);
    return result;
};
