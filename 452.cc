#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
		static bool cmp(vector<int>& v1, vector<int>& v2) {
			return v1[0] < v2[0];
		}

    int findMinArrowShots(vector<vector<int>>& points) {
			if (points.size() == 0) return 0;

			sort(points.begin(), points.end(), cmp);
			
			int ret = 1;
			for (int i = 1; i < points.size(); ++i) {
				if (points[i][0] > points[i - 1][1]) {
					ret++;
				}
				else {
					points[i][1] = min(points[i][1], points[i - 1][1]);
				}
			}
			return ret;
    }
};