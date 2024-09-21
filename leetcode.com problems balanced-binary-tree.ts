/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function isBalanced(root: TreeNode | null): boolean {
    // Helper function to get the height of the tree and check balance
    function checkHeight(node: TreeNode | null): number {
        // Base case: empty subtree is height 0
        if (node === null) return 0;

        // Recursively find the height of left and right subtrees
        let leftHeight = checkHeight(node.left);
        let rightHeight = checkHeight(node.right);

        // If either subtree is unbalanced, propagate the failure (-1)
        if (leftHeight === -1 || rightHeight === -1) return -1;

        // If the current node is unbalanced, return -1
        if (Math.abs(leftHeight - rightHeight) > 1) return -1;

        // Otherwise, return the height of the current node
        return Math.max(leftHeight, rightHeight) + 1;
    }

    // The tree is balanced if checkHeight does not return -1
    return checkHeight(root) !== -1;
}
