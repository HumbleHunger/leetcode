#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
				int ret = 0;

				for (int j = 0; j < s.size(); ++j) {
					for (int i = 0; i <= j; ++i) {
						if (s[i] == s[j]) {
							if (j - i <= 1) dp[i][j] = true;
							else dp[i][j] = dp[i + 1][j - 1];
							if (dp[i][j]) ret++;
						}
					}
				}
				/*for (auto n : dp) {
					for (auto m : n) {
						cout << m << " ";
					}
					cout << endl;
				}*/
				return ret;
    }
};