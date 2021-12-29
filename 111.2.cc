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
		int minDepth(TreeNode* root) {
			if (root == nullptr) return 0;
			int leftDepth = minDepth(root->left);
			int rightDepth = minDepth(root->right);

			if (root->left && root->right) return 1 + min(leftDepth, rightDepth);
			else return 1 + max(leftDepth, rightDepth);
    }
};