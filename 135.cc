#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
			vector<int> v;
			v.push_back(1);
			// 使右孩子比左孩子大的情况
			for (int i = 1; i < ratings.size(); ++i) {
				if (ratings[i] > ratings[i - 1]) {
					v.push_back(v[i - 1] + 1);
				}
				else v.push_back(1);
			}

			for (int i = ratings.size() - 2; i >= 0; --i) {
				if (ratings[i] > ratings[i + 1]) {
					v[i] = max(v[i], v[i + 1] + 1);
				}
			}
			int ret = 0;
			for (auto &n : v) {
				ret += n;
			}
			return ret;
		}
};