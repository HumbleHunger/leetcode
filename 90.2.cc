#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
		vector<int> path;
		vector<vector<int>> ret;
		void f(vector<int>& nums, int start) {
			ret.push_back(path);

			if (start >= nums.size()) return;

			for (int i = start; i < nums.size(); ++i) {
				if (i > start && nums[i] == nums[i - 1]) continue;
				path.push_back(nums[i]);
				f(nums, i + 1);
				path.pop_back();
			}
		}

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
			sort(nums.begin(), nums.end());
			f(nums, 0);
			return ret;
    }
};