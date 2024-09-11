class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reachable = 0;  // This will keep track of the farthest index we can reach

        // Traverse through the array
        for (int i = 0; i < nums.size(); i++) {
            // If the current index is beyond the reachable index, return false
            if (i > reachable) {
                return false;
            }
            
            // Update the farthest reachable index
            reachable = max(reachable, i + nums[i]);
        }

        // If we have traversed the array, we can reach the last index
        return true;
    }
};
