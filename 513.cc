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
    int findBottomLeftValue(TreeNode* root) {
		queue<TreeNode*> que;
		if (root) que.push(root);
		TreeNode* node;
		vector<vector<int>> ret;

		while (!que.empty())
		{
			int size = que.size();
			vector<int> temp;
			for (int i = 0; i < size; ++i)
			{
				node = que.front();
				que.pop();
				temp.push_back(node->val);
				if (node->left) que.push(node->left);
				if (node->right) que.push(node->right);
			}
			ret.push_back(temp);
		}
		return ret[ret.size() - 1][0];
    }
};