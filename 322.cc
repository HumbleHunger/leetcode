#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
			vector<int> dp(amount + 1, INT32_MAX - 1);
			dp[0] = 0;
			for (int i = 0; i < coins.size(); ++i) {
				for (int j = coins[i]; j <= amount; ++j) {
					dp[j] = min(dp[j], dp[j - coins[i]] + 1);
				}
			for (auto n : dp) {
				cout << n << " ";
			}
			cout << endl;
			}
			return dp[amount];
    }
};

int main() {
	Solution s;
	vector<int> v({2});
	s.coinChange(v, 3);
}