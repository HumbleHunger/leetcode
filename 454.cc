#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
		unordered_map<int, int> map;
        for (auto i : nums1)
        {
            for (auto j : nums2)
            {
                map[i+j]++;
            }
        }
		int count = 0;
        for (auto i : nums3)
        {
            for (auto j : nums4)
            {
                auto iter = map.find(0-(i + j));
				if (iter != map.end())
				{
					count += iter->second;
				}
            }
        }
		return count;
    }
};