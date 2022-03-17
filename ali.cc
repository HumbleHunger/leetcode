#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<string> ret;
	string path;

	vector<string> v {
		{
			"0",
			"1",
			"abc",
			"def",
			"ghi",
			"jkl",
			"mon",
			"pqrs",
			"tuv",
			"wxyz"
		}
	};

	void backtrace(string str, int a, int len) {
		if (path.size() == len) {
			ret.push_back(path);
			return;
		}
		int index = str[a] - '0';
		for (int i = 0; i < v[index].size(); ++i) {
			path.push_back(v[index][i]);
			backtrace(str, a + 1, len);
			path.pop_back();
		}

	}

	vector<string> func(string str) {
		backtrace(str, 0, str.size());
		return ret;
	}
};

int main() {
	Solution s;
	string str;
	cin >> str;
	auto ret = s.func(str);
	for (auto n : ret) {
		cout << n << " ";
	}
	cout << endl;
}