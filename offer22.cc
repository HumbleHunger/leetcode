class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (k--) fast = fast->next;
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};