/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }

        // Two pointers: slow moves one step, fast moves two steps
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;          // slow pointer moves 1 step
            fast = fast->next->next;    // fast pointer moves 2 steps
            
            // If slow and fast meet, there's a cycle
            if (slow == fast) {
                return true;
            }
        }

        // If fast reaches the end, there's no cycle
        return false;
    }
};
