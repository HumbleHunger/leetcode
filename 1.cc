#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
			unordered_map<int, int> map;
			for (int i = 0; i < nums.size(); ++i) {
				auto m = map.find(target - nums[i]);
				if (m != map.end()) {
					return {i, m->second};
				}
				map[nums[i]] = i;
			}
			return {};
    }
};