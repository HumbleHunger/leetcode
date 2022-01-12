#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ret(temperatures.size(), 0);
				deque<int> dp;
        for (int i = 0; i < temperatures.size(); ++i) {
            while (!dp.empty() && temperatures[i] > temperatures[dp.back()]) {
								int index = dp.back();
								ret[index] = i - index;
								dp.pop_back();
            }
						dp.push_back(i);
        }
				return ret;
    }
};