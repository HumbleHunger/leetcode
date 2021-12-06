#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
			int n1 = cost[0];
			int n2 = cost[1];
			if (cost.size() == 2) {
				return n2;
			}

			int ret = 0;
			for (int i = 2; i < cost.size(); ++i) {
				ret = min(n1 + cost[i], n2);
				std::cout << n1 << endl;
				n1 = n2;
				n2 = ret;
			}
			return min(n1, n2);
    }
};

int main() {
	vector<int> cost({1, 100, 1, 1, 1, 100, 1, 1, 100, 1});
	Solution s;
	s.minCostClimbingStairs(cost);
}