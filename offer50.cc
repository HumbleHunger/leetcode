#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    char firstUniqChar(string s) {
        deque<char> q;
        for (auto n : s) {
            if (q.empty()) {
                q.push_back(n);
                continue;
            }
						if (n == q.front()) {
							q.pop_front();
						}
        }
				return q.front();
    }
};