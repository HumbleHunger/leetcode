#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
			int ret = 0;
			int m = 0;
			int start = 0; 
			int cover = nums[0];
			while (start + cover < nums.size() - 1) {
				m = 1;
				ret++;
				cover = nums[start];
				for (int i = start + 1; i <= cover; ++i) {
					if (nums[i] > m) {
						start = i;
					}
				}
			}
			return ret;
    }
};