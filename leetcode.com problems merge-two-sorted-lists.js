function ListNode(val, next) {
    this.val = (val === undefined ? 0 : val);
    this.next = (next === undefined ? null : next);
}

var mergeTwoLists = function(list1, list2) {
    // Create a dummy node to act as the start of the merged list
    let dummy = new ListNode(-1);
    let current = dummy;

    // Traverse both lists
    while (list1 !== null && list2 !== null) {
        // Compare the current nodes of both lists
        if (list1.val <= list2.val) {
            current.next = list1;  // Append list1's node
            list1 = list1.next;    // Move list1 to its next node
        } else {
            current.next = list2;  // Append list2's node
            list2 = list2.next;    // Move list2 to its next node
        }
        current = current.next; // Move current to the next position in the merged list
    }

    // Attach the remaining nodes from the list that is not yet exhausted
    current.next = (list1 !== null) ? list1 : list2;

    // Return the merged list, starting from the next node after dummy
    return dummy.next;
};
