#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
			
			int mark = 0;
			int in = 0;
			int out = 0;
			int ret = 0;
			int pre = 0;
			int cur = 0;

			int start = 0;
			pre = prices[1] - prices[0];
			if (pre > 0) prices.push_back(INT32_MAX);
			else prices.push_back(INT32_MIN);
			for (int i = 1; i < prices.size() - 1; ++i) {
				cur = prices[i + 1] - prices[i];
				// 递增改变
				if ((cur > 0 && pre < 0) || (cur < 0 && pre > 0) || i == prices.size() - 2) {
					// pre是递增
					if (pre >= 0) {
						// 买
						if (mark == 0) {
							in = prices[start];
							cout << "买入" << in << endl;
							start = start + 1;;
							i = start;
							mark = 1;
						} else {
						// 卖
							out = prices[i];
							cout << "买出" << out << endl;
							ret += out - in;
							start = i + 1;
							mark = 0;
						}
					} else {
						// pre是递减
						// 买
						if (mark == 0) {
							in = prices[i];
							cout << "买入" << in << endl;
							start = i + 1;
							mark = 1;
						} else {
						// 卖
							out = prices[start];
							cout << "买出" << out << endl;
							start = start + 1;
							i = start;
							ret += out - in;
							mark = 0;
						}
					}
					pre = cur;
				}
			}
			return ret;
    }
};

int main() {
	Solution s;
	vector<int> v({1,2,3,4,5});
	s.maxProfit(v);
}

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        for (int i = 1; i < prices.size(); i++) {
            result += max(prices[i] - prices[i - 1], 0);
        }
        return result;
    }
};