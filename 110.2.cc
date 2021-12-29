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
				return true;
			}
			int left = getDepth(node->left);
			int right = getDepth(node->right);

			if (abs(left - right) <= 1) return 1 + max(left, right);
			return false;
		}

    bool isBalanced(TreeNode* root) {
			return getDepth(root);
    }
};