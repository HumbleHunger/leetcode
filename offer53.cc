#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int left2 = 0;
        int right2 = n - 1;

        while (right2 > left2) {
            int mid2 = (right2 + left2) / 2;

            if (mid2 == nums[mid2]) {

                left2 = mid2 + 1;
            } else {

                right2 = mid2;
            }
        }
        if (left2 == nums[left2]) return left2 + 1;
        return left2;
    }
};