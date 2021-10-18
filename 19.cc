#include <bits/stdc++.h>

using namespace std;

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
		ListNode* dhead = new ListNode;
        dhead->next = head;
        ListNode* slow = dhead;
        ListNode* fast = dhead;

        while (n-- && fast != NULL)
        {
            fast = fast->next;
        }

        fast = fast->next;

		while (fast != NULL)
		{
			fast = fast->next;
			slow = slow->next;
		}

        slow->next = slow->next->next;
		return dhead->next;
	}

};