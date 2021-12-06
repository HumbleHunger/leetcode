#include <bits/stdc++.h>

using namespace std;

class Solution1 {
public:
    int fib(int n) {
			vector<int> dp({0, 1});
			if (n < 2) {
				return dp[n];
			}
			for (int i = 2; i <= n; ++i) {
				int tmp = dp[i - 1] + dp[i - 2];
				dp.push_back(tmp);
			}
			return dp[n];
    }
};

class Solution2 {
public:
    int fib(int n) {
			if (n < 2) {
				return n;
			}
            int n1 = 0;
            int n2 = 1;
            int ret = 0;
			for (int i = 2; i <= n; ++i) {
				ret = n1 + n2;
				n1 = n2;
                n2 = ret;
			}
			return ret;
    }
};