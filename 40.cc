#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
		vector<vector<int>> ret;
		vector<int> path;

		void backtracking(vector<int>& nums, int target, int start, int sum, vector<bool>& used) {
			if (sum == target) {
				ret.push_back(path);
				return;
			}

			for (int i = start; i < nums.size() && sum + nums[i] <= target; ++i) {
				if (nums[i] == nums[i - 1] && used[i - 1] == false) continue;
				
				path.push_back(nums[i]);
				sum += nums[i];
				used[i] = true;
				backtracking(nums, target, i + 1, sum, used);
				sum -= nums[i];
				used[i] = false;
				path.pop_back();
			}
		}

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
			vector<bool> used(candidates.size(), false);
			sort(candidates.begin(), candidates.end());
			backtracking(candidates, target, 0, 0, used);
			return ret;
    }
};