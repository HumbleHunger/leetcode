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
		void f(TreeNode* node, int& count, bool& ret, int& target)
		{
				count += node->val;
				if (node && !node->left && !node->right || ret)
				{
					if (count == target) ret = true;
					return;
				}

				if (node->left) {
					f(node->left, count, ret, target);
					count -= node->left->val;
				}
				if (node->right) {
					f(node->right, count, ret, target);
					count -= node->right->val;
				}
		}

    bool hasPathSum(TreeNode* root, int targetSum) {
				int count = 0;
				bool ret = 0;
				if(root) f(root, count, ret, targetSum);
				return ret;
    }	
};