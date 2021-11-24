#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
		vector<int> path;
		vector<vector<int>> ret;

		void backtracking(int n, int k, int start)
		{
			// 终止条件
			if (path.size() == k) {
				ret.push_back(path);
				return;
			}
			
			for (int i = start; i <= n - (k - path.size()) + 1; ++i) {
				path.push_back(i);
				backtracking(n, k, i + 1);
				path.pop_back();
			}

		}

    vector<vector<int>> combine(int n, int k) {
				backtracking(n, k, 1);
				return ret;	
    }
};