#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
		vector<bool> used;
		string path;
		vector<string> ret;
		void f(string s) {
			if (path.size() == s.size()) {
				ret.push_back(path);
				return;
			}

			for (int i = 0; i < s.size(); ++i) {
				if (used[i] || (i > 0 && s[i] == s[i - 1])) continue;
				path += s[i];
				used[i] = true;
				f(s);
				path.pop_back();
				used[i] = false;
			}
		}
		
		vector<string> permutation(string s) {
			used.resize(s.size(), false);
			sort(s.begin(), s.end());
			f(s);
			return ret;
    }
};