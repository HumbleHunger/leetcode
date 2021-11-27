#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> ret;
		vector<int> path;

		void backtracking(vector<int>& nums, int start) {
			ret.push_back(path);
			if (start > nums.size()) {
				return;
			}

			for (int i = start; i < nums.size(); ++i) {
				if (i > start && nums[i] == nums[i - 1]) continue;
				path.push_back(nums[i]);
				backtracking(nums, i + 1);
				path.pop_back();
			}
		}

		vector<vector<int>> subsetsWithDup(vector<int>& nums) {
			sort(nums.begin(), nums.end());
			backtracking(nums, 0);
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