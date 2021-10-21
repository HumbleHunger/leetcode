#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> set1;
        set<int> set2;
        for (auto i : nums1)
        {
            set1.insert(i);
        }

        for (auto i : nums2)
        {
            set2.insert(i);
        }

        vector<int> ret;
        for (auto it1 = set1.begin(); it1 != set1.end(); ++it1)
        {
    		auto it2 = set2.find(*it1);
			if (it2 != set2.end())
			{
				ret.push_back(*it1);
			}
        }
		return ret;
    }
};