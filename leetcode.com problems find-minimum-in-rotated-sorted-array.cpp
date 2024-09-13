class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        // If the array is not rotated, return the first element
        if (nums[left] <= nums[right]) {
            return nums[left];
        }

        while (left < right) {
            int mid = left + (right - left) / 2;

            // If the mid element is greater than the right, the min is in the right part
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } 
            // Else the min is in the left part (including mid)
            else {
                right = mid;
            }
        }
        // After the loop, left == right and it will point to the minimum element
        return nums[left];
    }
};
