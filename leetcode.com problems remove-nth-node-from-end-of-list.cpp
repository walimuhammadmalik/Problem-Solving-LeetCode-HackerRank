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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node to simplify edge cases like removing the first node
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        
        // Move the fast pointer n+1 steps ahead so that the slow pointer will point to the previous node of the target node
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }
        
        // Move both fast and slow pointers until fast reaches the end
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        
        // Remove the nth node from the end
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        
        // Free memory of the node to be deleted
        delete nodeToDelete;
        
        // Return the new head (which might have changed if the first node was removed)
        ListNode* newHead = dummy->next;
        delete dummy; // Delete the dummy node
        return newHead;
    }
};
