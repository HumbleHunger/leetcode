#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
		vector<int> dp(nums2.size() + 1, 0);

        int ret = 0;
        for (int i = 1; i <= nums1.size(); ++i) {
            for (int j = nums2.size(); j > 0; --j) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[j] = dp[j - 1] + 1;
                } else dp[j] = 0;
                ret = max(ret, dp[j]);
            }
        }

        return ret;
    }
};