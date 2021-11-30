#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
			if (nums.size() <= 1) return nums.size();
			int pre = nums[1] - nums[0];
			int cur = 0;
			int ret = 1;
			for (int i = 2; i < nums.size(); ++i) {
				cur = nums[i] - nums[i - 1];

				if ((pre >= 0 && cur < 0) || (pre <= 0 && cur > 0)) {
					ret++;
					pre = cur;
				}
			}
			return ret;
		}
};