#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
		void f(vector<int>& nums, int n) {
			for (int i = 1; i <= n; ++i) {
				for (int j = 1; j <= i; ++j) {
					if (i == j * j) nums.push_back(i);
				}
			}
		}

    int numSquares(int n) {
			vector<int> nums;
			f(nums, n);

			vector<int> dp(n + 1, INT32_MAX);
			dp[0] = 0;
			for (int i = 0; i < nums.size(); ++i) {
				for (int j = nums[i]; j <= n; ++j) {
					if (dp[j - nums[i]] != INT32_MAX)
						dp[j] = min(dp[j], dp[j - nums[i]] + 1);
				}
			}
			return dp[n];
    }
};