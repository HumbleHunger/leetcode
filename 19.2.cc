 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
			ListNode* dhead = new ListNode(0, head);

			ListNode* fast = dhead;
			ListNode* slow = dhead;

			while (n--) {
				fast = fast->next;
			}

			ListNode* node = nullptr;
			while (fast) {
				fast = fast->next;
				node = slow;
				slow = slow->next;
			}

			node->next = slow->next;
			return head;
    }
};