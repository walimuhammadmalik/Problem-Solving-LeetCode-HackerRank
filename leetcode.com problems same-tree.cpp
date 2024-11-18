/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Base case 1: Both are null, so they are the same
        if (!p && !q) {
            return true;
        }

        // Base case 2: One is null and the other is not, so they are different
        if (!p || !q) {
            return false;
        }

        // Base case 3: Check if the values are the same and recursively check
        // left and right subtrees
        return (p->val == q->val) && isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};
