#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
		static bool cmp(vector<int>& v1, vector<int>& v2) {
			return v1[0] < v2[0];
		}

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
			if (intervals.size() <= 1) {
				return 0;
			}
			sort(intervals.begin(), intervals.end(), cmp);
			int ret = 0;
			for (int i = 1; i < intervals.size(); ++i) {
				if (intervals[i][0] < intervals[i - 1][1]) {
					ret++;
					intervals[i][1] = min(intervals[i][1], intervals[i - 1][1]);
				}
			}
			return ret;
    }
};