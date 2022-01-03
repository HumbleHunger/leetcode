#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
			vector<int> dp(n + 1, 0);
			for (int i = 2; i <= n; ++i) {
				for (int j = 1; j <= i; ++j) {
					int tmp = max(j * (i - j), j * dp[i - j]);
					if (tmp > dp[i]) dp[i] = tmp;
				}
			}
			return dp[n];
    }
};