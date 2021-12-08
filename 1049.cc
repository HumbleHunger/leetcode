#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
			int count = 0;
			for (auto n : stones) {
				count += n;
			}

			int weight = count / 2;
			vector<int> dp(weight + 1, 0);

			for (int i = 0; i < stones.size(); ++i) {
				for (int j = weight; j >= stones[i]; --j) {
					dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
				}
			}

			return count - dp[weight] -dp[weight];
    }
};