#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
		stack<char> st;
			for (auto & c : s)
			{
				if (!st.empty() && c == st.top())
				{
					cout << "pop " << st.top() << endl;
					st.pop();
					continue;
				}
				cout << "push " << c << endl;

				st.push(c);
			}
		
		string ret;
		while (!st.empty())
		{
			cout << "ret push " << st.top() << endl;
			ret.push_back(st.top());
			st.pop();
		}
		reverse(ret.begin(), ret.end());
		cout << ret << endl;
		return ret;
    }
};

int main()
{
	Solution s;
	s.removeDuplicates("abbaca");
	return 0;
}