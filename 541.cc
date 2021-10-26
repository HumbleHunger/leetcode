
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    string reverseStr(string s, int k) {
		for (int i = 0; i < s.size(); i += 2*k)
		{
			int left = i;
			int right = -1;
			if (i <= (int)s.size() - k)
			{
				right = i + k - 1;
			}
            if (i > (int)s.size() - k)
            {
                right = s.size() - 1;
            }
			while (left < right)
			{
				swap(s[left++], s[right--]);
			}
		}
		return s;
    }
};

int main()
{
	Solution s;
	s.reverseStr("a", 2);
	return 0;
}