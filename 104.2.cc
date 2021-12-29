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
		int getDepth(TreeNode* node) {
			if (node == nullptr) {
				return 0;
			}
			int leftDepth = getDepth(node->left);
			int rightDepth = getDepth(node->right);

			return 1 + max(leftDepth, rightDepth);
		}

    int maxDepth(TreeNode* root) {
			return getDepth(root);
    }
};