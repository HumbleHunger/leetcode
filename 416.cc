#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
			int count = 0;
			for (auto n : nums) {
				count += n;
			}
			if (count % 2 != 0) return false;

			// 背包重量
			int weight = count / 2;
			// 物品数量
			int num = nums.size();
			// 初始化
			vector<int> dp(weight + 1, 0);
			for (int i = 1; i < dp.size(); ++i) {
				if (i >= nums[0]) dp[i] = nums[0];
			}

			for (int i = 1; i < nums.size(); ++i) {
				for (int j = weight; j >= 0; --j) {
					if (j < nums[i]) continue;
					else dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
				}
			}

			if (dp[weight] == weight) return true;			
			return false;
    }
};