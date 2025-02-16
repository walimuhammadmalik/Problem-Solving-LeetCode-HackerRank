/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function deleteDuplicates(head: ListNode | null): ListNode | null {
    // Edge case: if the list is empty, return null
    if (!head) {
        return null;
    }

    let current = head;
    
    // Traverse the linked list
    while (current && current.next) {
        // If current node's value equals next node's value, skip the next node
        if (current.val === current.next.val) {
            current.next = current.next.next;
        } else {
            // Otherwise, move to the next node
            current = current.next;
        }
    }
    
    return head;
}
