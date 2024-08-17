/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode[]} lists
 * @return {ListNode}
 */
function ListNode(val, next) {
    this.val = (val === undefined ? 0 : val);
    this.next = (next === undefined ? null : next);
}

var mergeKLists = function(lists) {
    const minHeap = [];
    
    // Initialize the heap with the head of each list
    for (let list of lists) {
        while (list) {
            minHeap.push(list);
            list = list.next;
        }
    }
    
    // Sort the heap based on node values
    minHeap.sort((a, b) => a.val - b.val);
    
    // Create a dummy node to form the result linked list
    let dummy = new ListNode(0);
    let current = dummy;
    
    // Rebuild the merged linked list
    for (let node of minHeap) {
        current.next = node;
        current = current.next;
    }
    
    // Ensure the last node points to null
    current.next = null;
    
    return dummy.next;
};
