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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
			if (root == NULL) return nullptr;

			if (root->val < low) {
				TreeNode* node = trimBST(root->right, low,high);
				return node;
			}

			if (root->val > high) {
				TreeNode* node = trimBST(root->left, low, high);
				return node;
			}

			if (root->left) root->left = trimBST(root->left, low, high);
			if (root->right) root->right = trimBST(root->right, low, high);
			return root;
    }
};