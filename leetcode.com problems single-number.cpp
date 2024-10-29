#include <vector>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int result = 0;
        for (int num : nums) {
            result ^= num;  // XOR the current number with the result
        }
        return result; // The result will be the single number
    }
};
