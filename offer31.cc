#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    stack<int> s;

    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
				if (pushed.size() == 0) return true;
				map<int, int> map;
				for (int i = 0; i < pushed.size(); ++i) {
					map[pushed[i]] = i;
				}
				int n = 0;
				while (pushed[n] != popped[0] && n < pushed.size()) {
            s.push(pushed[n]);
						n++;
        }
				if (n == 0) s.push(pushed[0]);

				for (int i = 0; i < popped.size(); ++i) {
					if (!s.empty() && popped[i] == s.top()) {
						s.pop();
					} else {
						if (map[popped[i]] <= s.size() - 1) {
							return false;
						}
					}
				}
				return true;
    }
};