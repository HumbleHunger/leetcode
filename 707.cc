#include <bits/stdc++.h>

#include <iostream>

using namespace std;

class MyLinkedList
{
public:
	struct LinkedNode
	{
		int val_;
		LinkedNode* next_;
		LinkedNode() : val_(0), next_(NULL) {}
		LinkedNode(int val, LinkedNode* next) : val_(val), next_(next) {}
	};
	
	MyLinkedList()
		:	size_(0),
			dHead_(new LinkedNode(0, NULL))
	{
	}
	
	int get(int index)
	{
		if (index >= size_ || index < 0)
			return -1;
		LinkedNode* tmp = dHead_->next_;
		while (index--)
			tmp = tmp->next_;
		return tmp->val_;
	}

	void addAtHead(int val)
	{
		LinkedNode* tmp = new LinkedNode(val, dHead_->next_);
		dHead_->next_ = tmp;
		++size_;
	}

	void addAtTail(int val)
	{
		LinkedNode* tmp = dHead_;
		while (tmp->next_)
		{
			tmp = tmp->next_;
		}
		tmp->next_ = new LinkedNode(val, NULL);
		++size_;
	}

	void addAtIndex(int index, int val)
	{
        if (index > size_)
            return;
		LinkedNode* tmp = dHead_;
		while (index--)
		{
			tmp = tmp->next_;
		}
		tmp->next_ = new LinkedNode(val, tmp->next_);
		++size_;
	}

	void deleteAtIndex(int index)
	{
        if (index >= size_)
            return;
		LinkedNode* tmp = dHead_;
		while (index--)
		{
			tmp = tmp->next_;
		}
		LinkedNode* freenode = tmp->next_;
		tmp->next_ = tmp->next_->next_;
		--size_;
		delete(freenode);
	}
	void print()
	{
		LinkedNode* tmp = dHead_->next_;
		while (tmp->next_)
		{
			cout << tmp->val_ << " ";
			tmp = tmp->next_;
		}
		cout << tmp->val_ << " ";
	}
private:
	int size_;
	LinkedNode* dHead_;
};

int main()
{
	MyLinkedList linkedList;
	linkedList.addAtHead(7);
	linkedList.print();
	cout << endl;
	linkedList.addAtHead(2);
	linkedList.print();
	cout << endl;
	linkedList.addAtHead(1);
	linkedList.print();
	cout << endl;
	linkedList.addAtIndex(3,0);
	linkedList.print();
	cout << endl;
	linkedList.deleteAtIndex(2);  //现在链表是1-> 3
	linkedList.print();
	cout << endl;
	linkedList.addAtHead(6);
	linkedList.print();
	cout << endl;
	linkedList.addAtTail(4);
	linkedList.print();
	cout << endl;
	cout << linkedList.get(4);            //返回2
	linkedList.addAtHead(4);
	linkedList.print();
	cout << endl;
	linkedList.addAtIndex(5,0);
	linkedList.print();
	cout << endl;
	linkedList.addAtHead(6);
	linkedList.print();
	cout << endl;
	return 0;
}