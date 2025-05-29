/**
 * // Definition for a _Node.
 * function _Node(val, left, right, next) {
 *    this.val = val === undefined ? null : val;
 *    this.left = left === undefined ? null : left;
 *    this.right = right === undefined ? null : right;
 *    this.next = next === undefined ? null : next;
 * };
 */

/**
 * @param {_Node} root
 * @return {_Node}
 */
var connect = function(root) {
    if (!root) return null;

    let leftmost = root;

    while (leftmost.left) {
        let head = leftmost;

        while (head) {
            // Connect left and right children
            head.left.next = head.right;

            // Connect right child to next node's left child
            if (head.next) {
                head.right.next = head.next.left;
            }

            head = head.next;
        }

        leftmost = leftmost.left;
    }

    return root;
};
