#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
		stack<char> st;
        for (auto c : s)
        {
            if (c == '(') 
            {
                st.push(')');
                continue;
            }
            else if (c == '[')
            {
                st.push(')');
                continue;
            }
            else if (c == '{')
            {
                st.push(')');
                continue;
            }
            
            if (c == st.top())
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
        return st.empty();
    }
};