#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
		vector<string> ret;
		vector<string> path;
		// start代表分割位置
		void backtracking(string &s, int start) {
			// 终止条件
			if (start >= s.size() && path.size() == 4) {
				string tmp;
				for (auto & n : path) {
					tmp = tmp + n;
				}
				tmp.pop_back();
				ret.push_back(tmp);
				return;
			}

      if (start >= s.size()) {
        return;
      }

			for (int i = 1; i <= 3 && start + i <= s.size(); ++i) {
				string str1 = s.substr(start, i);
				int num = atoi(str1.c_str());
				if (i == 1) {
					path.push_back(str1 + '.');
				} else if (i == 2 && str1[0] != '0') {
					path.push_back(str1 + '.');
				} else if (i == 3 && str1[0] != '0' && num < 256) {
					path.push_back(str1 + '.');
				} else {
					break;
				}
				backtracking(s, start + i);
				path.pop_back();
			}
		}

    vector<string> restoreIpAddresses(string s) {
			backtracking(s, 0);
			return ret;
    }
};

int main() {
	Solution s;
	for (auto & n : s.restoreIpAddresses("25525511135")) {
		cout << n << "  " << endl;
	}
	return 0;
}