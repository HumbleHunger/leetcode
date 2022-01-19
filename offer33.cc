#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    bool f(int i, int j, vector<int>& v) {
			if (j <= i + 1) return true;
			int k = 0;
			for (k = 0; k < j; ++k) {
				if (v[k] == v[j - 1]) {
					break;
				}
			}

			for (int l = k; l < j - 1; ++l) {
				if (v[l] <= v[j - 1]) return false;
			}

			return f(i, k, v) && f(k, j - 1, v);
    }

    bool verifyPostorder(vector<int>& postorder) {
			 int i = 0;
       int j = postorder.size();
			 return f(i, j, postorder);
    }
};