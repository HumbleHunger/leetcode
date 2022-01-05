class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        vector<int> dp1(nums.size() - 1, 0);
        vector<int> dp2(nums.size() - 1, 0);
        dp1[0] = nums[0];
        dp1[1] = max(nums[0], nums[1]);
        dp2[0] = nums[1];
        dp2[1] = max(nums[1], nums[2]);
        for (int i = 2; i < nums.size() - 1; ++i) {
            dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i]);
        }
        for (int i = 3; i < nums.size(); ++i) {
            dp2[i - 1] = max(dp2[i - 2], dp2[i - 3] + nums[i]);
        }
        return max(dp1.back(), dp2.back());
    }
};