class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if (nums.empty()) return result;
        
        int start = 0; // Start index of a potential range
        
        for (int i = 1; i <= nums.size(); ++i) {
            // If it's the end of the array or the current number is not consecutive
            if (i == nums.size() || nums[i] != nums[i-1] + 1) {
                if (start == i - 1) {
                    // Single element range
                    result.push_back(to_string(nums[start]));
                } else {
                    // Range with more than one element
                    result.push_back(to_string(nums[start]) + "->" + to_string(nums[i-1]));
                }
                start = i; // Update the start index for the next range
            }
        }
        
        return result;
    }
};
