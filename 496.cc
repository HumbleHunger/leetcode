#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
			stack<int> s;
			s.push(0);
			vector<int> v(nums2.size(), -1);
			for (int i = 1; i < nums2.size(); ++i) {
				while (!s.empty() && nums2[s.top()] < nums2[i]) {
					v[s.top()] = nums2[i];
					s.pop();
				}
				s.push(i);
			}

			vector<int> ret;
			for (auto n : nums1) {
				for (int i = 0; i < nums2.size(); ++i) {
					if (nums2[i] == n) ret.push_back(v[i]);
				}
			}
			return ret;
    }
};