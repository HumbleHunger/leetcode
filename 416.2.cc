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
				vector<int> dp(count + 1, 0);

				for (int i = dp.size() - 1; i >= 0; --i) {
					dp[i] = max(dp[i - nums[0]] + nums[0], dp[i]);
				}

				for (int i = 1; i < nums.size(); ++i) {
					for (int j = dp.size() - 1; j >= 0; --j) {
						dp[j] = max(dp[j - nums[i]] + nums[i], dp[j]);
					}
				}

				if (dp.back() == dp.size() - 1) return true;
				return false;
    }
};