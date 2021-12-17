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

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> dp(nums.size()); 
        dp[0] = nums[0];
        int result = dp[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]); // 状态转移公式
            if (dp[i] > result) result = dp[i]; // result 保存dp[i]的最大值
        }
        return result;
    }
};