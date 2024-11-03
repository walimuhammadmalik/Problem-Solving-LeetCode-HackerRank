#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Place each number in its right position
        for (int i = 0; i < n; i++) {
            // While the number is in the range [1, n] and it's not in the right position
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                // Swap the numbers
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        
        // Step 2: Find the first missing positive
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1; // The first missing positive is i + 1
            }
        }
        
        // If all positions are filled correctly, the missing positive is n + 1
        return n + 1;
    }
};
