#include <bits/stdc++.h>

using namespace std;

	struct ListNode {
	int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
			ListNode* node = new ListNode(0, head);
			ListNode* pre = node;
			node = head;
			head = pre;
			while (node != nullptr) {
				if (node->val == val) {
					pre->next = node->next;
					node = node->next;
					continue;
				}
				pre = node;
				node = node->next;
			}
			return head;
    }
};