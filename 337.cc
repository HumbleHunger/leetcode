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
			// 终止条件
			if (node == nullptr) return {0, 0};

			auto left = f(node->left);
			auto right = f(node->right);

			vector<int> ret;
			ret.push_back(max(left[0], left[1]) + max(right[0], right[1]));
			ret.push_back(node->val + left[0] + right[0]);

			return ret;
		}

    int rob(TreeNode* root) {
				auto ret = f(root);
				return max(ret[0], ret[1]);
    }
};