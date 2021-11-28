#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
		vector<string> ret;

		void next_path(const vector<vector<string>>& tickets, string start, vector<bool>& used) {
			cout << "start is " << start << endl;
			for (auto n : used) {
				cout << n;
			}
			cout << endl;



			ret.push_back(start);
			if (ret.size() == tickets.size() + 1) {
				return;
			}

			string next("ZZZZ");
			for (int i = 0; i < tickets.size(); ++i) {
				if (tickets[i][0] == start) {
					if (tickets[i][1] < next && !used[i]) {
						used[i] = true;
						if (next != string("ZZZZ")) {
							for (int j = 0; j < i; ++j) {
								if (tickets[j][1] == next) {
									used[j] = false;
								}
							}
						}
						next = tickets[i][1];

					}
				}
			}
            if (next == "ZZZZ") {
                ret.pop_back();
                string s = ret.back();
                ret.pop_back();
                next_path(tickets, s, used);
								for (int j = 0; j < tickets.size(); ++j) {
									if (tickets[j][1] == start && tickets[j][0] == s) {
										used[j] = false;
										break;
									}
								}
            } else {
                next_path(tickets, next, used);
            }
		}

    vector<string> findItinerary(const vector<vector<string>>& tickets) {
			vector<bool> used(tickets.size(), false);
            next_path(tickets, "JFK", used);
			return ret;
    }
};

int main() {
	Solution s;
	s.findItinerary({{"JFK","KUL"},{"JFK","NRT"},{"NRT","JFK"}});
}