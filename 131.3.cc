#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> path;
    vector<vector<string>> ret;
    void func(string s, int start) {
        if (start == s.size()) {
            ret.push_back(path);
            return;
        }

        for (int i = 1; i + start <= s.size(); ++i) {
            string sub(s.substr(start, i));
            string tmp = sub;
            reverse(sub.begin(), sub.end());
            if (sub == tmp) {
               path.push_back(tmp);
							 func(s, start + i);
							 path.pop_back(); 
            }
        }
    }

    vector<vector<string>> partition(string s) {
			func(s, 0);
			return ret;
    }
};