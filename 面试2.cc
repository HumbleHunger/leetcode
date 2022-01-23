#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
		vector<vector<int>> ret;
    vector<vector<int>> func(int num) {
			if (num < 3) return ret;
			int left = 0;
			int right = 0;
			for (int i = 1; i <= num / 3; ++i) {
				left = i;
				right = num - 2 * left;
				while (right >= left) {
					vector<int> tmp({i, left, right});
					ret.push_back(tmp);
					right--;
					left++;
				}
			}
			return ret;
		}
};

int main(int argc, char** argv) {
	Solution s;
	int num = atoi(argv[1]);
	auto ret = s.func(num);
	for (auto& n : ret) {
		for (auto m : n) {
			cout << m << " ";
		}
		cout << endl;
	}
}