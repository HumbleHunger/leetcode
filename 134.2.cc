#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int count = 0;
				int min = INT32_MAX;
				for (int i = 0; i < gas.size(); ++i) {
					count += gas[i] - cost[i];
					if (count < min) min = count;
				}
				if (count < 0) return -1;
				if (min >= 0) return 0;
				count = 0;
				for (int i = gas.size() - 1; i >= 0; ++i) {
					count += gas[i] - cost[i];
					if (count + min >= 0) return i;
				}
				return -1;
    }
};

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
			int count = 0;
			int ret = 0;
			int sum = 0;
			for (int i = 0; i < gas.size(); ++i) {
					count += gas[i] - cost[i];
					sum += gas[i] - cost[i];
					if (count < 0) {
						ret = i + 1;
						count = 0;
					}
			}
			if (sum >= 0) return ret;
			return -1;
    }
};