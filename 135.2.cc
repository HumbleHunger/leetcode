#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
			vector<int> nums(ratings.size(), 1);
			// 右大于左
			for (int i = 1; i < ratings.size(); ++i) {
				if (ratings[i] > ratings[i - 1]) nums[i] = max(nums[i - 1] + 1, nums[i]);
			}
			// 左大于右
			for (int i = ratings.size() - 2; i >= 0; --i) {
				if (ratings[i] > ratings[i + 1]) nums[i] = max(nums[i + 1] + 1, nums[i]);
			}

			int ret = 0;
			for (auto n : nums) {
				ret += n;
			}
			return ret;
    }
};