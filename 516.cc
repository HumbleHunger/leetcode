#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
			vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));

			for (int j = 0; j < s.size(); ++j) {
				for (int i = j; i >= 0; --i) {
					if (s[i] == s[j]) {
						if (j - i <= 1) {
							dp[i][j] = j - i + 1;
						} else {
							dp[i][j] = dp[i + 1][j - 1] + 2;
						}
					} else {
						dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
					}
				}
			}
			return dp[0].back();
    }
};