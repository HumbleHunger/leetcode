#include <bits/stdc++.h>

using namespace std;

// 贪心
class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
			// 记录最小价格
			int low = INT_MAX;
			// 记录最大利润
			int ret = 0;	
			for (int i = 0; i < prices.size(); ++i) {
				low = min(low, prices[i]);
				// ret始终由prices[i]与prices[i]之前的最小值相减得出
				ret = max(ret, prices[i] - low);
			}
			return ret;
    }
};

// dp
class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
			vector<vector<int>> dp(prices.size(), vector<int>({0, 0}));
			dp[0][0] = -prices[0];
			dp[0][1] = 0;
			for (int i = 1; i < prices.size(); ++i) {
				// 如果第i天持有股票，可能是昨天就已持有或者今天买入，取最大值即持有现金最多的情况
				dp[i][0] = max(dp[i - 1][0], -prices[i]);
				// 如果第i天不持有股票，可能是昨天就不持有或者今天卖出，取最大值即持有现金最多的情况
				dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
			}
			return max(dp[prices.size() - 1][0], dp[prices.size() - 1][1]);
    }
};