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
    vector<vector<int>> levelOrder(TreeNode* root) {
			deque<TreeNode*> dq;
			vector<vector<int>> ret;
			if (root) dq.push_back(root);
			while (!dq.empty()) {
				vector<int> tmp;
				int size = dq.size();
				for (int i = 0; i < size; ++i) {
					TreeNode* node = dq.front();
					dq.pop_front();
					tmp.push_back(node->val);
					if (node->left) dq.push_back(node->left);
					if (node->right) dq.push_back(node->right);
				}
				ret.push_back(tmp);
			}
			return ret; 
		}
};