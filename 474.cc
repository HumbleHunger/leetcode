#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
			vector<vector<int>> dp(m, vector<int>(n, 0));

			for (auto str : strs) {
				int num0 = 0;
				int num1 = 0;
				for (auto c : str) {
					if (c == '0') num0++;
					else num1++;
				}

				for (int i = m; i >= num0; --i) {
					for (int j = n; j >= num1; --j) {
						dp[i][j] = max(dp[i][j], dp[i - num0][j - num1] + 1);
					}
				}
			}

			return dp[m][n];
    }
};