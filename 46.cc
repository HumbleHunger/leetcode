#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
		vector<vector<int>> ret;
		vector<int> path;

		void backtracking(const vector<int>& nums, vector<bool>& used) {
			if (path.size() == nums.size()) {
				ret.push_back(path);
				return;
			}

			for (int i = 0; i < nums.size(); ++i) {
				if (used[i]) {
					continue;
				}
				path.push_back(nums[i]);
				used[i] = true;
				backtracking(nums, used);
				used[i] = false;
				path.pop_back();
			}
		}
    vector<vector<int>> permute(const vector<int>& nums) {
			vector<bool> used(nums.size(), false);
			backtracking(nums, used);
			return ret;
    }
};

int main() {
	Solution s;
	s.permute({1, 2,3});
}