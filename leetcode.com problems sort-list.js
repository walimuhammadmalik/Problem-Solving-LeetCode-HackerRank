/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var sortList = function(head) {
    if (!head || !head.next) return head;

    // Split the list into halves using slow/fast pointer
    let slow = head, fast = head, prev = null;
    while (fast && fast.next) {
        prev = slow;
        slow = slow.next;
        fast = fast.next.next;
    }
    // Disconnect left half from right
    prev.next = null;

    // Sort each half
    const l1 = sortList(head);
    const l2 = sortList(slow);

    // Merge the sorted halves
    return merge(l1, l2);
};

// Helper function to merge two sorted lists
function merge(l1, l2) {
    const dummy = new ListNode(0);
    let tail = dummy;

    while (l1 && l2) {
        if (l1.val < l2.val) {
            tail.next = l1;
            l1 = l1.next;
        } else {
            tail.next = l2;
            l2 = l2.next;
        }
        tail = tail.next;
    }

    tail.next = l1 || l2;
    return dummy.next;
}
