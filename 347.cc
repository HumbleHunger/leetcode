#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
		for (auto i : nums)
		{
			m[i]++;
		}
		priority_queue<pair<int, int>> q;

		for (auto i : m)
		{
			pair<int, int> p;
			p.first = i.second;
			p.second = i.first;
			q.push(p);
		}
		vector<int> ret;
		for (int i = 0; i < k; ++i)
		{
			int n = q.top().second;
			q.pop();
			ret.push_back(n);
		}
        return ret;
    }
};