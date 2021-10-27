
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string ret;
        string tmp;
        for (int i = s.size() - 1; i > -1; --i)
        {
            tmp.clear();
            while (s[i] != ' ' && i > -1)
            {
                tmp = tmp + s[i--];
            }
			if (tmp.size() >= (size_t)1) {
   	        	reverse(tmp.begin(), tmp.end());
   	        	ret = ret + tmp + ' ';
			}
        }
		ret.erase(ret.size() - 1);
		return ret;
    }
};

int main()
{
	Solution s;
	string q = s.reverseWords("the sky is blue");
	cout << "!" << q << "!" << endl;
	q = s.reverseWords("  hello world  ");
	cout << "!" << q << "!" << endl;
	q = s.reverseWords("  Bob    Loves  Alice   ");
	cout << "!" << q << "!" << endl;
}