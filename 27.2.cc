#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
			int p1 = 0;
			int p2 = 0;
			for (p2 = 0; p < nums.size(); ++p2) {
				if (val != nums[p2]) {
					nums[p1++] = nums[p2];
				} 
			}
			return p1;
		}
};