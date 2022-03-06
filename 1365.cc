#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        unordered_map<int, int> map;
				for (int i = 0; i < nums.size(); ++i) {
					map[nums[i]] = i;
				}
				vector<int> ret(nums.size(), 0);
				sort(nums.begin(), nums.end());
				for (int i = 0; i < nums.size(); ++i) {
					ret[map[nums[i]]] = i;
				}
				return ret;
    }
};