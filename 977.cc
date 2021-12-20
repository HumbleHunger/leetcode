#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
       int left = 0;
			 int right = nums.size() - 1;
			 vector<int> ret;
			 while (left <= right) {
				int n1 = nums[left] * nums[left];
				int n2 = nums[right] * nums[right];
				if (n1 <= n2) {
					ret.push_back(n1);
					left++;
				} else {
					ret.push_back(n2);
					right--;
				}
			 }
			 reverse(ret.begin(), ret.end());
			 return ret;
    }
};