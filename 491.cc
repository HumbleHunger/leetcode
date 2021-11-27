#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
		vector<vector<int>> ret;
		vector<int> path;
		void f(vector<int>& v, int start) {
        if (path.size() > 1) ret.push_back(path);
			for (int i = start; i < v.size(); ++i) {
				if (i > start && v[i] == v[i - 1]) continue;
				path.push_back(v[i]);
				f (v, i + 1);
				path.pop_back();
			}
		}

    vector<vector<int>> findSubsequences(vector<int>& nums) {
			int len = 1;
			int start = 0;
			vector<int> v;
			for (int i = 0; i < nums.size() - 1; ++i) {
					if (nums[i + 1] >= nums[i]) {
						len++;
					} else {
						if (len > 1) {
							vector<int> sub(nums.begin() + start, nums.begin() + start + len);
							f(sub, 0);
						}
						len = 1;
						start = i + 1;
					}
			}
			vector<int> sub(nums.begin() + start, nums.begin() + start + len);
			f(sub, 0);
      return ret;
    }
};

int main() {
	vector<int> v{4, 6, 7, 7};
	Solution s;
	s.findSubsequences(v);
}