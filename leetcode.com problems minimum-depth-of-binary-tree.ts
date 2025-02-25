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

function minDepth(root: TreeNode | null): number {
    if (!root) return 0; // Empty tree case

    let queue: [TreeNode, number][] = [[root, 1]]; // Store node with depth

    while (queue.length) {
        let [node, depth] = queue.shift()!; // Dequeue

        // If it's a leaf node, return its depth
        if (!node.left && !node.right) return depth;

        if (node.left) queue.push([node.left, depth + 1]);
        if (node.right) queue.push([node.right, depth + 1]);
    }

    return 0; // This won't be reached, added for type safety
}
