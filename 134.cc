#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
			vector<int> rest;
			int min = INT32_MAX;
			int count = 0;
			for (int i = 0; i < gas.size(); ++i) {
				rest[i] = gas[i] - cost[i];
				count += rest[i];
				if (count < min) min = count;
			}
			if (count < 0) return -1;
			if (min >= 0) return 0;
			count = 0;
			for (int i = rest.size() - 1; i >= 0; --i) {
				count += rest[i];
				if (count >= -min) return i;
			}
			return -1;
    }
};

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curSum = 0;
        int totalSum = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); i++) {
            curSum += gas[i] - cost[i];
            totalSum += gas[i] - cost[i];
            if (curSum < 0) {   // 当前累加rest[i]和 curSum一旦小于0
                start = i + 1;  // 起始位置更新为i+1
                curSum = 0;     // curSum从0开始
            }
        }
        if (totalSum < 0) return -1; // 说明怎么走都不可能跑一圈了
        return start;
    }
};