#include <bits/stdc++.h>

using namespace std;

class MyLinkedList {
public:
		struct ListNode {
			int val_;
			ListNode* next_;
			ListNode(int val, ListNode* next) :val_(val), next_(next) {}
		};

    MyLinkedList() {
			head = new ListNode(0, nullptr);
    }
    
    int get(int index) {
			ListNode* cur = head;
			for (int i = 0; i < index; ++i) {
				if (cur) cur = cur->next_;
			}
			if (cur && cur->next_) return cur->next_->val_;
			else return -1;
    }
    
    void addAtHead(int val) {

    }
    
    void addAtTail(int val) {
			ListNode* cur = head;
			while (cur->next_) {
				cur = cur->next_;
			}
			cur->next_ = new ListNode(val, nullptr);
    }
    
    void addAtIndex(int index, int val) {
			ListNode* cur = head;
			for (int i = 0; i < index; ++i) {
				if (cur) cur = cur->next_;
			}
			
    }
    
    void deleteAtIndex(int index) {

    }
private:
		int val;
		ListNode* head;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */