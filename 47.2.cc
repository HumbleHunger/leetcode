#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
		vector<int> path;
		vector<vector<int>> ret;
		void f(vector<int>& nums, vector<bool>& used) {
			if (path.size() == nums.size()) {
				ret.push_back(path);
				return;
			}

			for (int i = 0; i < nums.size(); ++i) {
				if (used[i]) continue;
				if (i > 0 && nums[i - 1] == nums[i] && used[i - 1] == false) continue;
				path.push_back(nums[i]);
				used[i] = true;
				f(nums, used);
				used[i] = false;
				path.pop_back();
			}
		}

    vector<vector<int>> permuteUnique(vector<int>& nums) {
			sort(nums.begin(), nums.end());
			vector<bool> used(nums.size(), false);
			f(nums, used);
			return ret;
    }
};