#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
		class ds {
			public:
				void pop(int n) {
					if (!q.empty() && n == q.front()) {
						q.pop_front();
					}
				}

				void push(int n) {
					while (q.size() > 0 && n > q.back()) {
						q.pop_back();
					}
					q.push_back(n);
				}

				int top() {
					return q.front();
				}
			private:
				deque<int> q;
		};

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
			ds dq;
			vector<int> ret;
			for (int i = 0; i < 3; ++i) {
				dq.push(nums[i]);
			}
			ret.push_back(dq.top());
			for (int i = 3; i < nums.size(); ++i) {
				dq.pop(nums[i - 3]);
				dq.push(nums[i]);
				ret.push_back(dq.top());
			}
			return ret;
    }
};