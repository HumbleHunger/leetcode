#include <bits/stdc++.h>
using namespace std;
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
		vector<int> path;
		vector<vector<int>> ret;
		void backtrace(TreeNode* node, int target, int count) {
			// 叶节点终止
			if (!node->left && !node->right) {
				if (count + node->val == target) {
					path.push_back(node->val);
					ret.push_back(path);
					path.pop_back();
					return;
				}
			}

			path.push_back(node->val);
			count += node->val;
			if (node->left) {
				backtrace(node->left, target, count);
			}
			if (node->right) {
				backtrace(node->right, target, count);
			}
			path.pop_back();
			count -= node->val;
		}
		
		vector<vector<int>> pathSum(TreeNode* root, int target) {
      backtrace(root, target, 0);
			return ret; 
    }
};