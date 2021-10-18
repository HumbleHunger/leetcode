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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int a = 0;
        int b = 0;
        ListNode* cur1 = headA;
        ListNode* cur2 = headB;
        while (cur1 != NULL)
        {
            ++a;
            cur1 = cur1->next;
        }

        while (cur2 != NULL)
        {
            ++b;
            cur2 = cur2->next;        
        }

        cur1 = headA;
        cur2 = headB;

        int n = a - b;
        if (n < 0)
        {
            n = -n;
            swap(cur1, cur2);
        }

        while (n--)
        {
            cur1 = cur1->next;
        }
        
        while (cur1 != cur2 && cur1 != NULL)
        {
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return cur1;
    }
};
