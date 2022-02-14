#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1, -1};
        int left = 0;
        int right = nums.size() - 1;
        int start = -1;
        int end = -1;
        vector<int> v1({0, 0});
        vector<int> v2({-1, -1});
        if (nums.size() == 1) return target == nums[0] ? v1 : v2;
        while (right > left) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > target) {
                right = mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                while (mid >= 0 && nums[mid] == target) {
                    mid--;
                }
                start = mid + 1;
                break;
            }
        }
        if (nums[left] == target) start = left;
        end = start;
        while (end < nums.size() - 1 && nums[end + 1] == target) {
            end++;
        }
        //if (end < -1) end = -1;
        return {start, end};
    }
};