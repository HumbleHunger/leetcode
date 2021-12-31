#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> path;
    vector<vector<int>> ret;
    void f(vector<int>& nums, int target, int count, int start) {
        if (count >= target) {
            if (count == target) ret.push_back(path);
            return;
        }

        for (int i = start; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            count += nums[i];
            f(nums, target, count, i);
            path.pop_back();
            count -= nums[i];
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        f(candidates, target, 0, 0);
        return ret;
    }
};