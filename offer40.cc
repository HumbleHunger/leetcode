#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        priority_queue<int> q;
				for (int i = 0; i < k; ++i) {
					q.push(arr[i]);
				}

				for (int i = k; i < arr.size(); ++i) {
					if (q.top() > arr[i]) {
						q.pop();
						q.push(arr[i]);
					}
				}
				vector<int> ret(k, 0);
				for (int i = 0; i < k; ++i) {
					ret.push_back(q.top());
					q.pop();
				}
				return ret;			
    }
};