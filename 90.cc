#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> ret;
		vector<int> path;

		void backtracking(vector<int>& nums, vector<bool>& used, int start) {
			ret.push_back(path);
			if (start > nums.size()) {
				return;
			}

			for (int i = start; i < nums.size(); ++i) {
				if (used[i - 1] == false && nums[i] == nums[i - 1]) continue;
				path.push_back(nums[i]);
				used[i] = true;
				backtracking(nums, used, i + 1);
				used[i] = false;
				path.pop_back();
			}
		}

		vector<vector<int>> subsetsWithDup(vector<int>& nums) {
			sort(nums.begin(), nums.end());
			vector<bool> used(nums.size(), false);
			backtracking(nums, used, 0);
			return ret;
    }
};

int main() {
	Solution s;
	vector<int> n{1 , 2, 2};
	for (auto &n : s.subsetsWithDup(n) ) {
		for (auto n1 : n) 
		std::cout << n1 << " " << std::endl;
	}
}