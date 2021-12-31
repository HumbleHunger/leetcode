#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
		vector<int> path;
		vector<vector<int>> ret;

		void f(vector<int>& nums, int start) {
			if (path.size() > 1) {
				ret.push_back(path);
			}

			if (start >= nums.size()) return;

			unordered_set<int> used;
			for (int i = start; i < nums.size(); ++i) {
				if (used.count(nums[i]) != 0) continue;
				if (path.size() > 0 && nums[i] < path.back()) continue;
				path.push_back(nums[i]);
				used.insert(nums[i]);
				f(nums, i + 1);
				path.pop_back();
			}
		}

    vector<vector<int>> findSubsequences(vector<int>& nums) {
			f(nums, 0);
			return ret;
    }
};