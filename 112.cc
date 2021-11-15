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
		int i = 0;
		vector<int> path;
		void f(TreeNode* node, int& count, vector<vector<int>>& ret, int& target)
		{
				count += node->val;
				path.push_back(node->val);
				if (node && !node->left && !node->right)
				{
					if (count == target)
					{
						ret.push_back(path);
					}
					return;
				}

				if (node->left) {
					f(node->left, count, ret, target);
					count -= node->left->val;
					path.pop_back();
				}
				if (node->right) {
					f(node->right, count, ret, target);
					count -= node->right->val;
					path.pop_back();
				}
		}
		vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
				int count = 0;
				vector<vector<int>> ret;
				if(root) f(root, count, ret, targetSum);
				return ret;
    }	
};