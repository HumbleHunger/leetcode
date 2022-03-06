#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int robf(vector<int>& nums) {
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

    int rob(vector<int>& nums) {
			        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
				vector<int> nums1(nums.begin(), nums.begin() + nums.size() - 1);
				vector<int> nums2(nums.begin() + 1, nums.begin() + nums.size());
        int result1 = robf(nums1); // 情况二
        int result2 = robf(nums2); // 情况三
        return max(result1, result2);
	}
};

int main() {
	vector<int> v({1, 2, 3});
	Solution s;

	s.rob(v);
}