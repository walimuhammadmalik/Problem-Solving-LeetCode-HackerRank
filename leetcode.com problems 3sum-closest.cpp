class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // Sort the array
        sort(nums.begin(), nums.end());
        
        int closestSum = nums[0] + nums[1] + nums[2]; // Initialize with the first triplet
        
        // Iterate through each number
        for (int i = 0; i < nums.size() - 2; ++i) {
            int left = i + 1;  // Second pointer
            int right = nums.size() - 1;  // Third pointer
            
            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];
                
                // If the current sum is exactly equal to the target, return it
                if (currentSum == target) {
                    return currentSum;
                }
                
                // If the current sum is closer to the target, update the closestSum
                if (abs(currentSum - target) < abs(closestSum - target)) {
                    closestSum = currentSum;
                }
                
                // Move pointers to try to get closer to the target
                if (currentSum < target) {
                    ++left;
                } else {
                    --right;
                }
            }
        }
        
        return closestSum; // Return the closest sum found
    }
};
