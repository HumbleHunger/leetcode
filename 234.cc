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
    ListNode* reverse(ListNode* node) {
        ListNode* pre = nullptr;
        ListNode* cur = node;
        while (cur != nullptr) {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
            if (fast) fast = fast->next;
        }
        fast = reverse(slow);
        while (fast && head) {
            if (fast->val != head->val) {
                return false;
            }
            fast = fast->next;
            head = head->next;
        }
        return true;
    }
};