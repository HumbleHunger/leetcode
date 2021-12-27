#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
			set<int> set1;
			set<int> set2;
			for (auto n : nums1) {
				set1.insert(n);
			}
			
			for (auto n : nums2) {
				set2.insert(n);
			}

			vector<int> ret;
			for (auto n : set1) {
				if (set2.find(n) != set2.end()) {
					ret.push_back(n);
				}
			}
			return ret;
    }
};