class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow)
            {
                ListNode* ptr1 = head;
                ListNode* ptr2 = fast;
                while (ptr1 != ptr2)
                {
                    ptr1 = ptr1->next;
                    ptr2 = ptr2->next;
                }
                return ptr1;
            }
        }
        return NULL;
    }
};