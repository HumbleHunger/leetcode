#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
			stack<int> s;
			vector<int> ret(temperatures.size(), 0);
			s.push(0);
			for (int i = 1; i < temperatures.size(); ++i) {
				while (!s.empty() && temperatures[s.top()] < temperatures[i]) {
					ret[s.top()] = i - s.top();
					s.pop();
				}
				s.push(i);
			}
			return ret;
    }
};