#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
			sort(nums.begin(), nums.end());
			vector<vector<int>> ret;
			int left = 0;
			int right = 0;
			for (int i = 0; i < nums.size() - 3; ++i) {
				if (nums[i] > 0) return ret;
				// i去重
				if (i > 0 && nums[i] == nums[i - 1]) continue;
				for (int j = i + 1; j < nums.size() - 2; ++j) {
					// j去重
					if (j > i + 1 && nums[j] == nums[j - 1]) continue;
					left = j + 1;
					right = nums.size() - 1;
					while (right > left) {
						int sum = nums[i] + nums[j] + nums[left] + nums[right];
						if (sum > 0) right--;
						else if (sum < 0) left++;
						else {
							ret.push_back({nums[i], nums[j], nums[left], nums[right]});
							while (right > left && nums[left] == nums[left + 1]) left++;
							while (right > left && nums[right] == nums[right - 1]) right--;
							right--;
							left++;
						}
					}
				}
			}
			return ret;
    }
};