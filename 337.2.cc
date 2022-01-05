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
		vector<int> f(TreeNode* node) {
			if (node == nullptr) return {0, 0};

			vector<int> left = f(node->left);
			vector<int> right = f(node->right);

			vector<int> ret;
			// 偷
			ret.push_back(node->val + left[1] + right[1]);
			// 不偷
			ret.push_back(max(left[0], left[1]) + max(right[0], right[1]));
			return ret;
		}

		int rob(TreeNode* root) {
				auto ret = f(root);
				return max(ret[0], ret[1]);
		}
};