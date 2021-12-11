#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
			vector<int> dp(s.size() + 1, 0);
			dp[0] = 1;

			for (int j = 1; j <= s.size(); ++j) {
				for (int i = 0; i < wordDict.size(); ++i) {
					if (j >= wordDict[i].size()) {
						if (wordDict[i] == s.substr(j - wordDict[i].size(), wordDict[i].size()) && dp[j - wordDict[i].size()]) {
							dp[j] = 1;
						}
					}
				}
			}

			return dp[s.size()];
    }
};