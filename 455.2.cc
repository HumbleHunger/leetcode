#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
			sort(g.begin(), g.end());
			sort(s.begin(), s.end());
			int index = 0;
			int ret = 0;
			for (int i = 0; i < s.size(); ++i) {
				if (s[i] >= g[index]) {
					ret++;
					index++;
				}
			}
			return ret;
		}
};