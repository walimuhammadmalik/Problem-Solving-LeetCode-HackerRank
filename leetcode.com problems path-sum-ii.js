/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} targetSum
 * @return {number[][]}
 */
var pathSum = function(root, targetSum) {
    const result = [];
    
    const dfs = (node, currentPath, remainingSum) => {
        if (!node) return;
        
        // Add the current node to the path
        currentPath.push(node.val);
        
        // Check if it's a leaf node and if the remaining sum equals the node's value
        if (!node.left && !node.right && remainingSum === node.val) {
            result.push([...currentPath]);
        } else {
            // Recursively check the left and right subtrees
            dfs(node.left, currentPath, remainingSum - node.val);
            dfs(node.right, currentPath, remainingSum - node.val);
        }
        
        // Backtrack: remove the current node from the path
        currentPath.pop();
    };
    
    dfs(root, [], targetSum);
    return result;
};
