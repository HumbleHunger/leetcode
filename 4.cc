#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
		int topk(vector<int>& nums, int k, int left = 0, int right = -2) {
			if (right == -2) right = nums.size() - 1;
            //cout << left << " " << right << endl;

			if (right < left) return -1;

			int l = left;
			int r = right;

			while (r > l) {
				while (r > l && nums[r] >= nums[left]) r--;
				while (r > l && nums[l] <= nums[left]) l++;
				swap(nums[l], nums[r]);
			}
			swap(nums[left], nums[l]);
            //cout << l << " " << endl;
			if (l < k) {
				return topk(nums, k, l + 1, right);
			} else if (l > k) {
				return topk(nums, k, left, l - 1);
			}
            //cout << nums[l] << endl;
            return nums[l];
		}

        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
			for (int i = 0; i < nums2.size(); ++i) {
				nums1.push_back(nums2[i]);
			}
			double ret = 0;
			int mid = nums1.size() / 2;
			if (nums1.size() % 2 == 0) {
                //cout << 
                //cout << nums1.size() << " " << mid << endl;
				ret = topk(nums1, mid);
                ret += topk(nums1, mid - 1);
                return ret / 2;
			} else {
                //cout << nums1.size() << " " << mid << endl;
				ret = topk(nums1, mid);
			}
			return ret;
    }
};
