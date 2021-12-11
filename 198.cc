#include <bits/stdc++.h>

using namespace std;

// 有点像非伯纳切数列
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() < 2) {
            return nums[0];
        }
        int n1 = nums[0];
        int n2 = max(nums[0], nums[1]);

        int ret = n2;
        for (int i = 2; i < nums.size(); ++i) {
            ret = max(n1 + nums[i], n2);
            n1 = n2;
            n2 = ret;
        }
        return ret;
    }
};