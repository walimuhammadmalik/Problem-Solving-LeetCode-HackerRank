class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0, threes = 0;

        for (int num : nums) {
            // Update twos with the bits where a number appeared twice
            twos |= ones & num;
            // Update ones with the bits where a number appeared once
            ones ^= num;
            // Compute threes where both ones and twos have the same bits (appears three times)
            threes = ones & twos;

            // Remove the bits that appeared three times
            ones &= ~threes;
            twos &= ~threes;
        }

        return ones; // The number that appeared only once will remain in 'ones'
    }
};
