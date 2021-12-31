#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
		vector<int> path;
		vector<vector<int>> ret;
		void f(vector<int>& nums, int target, int start, int count) {
			if (count >= target) {
				if (count == target) {
					ret.push_back(path);
				}
				return;
			}

			for (int i = start; i < nums.size(); ++i) {
				if (i > start && nums[i] == nums[i - 1]) continue;
				path.push_back(nums[i]);
				count += nums[i];
				f(nums, target, i + 1, count);
				count -= nums[i];
				path.pop_back();
			}
		}

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
			sort(candidates.begin(), candidates.end());
			f(candidates, target, 0, 0);
			return ret;
    }
};