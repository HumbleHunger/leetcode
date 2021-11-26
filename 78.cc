#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
		vector<vector<int>> ret;
		vector<int> path;
		void backtracking(vector<int>& nums, int start) {
			if (start > nums.size()) {
				return;
			}

			for (int i = start; i < nums.size(); ++i) {
				path.push_back(nums[i]);
				ret.push_back(path);
				backtracking(nums, i + 1);
				path.pop_back();
			}
		}

    vector<vector<int>> subsets(vector<int>& nums) {
			ret.push_back(path);
			backtracking(nums, 0);
			return ret;
    }
};