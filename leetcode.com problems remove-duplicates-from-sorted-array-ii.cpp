class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size();

        int i = 2;  // Start from index 2, since the first two can remain the same
        
        for (int j = 2; j < nums.size(); j++) {
            if (nums[j] != nums[i - 2]) {  // Compare with the element two positions before
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};
