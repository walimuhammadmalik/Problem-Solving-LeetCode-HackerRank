/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;  // Edge cases
        
        // Step 1: Calculate the length of the list and make it circular
        ListNode* current = head;
        int length = 1;  // Start counting from head
        while (current->next) {
            current = current->next;
            length++;
        }
        
        // Now 'current' is at the last node. Connect it to the head.
        current->next = head;
        
        // Step 2: Find the new tail and head
        k = k % length;  // In case k is larger than the length of the list
        int stepsToNewTail = length - k;
        current = head;
        
        for (int i = 1; i < stepsToNewTail; i++) {  // Find the new tail (1-based)
            current = current->next;
        }
        
        // The new head is the node after the new tail
        ListNode* newHead = current->next;
        current->next = nullptr;  // Break the circular list
        
        return newHead;
    }
};
