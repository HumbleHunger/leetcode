#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
		unordered_map<string, map<string, int>> map;
		vector<string> ret;
		bool f(int size) {
			if (ret.size() == size + 1) {
				return true;
			}

			for (auto& target : map[ret.back()]) {
				if (target.second > 0) {
					ret.push_back(target.first);
					target.second--;
					if (f(size)) return true;
					target.second++;
					ret.pop_back();
				}
			}
			return false;
		}

    vector<string> findItinerary(vector<vector<string>>& tickets) {
			for (auto& str : tickets) {
				map[str[0]][str[1]]++;
			}
			ret.push_back("JFK");
			f(tickets.size());
			return ret;
    }
};