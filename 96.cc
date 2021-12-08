#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
			vector<int> dp{1, 1, 2};

			for (int i = 3; i <= n; ++i) {
				dp.push_back(0);
				for (int j = 1; j <= i; ++j) {
					dp[i] += dp[j - 1] * dp[i -j];
				}
			}

			return dp[n];
    }
};