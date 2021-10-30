#include <bits/stdc++.h>

using namespace std;

class MyStack {
public:
	deque<int> dq1;
	deque<int> dq2;

    MyStack() {

    }
    
    void push(int x) {
		dq1.push_back(x);
    }
    
    int pop() {
		while (dq1.size() > 1)
		{
			dq2.push_back(dq1.front());
			dq1.pop_front();
		}
		int ret = dq1.front();
		dq1.pop_front();
		while (!dq2.empty())
		{
			dq1.push_back(dq2.front());
			dq2.pop_front();
		}
		return ret;
    }
    
    int top() {
		int ret = pop();
		dq1.push_back(ret);
		return ret;
    }
    
    bool empty() {
		return dq1.empty();
    }
};