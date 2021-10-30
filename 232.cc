#include <bits/stdc++.h>

using namespace std;

class MyQueue {
public:
	stack<int> In;
	stack<int> Out;

    MyQueue()
	{

    }
    
    void push(int x) {
		In.push(x);
    }
    
    int pop() {
		if (Out.empty())
		{
			while (!In.empty())
			{
				Out.push(In.top());
				In.pop();
			}
		}
		int ret = Out.top();
		Out.pop();
		return ret;
		
    }
    
    int peek() {
		if (Out.empty())
		{
			while (!In.empty())
			{
				Out.push(In.top());
				In.pop();
			}
		}
		return Out.top();
	}
    
    bool empty() {
		if (In.empty() && Out.empty())
			return true;
		return false;
    }
};