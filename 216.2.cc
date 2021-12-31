#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
		vector<int> path;
		vector<vector<int>> ret;
		void f(int k, int n, int start, int count) {
			if (path.size() == k && count == n) {
				ret.push_back(path);
				return;
			}

			for (int i = start; i <= 10 - k + 1 + path.size() && count <= n; ++i) {
				path.push_back(i);
				count += i;
				f(k, n, i + 1, count);
				count -= i;
				path.pop_back();
			}
		}

    vector<vector<int>> combinationSum3(int k, int n) {
			f(k, n, 1, 0);
			return ret;
    }
};