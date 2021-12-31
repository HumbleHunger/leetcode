#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
		vector<int> path;
		vector<vector<int>> ret;
    void f(int n, int k, int start) {
			if (path.size() == k) {
				ret.push_back(path);
				return;
			}

			for (int i = start; i < n; ++i) {
				path.push_back(i);
				f(n, k, start + 1);
				path.pop_back();
			}
		}

    vector<vector<int>> combine(int n, int k) {
			f(n, k, 0);
			return ret;
    }
};