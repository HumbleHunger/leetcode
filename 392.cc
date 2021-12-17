#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
			vector<vector<int>> dp(t.size() + 1, vector<int>(s.size() + 1, 0));

			for (int i = 1; i <= t.size(); ++i) {
				for (int j = 1; j <= s.size(); ++j) {
					if (t[i - 1] == s[j - 1]) {
						dp[i][j] = dp[i -1][j - 1] + 1;
					} else {
						dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
					}
					if (dp[i][j] == s.size()) return true;
				}
			}
			return false;
    }
};