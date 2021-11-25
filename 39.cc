#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
		vector<vector<int>> ret;
		vector<int> path;
		void backtracking(vector<int>& candidates, int target, int start, int sum) {
			if (sum == target) {
				ret.push_back(path);
			}

			for (int i = start; i < candidates.size(); ++i) {
				path.push_back(candidates[i]);
				backtracking(candidates, target, start + 1, sum + candidates[i]);
			}
		}
  
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
			backtracking(candidates, target, 0, 0);
			return ret;
    }
};