class Solution {
public:
    vector<double> dicesProbability(int n) {
        int count = 0;
        vector<vector<int>> dp(n, vector<int>(6 * n + 1, 0));
        for (int j = 1; j <= 6; ++j) dp[0][j] = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j <= 6 * (i + 1); ++j) {
                for (int k = 1; k <= 6; ++k) {
                    if (j >= k) dp[i][j] += dp[i - 1][j - k];
                }
            }
        }
        for (auto m : dp[n - 1]) {
            cout << m << " ";
            count += m;
        }
        cout << endl;
        cout << count;
        vector<double> ret(5 * n + 1, 0);
        int min = n;
        for (int i = 0; i < ret.size(); ++i) {
         
            ret[i] = dp[n - 1][min++] / (double)count;
   
        }
        return ret;
    }
};