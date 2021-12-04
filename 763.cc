#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
			int hash[26];
			for (int i = 0; i < s.size(); ++i) {
				hash[s[i] - 'a'] = i;
			}

			vector<int> ret;
			int n = 0;
			int count = 0;
			for (int i = 0; i < s.size(); ++i) {
				n = max(hash[s[i] - 'a'], n);
				if (i == n) {
					ret.push_back(i + 1 - count);
					count = i + 1;
				}
			}
			return ret;
    }
};