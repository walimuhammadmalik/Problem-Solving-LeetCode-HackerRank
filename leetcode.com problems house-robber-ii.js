/**
 * @param {number[]} nums
 * @return {number}
 */
var rob = function(nums) {
    if (nums.length === 0) return 0;
    if (nums.length === 1) return nums[0];

    const robLinear = (arr) => {
        let prev1 = 0, prev2 = 0;
        for (let num of arr) {
            let temp = Math.max(prev1, prev2 + num);
            prev2 = prev1;
            prev1 = temp;
        }
        return prev1;
    };

    // Exclude first house OR last house
    return Math.max(robLinear(nums.slice(1)), robLinear(nums.slice(0, nums.length - 1)));
};
