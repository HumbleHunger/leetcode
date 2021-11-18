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
    TreeNode* searchBST(TreeNode* root, int val) {
			while (root && root->val != val)
			{
				if (root->val > val) {
					root = root->left;
					continue;
				}

				if (root->val < val) {
					root = root->right;
					continue;
				}
			}

			return root ? root : NULL;
			
    }
};