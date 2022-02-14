#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 1) return target == nums[0] ? 0 : -1;
        int left = 0;
        int right = nums.size() - 1;
        while (right > left) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right]) {
                if (nums[mid] > target && nums[right] < target) {
                    right = mid;
                } else if (target > nums[mid] || target < nums[right]) {
                    left = mid + 1;
                } else {
                    return target == nums[mid] ? mid : right;
                }
            } else {
                if (nums[mid] < target && target < nums[right]) {
                    left = mid + 1;
                } else if (target < nums[mid] || target > nums[right]) {
                    right = mid;
                } else {
                    return target == nums[mid] ? mid : right;
                }
            }
        }
        return -1;
    }
};