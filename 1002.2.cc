#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
			int hash1[26] = {0};
			int hash2[26] = {0};
			for (auto n : words[0]) {
				hash1[n - 'a']++;
			}

			for (auto word : words) {
				for (auto n : word) {
					hash2[n - 'a']++;
				}

				for (int i = 0; i < 26; ++i) {
					hash1[i] = min(hash1[i], hash2[i]);
				}

				memset(hash2, 0, 26 * sizeof(int));
			}

			vector<string> ret;
			for (int i = 0; i < 26; ++i) {
				while (hash1[i] != 0) {
					string s;
					ret.push_back(s + 'a');
					hash1[i]--;
				}
			}
			return ret;
    }
};