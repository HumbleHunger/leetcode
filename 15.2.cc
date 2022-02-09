#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
		vector<vector<int>> ret;
    vector<vector<int>> threeSum(vector<int>& nums) {
				if (nums.size() < 3) return ret;
        sort(nums.begin(), nums.end());
				int left = 1;
				int right = nums.size() - 1;
				for (int i = 0; i < nums.size() - 2; ++i) {
					left = i + 1;
					right = nums.size() - 1;
					// i去重
					if (i > 0 && nums[i] == nums[i - 1]) continue;

					while (right > left) {
						if (nums[i] + nums[left] + nums[right] > 0) {
							while (right > left && nums[right] == nums[right - 1]) {
								right--;
							}
							right--;
						} else if (nums[i] + nums[left] + nums[right] < 0) {
							while (right > left && nums[left] == nums[left + 1]) {
								left++;
							}
							left++;
						} else {
							ret.push_back({nums[i], nums[left], nums[right]});
							right--;
							left++;
						}
					}
				}
				return ret;
    }
};