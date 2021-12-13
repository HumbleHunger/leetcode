#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
			vector<int> dp(prices.size(), 0);
			vector<int> p(prices.size(), 0);
			for (int i = 1; i < p.size(); ++i) {
				p[i] = prices[i] - prices[i - 1];
			}
			dp[0] = 0;
			for (int i = 1; i < dp.size(); ++i) {
				dp[i] = max(dp[i - 1], dp[i - 1] + p[i]);
			}
			return dp.back();
		}
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
			// dp是所得最大现金
			vector<vector<int>> dp(prices.size(), vector<int>({0, 0}));
			dp[0][0] = -prices[0];

			for (int i = 1; i < prices.size(); ++i) {
				dp[i][0] = max(dp[i - 1][1] - prices[i], dp[i - 1][0]);
				dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
			}

			return max(dp.back()[0], dp.back()[1]);
		}
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        for (int i = 1; i < prices.size(); i++) {
            result += max(prices[i] - prices[i - 1], 0);
        }
        return result;
    }
};