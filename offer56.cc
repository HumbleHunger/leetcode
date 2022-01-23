#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
				sort(nums.begin(), nums.end());
				vector<int> ret;
				for (int i = 0; i < nums.size() - 1; ++i) {
					if (nums[i] != nums[i + 1]) {
						ret.push_back(nums[i]);
					} else {
						++i;
					}
        }
				if (ret.size() < 2) ret.push_back(nums.back());
				return ret;
    }
};