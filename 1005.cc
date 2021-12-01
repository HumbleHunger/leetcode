#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
			for (int i = 0; i < k; ++i) {
				int minn = INT32_MAX;				
				int index = 0;
				for (int j = 0; j < nums.size(); ++j) {
					minn = min(nums[j], minn);
					index = j;
				}
				nums[index] = -nums[index];
			}
			int ret = 0;
			for (auto n : nums) {
				ret += n;
			}
			return ret;
    }
};