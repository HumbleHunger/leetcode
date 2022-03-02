#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.size() == 1) return nums[0];
        return quicksort(nums, 0, nums.size() - 1, k);
    }

    int quicksort(vector<int>& nums, int left, int right, int k) {
        int l = left, r = right;

        while (l < r) {
            while (l < r && nums[r] <= nums[left]) r--;
            while (l < r && nums[l] >= nums[left]) l++;
            swap(nums[l], nums[r]);
        }
        swap(nums[l], nums[left]);
        if (l < k - 1) return quicksort(nums, l + 1, right, k);
        if (l > k - 1) return quicksort(nums, left, l - 1, k);
        return nums[l];
    }
};