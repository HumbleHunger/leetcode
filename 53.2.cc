#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
			int ret = 0;
			int count = 0;
			for (int i = 0; i < nums.size(); ++i) {
				count += nums[i];
				if (count < 0) count = 0;
				if (count > ret) ret = count;
			}
			return ret;
    }
};