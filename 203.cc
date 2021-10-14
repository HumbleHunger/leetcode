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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* pre = head;
        ListNode* cur = head;
        while (cur)
        {
            if (cur->val == val)
            {
                if (cur == head)
                {
                    head = cur->next;
                }
                pre->next = cur->next;
                cur = cur->next;
                continue;
            }
            pre = cur;
            cur = cur->next;
        }
        return head;
    }
};