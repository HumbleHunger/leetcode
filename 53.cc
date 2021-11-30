#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(const vector<int>& nums) {
			int count = 0;
			int ret = INT32_MIN;
			for (int i = 0; i < nums.size(); ++i) {
				count += nums[i];
				if (count > ret) ret = count;
				if (count < 0) count = 0;
			}
			return ret;
		}
};