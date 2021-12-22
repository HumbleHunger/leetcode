 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
			ListNode* cur1 = headA;
			ListNode* cur2 = headB;

			int count1 = 0;
			int count2 = 0;
			while (cur1) {
				count1++;
				cur1 = cur1->next;
			}
			while (cur2) {
				count2++;
				cur2 = cur2->next;
			}
			int len = 0;
			if (count1 > count2) len = count1 - count2;
			else len = count2 - count1;

			cur1 = headA;
			cur2 = headB;
			if (count1 > count2) {
				while (len--) {
					cur1 = cur1->next;
				}
			} else {
				while (len--) {
					cur2 = cur2->next;
				}
			}
			while (cur1 != cur2) {
				cur1 = cur1->next;
				cur2 = cur2->next;
			}
			return cur1;
    }
};