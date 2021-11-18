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
		long long maxVal = LONG_MIN;
    bool isValidBST(TreeNode* root) {
				if (root == NULL) return true;

				bool left = isValidBST(root->left);
				if (maxVal < root->val) maxVal = root->val;
				else {
					return false;
				}

				bool right = isValidBST(root->right);

				return left && right;

		}
};