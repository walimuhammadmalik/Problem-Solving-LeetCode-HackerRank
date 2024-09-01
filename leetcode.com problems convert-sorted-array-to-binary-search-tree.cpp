/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // Call the helper function to construct the BST
        return buildBST(nums, 0, nums.size() - 1);
    }
    
private:
    TreeNode* buildBST(vector<int>& nums, int left, int right) {
        // Base case: if left index exceeds right, return nullptr
        if (left > right) {
            return nullptr;
        }
        
        // Find the middle element of the current subarray
        int mid = left + (right - left) / 2;
        
        // Create a new TreeNode with the middle element
        TreeNode* root = new TreeNode(nums[mid]);
        
        // Recursively build the left and right subtrees
        root->left = buildBST(nums, left, mid - 1);
        root->right = buildBST(nums, mid + 1, right);
        
        // Return the root of the subtree
        return root;
    }
};
