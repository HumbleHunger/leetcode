#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
			int min = INT32_MAX;
			int ret = 0;
			for (int i = 0; i < prices.size(); ++i) {
				if (prices[i] < min) {
					min = prices[i];
					continue;
				}
				int n = prices[i] - min - fee;
				if (prices[i] - min - fee > 0) {
					ret += n;
					min = prices[i] - fee;
				}
			}
			return ret;
    }
};