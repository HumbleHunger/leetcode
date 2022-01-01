#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
			int diff = 0;
			int ret = 0;
			for (int i = 1; i < nums.size(); ++i) {
				if ((diff <= 0 && nums[i] - nums[i - 1] > 0) || (diff >= 0 && nums[i] - nums[i - 1] < 0)) {
					ret++;
					diff = nums[i] - nums[i - 1];
				}
			}
			return ret;
    }
};