#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
			vector<vector<int>> dp(prices.size(), vector<int>(5, 0));

			dp[0][1] = -prices[0];
			dp[0][3] = -prices[0];

			for (int i = 1; i < dp.size(); ++i) {
				dp[i][0] = dp[i - 1][0];
				dp[i][1] = max(dp[i - 1][0] - prices[i], dp[i - 1][1]);
				dp[i][2] = max(dp[i - 1][1] + prices[i], dp[i - 1][2]);
				dp[i][3] = max(dp[i - 1][2] - prices[i], dp[i - 1][3]);
				dp[i][4] = max(dp[i - 1][3] + prices[i], dp[i - 1][4]);
			}
			return dp.back()[4];
    }
};