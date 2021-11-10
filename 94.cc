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
    vector<int> inorderTraversal(TreeNode* root) {
		vector<int> ret;
		stack<TreeNode*> s;
		TreeNode* node = root;
		while (node != NULL || !s.empty())
		{
			if (node != NULL)
			{
				// 压入栈，回溯需要
				s.push(node);
				// 往左走
				node = node->left;
			}
			// 找到了最左边
			else
			{
				// 回溯
				node = s.top();
				// 输出
				ret.push_back(node->val);
				s.pop();
				// 往右走
				node = node->right;
			}
		}
    }
};