#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
			int hashs[26] = {0};
			int hasht[26] = {0};
			for (auto n : s) {
				hashs[n - 'a']++;
			}
			for (auto n : t) {
				hasht[n - 'a']++;
			}
			for (int i = 0; i < 26; ++i) {
				if (hashs[i] != hasht[i]) return false;
			}
			return true;
    }
};