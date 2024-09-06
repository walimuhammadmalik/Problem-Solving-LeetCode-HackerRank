class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Pointers for nums1, nums2, and the merged array
        int p1 = m - 1;  // Pointer for the last initialized element in nums1
        int p2 = n - 1;  // Pointer for the last element in nums2
        int p = m + n - 1;  // Pointer for the last position in nums1
        
        // Start merging from the back of nums1
        while (p1 >= 0 && p2 >= 0) {
            // Place the larger element at the end of nums1
            if (nums1[p1] > nums2[p2]) {
                nums1[p] = nums1[p1];
                p1--;
            } else {
                nums1[p] = nums2[p2];
                p2--;
            }
            p--;
        }
        
        // If there are any remaining elements in nums2, copy them into nums1
        while (p2 >= 0) {
            nums1[p] = nums2[p2];
            p2--;
            p--;
        }
    }
};
