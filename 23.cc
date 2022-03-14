#include <bits/stdc++.h>

using namespace std;

	struct ListNode {
      int val;
      ListNode* next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

bool cmp(int a, int b) {
	return a > b;
}

class Solution {
public:
		

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, cmp> pq;
				for (auto head : lists) {
					ListNode* cur = head;
					while (cur != nullptr) {
						pq.push(cur->val);
						cur = cur->next;
					}
				}
				ListNode* node = nullptr;
				while (!pq.empty()) {
					int val = pq.top();
					pq.pop();
					node->next = new ListNode(val);
					node = node->next;
				}
				return node->next;
    }
};

int main() {

}