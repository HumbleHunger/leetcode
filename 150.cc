#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> ret;
		for (string& s : tokens)
        {
			if (s.size() == 1) 
			{
	            if (s[0] == '*' || s[0] == '-' || s[0] == '+' || s[0] == '/')
  	        	{
  	            	int b = ret.top();
					ret.pop();
					cout << "pop " << b << endl;
	            	int a = ret.top();
					ret.pop();
					cout << "pop " << a << endl;
					int c = 0;
					if (s[0] == '*')
					{
						c = a * b;
					}
					if (s[0] == '+')
					{
						c = a + b;
					}
					if (s[0] == '-')
					{
						c = a - b;
					}
					if (s[0] == '/')
					{
						c = a / b;
					}
					ret.push(c);
					cout << "push " << a << s[0] << b << " = " << c << endl;
					continue;
	            }
			}
				cout << "push " << s.c_str() << endl;
				ret.push(atoi(s.c_str()));
        }
		return ret.top();
    }
};

int main()
{
	vector<string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
	Solution s;
	cout << s.evalRPN(tokens) << endl;

}