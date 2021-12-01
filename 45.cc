#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
			if(nums.size() == 1) return 0;
			int cur = 0;
			int next = 0;
			int ret = 0;

			for (int i = 0; i < nums.size(); ++i) {
				//更新next
				next = max(next, i + nums[i]);
				if (i == cur) {
					// 如当前范围没到终点则往下走
					if (i != nums.size() - 1) {
						ret++;
						cur = next;
						if (next >= nums.size() - 1) break;
					} else break;
				}
			}
			return ret;
		}
};