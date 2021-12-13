#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
			int min = INT32_MAX;
			int ret = 0;
			for (int i = 0; i < prices.size(); ++i) {
				if (prices[i] < min) {
					min = prices[i];
					continue;
				}
				int n = prices[i] - min - fee;
				if (prices[i] - min - fee > 0) {
					ret += n;
					min = prices[i] - fee;
				}
			}
			return ret;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
			vector<vector<int>> dp(prices.size(), vector<int>({0, 0}));
			dp[0][0] = -prices[0];
			for (int i = 1; i < prices.size(); ++i) {
				dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
				dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
			}
			return dp.back().back();
    }
};