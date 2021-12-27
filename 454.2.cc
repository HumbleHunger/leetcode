#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
			unordered_map<int, int> map;
			// 遍历前两个数组，统计两数之和出现的次数
			for (auto n : nums1) {
				for (auto m : nums2) {
					map[n + m]++;
				}
			}
			int count = 0;
			// 遍历后两个数组，寻找能与之相加为0的个数
			for (auto n : nums3) {
				for (auto m : nums4) {
					if (map.find(-m - n) != map.end()) {
						count += map[-m - n];
					}
				}
			}
			return count;
    }
};