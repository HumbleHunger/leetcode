#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
				vector<vector<int>> ret;
				int left = 0;
				int right = 0;
				for (int i = 0; i < nums.size() - 2; ++i) {
					// 如果i指针的数大于0，则不可能和为0
					if (nums[i] > 0) return ret;
					// i指针去重
					if (i > 0 && nums[i] == nums[i - 1]) continue;
					left = i + 1;
					right = nums.size();
					while (right > left) {
						int sum = nums[i] + nums[left] + nums[right];
						if (sum > 0) right--;
						else if (sum < 0) left++;
						else {
							ret.push_back({nums[i], nums[left], nums[right]});
							// left指针去重
							while (nums[left] == nums[left + 1]) left++;
							// right去重
							while (nums[right] == nums[right - 1]) right--;
						}
					}
				}
				return ret;
    }
};