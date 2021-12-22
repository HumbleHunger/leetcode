#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
		int left = 0;
        int right = 0;
        int ret = INT32_MAX;
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            count += nums[i];
            right++;
            while (count >= target) {
                if (right - left + 1 < ret) ret = right - left + 1;
                count -= nums[left++];
            }
        }
        return ret;
    }
};