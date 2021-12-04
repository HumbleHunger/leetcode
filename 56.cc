#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
		static bool cmp(vector<int>& v1, vector<int>& v2) {
			return v1[0] < v2[0];
		}

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
			if (intervals.size() <= 1) return intervals;
			sort(intervals.begin(), intervals.end(), cmp);

			vector<vector<int>> ret;
			for (int i = 1; i < intervals.size(); ++i) {
				std::cout << intervals[i][0] << "  " << intervals[i - 1][1] << endl;
				if (intervals[i][0] > intervals[i - 1][1]) {
					ret.push_back(intervals[i - 1]);
				} else {
					intervals[i][0] = min(intervals[i][0], intervals[i - 1][0]);
					intervals[i][1] = max(intervals[i][1], intervals[i - 1][1]);
				}
			}
			return ret;
    }
};

int main() {
	vector<vector<int>> v({{1,3},{2,6},{8,10},{15,18}});
	Solution s;
	s.merge(v);
}