#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
		vector<string> path;
		vector<string> ret;
		void f(string s, int start) {
			if (start >= s.size()) {
				if (path.size() == 4) {
					for (int i = 0; i < 3; ++i) {
						ret.push_back(path[i] + '.');
					}
					ret.push_back(path[3]);
				}
				return;
			}

			for (int i = 1; i <= 3 && i + start < s.size(); ++i) {
				string str1 = s.substr(start, i);
				int num = atoi(str1.c_str());
				if (i == 1) {
					path.push_back(str1);
				} else if (i == 2 && str1[0] != '0') {
					path.push_back(str1);
				} else if (i == 3 && str1[0] != '0' && num < 256) {
					path.push_back(str1);
				} else {
					break;
				}
				f(s, start + i);
				path.pop_back();
			}

		}

    vector<string> restoreIpAddresses(string s) {
			f(s, 0);
			return ret;
    }
};