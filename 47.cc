class Solution {
public:
		vector<vector<int>> ret;
		vector<int> path;

		void backtracking(vector<int>& nums, vector<bool>& used) {
			if (path.size() == nums.size()) {
				ret.push_back(path);
				return;
			}

			for (int i = 0; i < nums.size(); ++i) {
				if (used[i] || (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])) {
					continue;
				}
				path.push_back(nums[i]);
				used[i] = true;
				backtracking(nums, used);
				used[i] = false;
				path.pop_back();
			}
		}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
			sort(nums.begin(), nums.end());
            vector<bool> used(nums.size(), false);
			backtracking(nums, used);
			return ret;
    }
};