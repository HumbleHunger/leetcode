#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> path;
    vector<vector<string>> ret;
		void f(string s, int start) {
			if (start > s.size()) {
				ret.push_back(path);
				return;
			}

			for (int i = start; i < s.size(); ++i) {
				string str(s.substr(start, start + i + 1));
				string tmp(str);
				reverse(str.begin(), str.end());
				if (str == tmp) path.push_back(tmp);
				else continue;
				f(s, i + 1);
				path.pop_back();
			}
		}
		
		vector<vector<string>> partition(string s) {
			f(s, 0);
			return ret;
    }
};