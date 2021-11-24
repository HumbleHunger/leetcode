#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
		const string letterMap[10] = {
    "", // 0
    "", // 1
    "abc", // 2
    "def", // 3
    "ghi", // 4
    "jkl", // 5
    "mno", // 6
    "pqrs", // 7
    "tuv", // 8
    "wxyz", // 9
		};

		string path;
		vector<string> ret;
		vector<int> order;

		void backtracking(int index, int k) {
			if (path.size() == k) {
				ret.push_back(path);
				return;
			}

			for (auto &n : letterMap[index]) {
				path.push_back(n);
				backtracking(order[path.size()], k);
				path.pop_back();
			}
		}

    vector<string> letterCombinations(string digits) {
			for (auto n : digits) {
				order.push_back(atoi(&n));
			}
			backtracking(order[0], digits.size());
			return ret;
    }
};

int main() {
	Solution s;
	string str("23");
	for (auto &n : s.letterCombinations(str) ) {
		cout << n << endl;
	}
}