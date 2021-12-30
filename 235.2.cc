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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
			TreeNode* node = root;
			while (1) {
				if (node->val > p->val && node->val > p->val) {
					node = node->left;
				}
				else if (node->val < p->val && node->val < p->val) {
					node = node->right;
				}
				else {
					return node;
				}
			}
			return node;
		}
};