#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
		vector<vector<int>> ret;
		vector<int> path;
		void backtracking(int k, int n, int start) {
			if (path.size() == k) {
				int count = 0;
				for (auto & n : path) {
					count += n;
				}
				if (count == n) {
					ret.push_back(path);
				}
				return;
			}

			for (int i = start; i < 10 - k + 1 + path.size(); ++i) {
				path.push_back(i);
				backtracking(k, n, i + 1);
				path.pop_back();
			}
		}

    vector<vector<int>> combinationSum3(int k, int n) {
			backtracking(k, n, 1);
			return ret;
    }
};