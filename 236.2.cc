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
		TreeNode* ret;
		bool f(TreeNode* node, int val1, int val2) {
			if (node == nullptr) return false;

			bool ret1 = f(node->left, val1, val2);
			bool ret2 = f(node->right, val1, val2);

			if ((ret1 && ret2) || ((node->val == val1 || node->val == val2) && (ret1 || ret2))) ret = node;
			if (ret1 || ret2 || (node->val == val1 || node->val == val2)) return true;
			return false;
		}

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
			f(root, p->val, q->val);
			return ret;			
    }
};