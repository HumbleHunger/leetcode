#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
			if (n <= 2) {
				return n;
			}

			int ret = 0;
			int n1 = 1;
			int n2 = 2;
			for (int i = 3; i <= n; ++i) {
				ret = n1 + n2;
				n1 = n2;
				n2 = ret;
			}
			return ret;
    }
};