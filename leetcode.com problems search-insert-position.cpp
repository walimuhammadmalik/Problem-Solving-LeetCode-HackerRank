class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // If target is found, return the index
            if (nums[mid] == target) {
                return mid;
            }
            // If target is less than mid element, discard the right half
            else if (nums[mid] > target) {
                right = mid - 1;
            }
            // If target is greater than mid element, discard the left half
            else {
                left = mid + 1;
            }
        }
        // If the target is not found, left will be the insertion point
        return left;
    }
};
