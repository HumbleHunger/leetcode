#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
		vector<pair<int, int>> path;
		vector<vector<string>> ret;
		// index表示层号， pre表示上一层的位置
		void f(int n, vector<bool>& used, unordered_map<int, bool>& not, int index) {
			if (index > n) return;
			
			if (path.size() == n) {
				vector<string> tmp;
				for (int i = 0; i < n; ++i) {
					tmp.push_back(string(n, '.'));
					tmp[path[i].first - 1][path[i].second - 1] = 'Q';
				}
				ret.push_back(tmp);
			}

			for (int i = 1; i <= n; ++i) {
				if (used[i]) continue;


				if (i > pre + 1 || i < pre - 1) {
					path.push_back(pair<int, int>(index, i));
					used[i] = true;
					f(n, used, i, index + 1);
					path.pop_back();
					used[i] = false;
				}
			}
		}

    vector<vector<string>> solveNQueens(int n) {
			vector<bool> used(n + 1, false);
			unordered_map<int, bool> not;
			f(n, used, not, 1);
			return ret;
		}
};