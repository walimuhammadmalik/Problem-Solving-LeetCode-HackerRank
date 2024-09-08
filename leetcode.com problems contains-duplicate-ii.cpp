class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> numMap;  // stores the element and its latest index
        
        for (int i = 0; i < nums.size(); i++) {
            if (numMap.find(nums[i]) != numMap.end()) {
                // Check the distance between the indices
                if (i - numMap[nums[i]] <= k) {
                    return true;  // Found nearby duplicate
                }
            }
            // Update the index of the current element
            numMap[nums[i]] = i;
        }
        
        return false;  // No nearby duplicate found
    }
};
