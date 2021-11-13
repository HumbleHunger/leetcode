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
	void f(TreeNode* node, int& ret)
	{
		if (node == NULL)
		{
			return;
		}
		// 左叶子
		if (node->left && !node->left->right && !node->left->left)
		{
			ret += node->left->val;
		}

		f(node->left, ret);
		f(node->right, ret);
	}

    int sumOfLeftLeaves(TreeNode* root) {
		int ret = 0;
		f(root, ret);		
		return ret;
	}
};