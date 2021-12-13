#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
			vector<vector<int>> dp(prices.size(), vector<int>(2 * k + 1, 0));
			for (int i = 1; i < dp[0].size(); i += 2) {
				dp[0][i] = -prices[0];
			}

			for (int i = 1; i < dp.size(); ++i) {
				for (int j = 1; j < dp[0].size(); ++j) {
					if (j % 2 == 0) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + prices[i]);
					else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i]);
				} 
			}

			return dp.back().back();
    }
};