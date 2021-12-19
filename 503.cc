#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
			int max = 0;
			stack<int> s;
			vector<int> ret(nums.size(), -1);
			s.push(0);

			for (int i = 1; i < nums.size(); ++i) {
				if (nums[i] > nums[max]) max = i;
				while (!s.empty() && nums[s.top()] < nums[i]) {
					ret[s.top()] = nums[i];
					s.pop();
				}
				s.push(i);
			}

			for (int i = 0; i <= max; ++i) {
				cout << i << endl;
				while (!s.empty() && nums[s.top()] < nums[i]) {
					ret[s.top()] = nums[i];
					s.pop();
				}
				s.push(i);
			}
			return ret;
    }
};

int main() {
	vector<int> v({1,2,1});
	Solution s;
	s.nextGreaterElements(v);
}