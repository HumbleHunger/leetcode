#include <bits/stdc++.h>

using namespace std;

class TreeNode;

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
		vector<pair<int, int*>> ret;
		void f(TreeNode* node) {
			if (!node) return;

			f(node->left);
			ret.push_back({node->val, &node->val});
			f(node->right);
		}

    TreeNode* convertBST(TreeNode* root) {
			f(root);

			for (int i = 0; i < ret.size(); ++i) {
				int count = 0;
				for (int j = i; j < ret.size(); ++j) {
					count += ret[j].first;
				}
				*ret[i].second = count;
			}

			return root;
    }
};