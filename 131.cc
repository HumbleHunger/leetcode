#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
		vector<vector<string>> ret;
		vector<string> path;

		void backtracking(string& s, int start) {
			if (start == s.size()) {
				ret.push_back(path);
				return;
			}

			for (int len = 1; len <= s.size() - start; ++len) {
				if (len > 1) {
					string tmp = s.substr(start, len);
					string tmp1(tmp);
					reverse(tmp1.begin(), tmp1.end());
					if (tmp == tmp1) {
						path.push_back(tmp);
						backtracking(s, start + len);
						path.pop_back();
					}
				}
				else {
					string tmp(s.substr(start, 1));
					path.push_back(tmp);
					backtracking(s, start + 1);
					path.pop_back();
				}
			}
		}

    vector<vector<string>> partition(string s) {
			backtracking(s, 0);
			return ret;
    }
};