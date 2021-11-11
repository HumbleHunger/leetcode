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
    TreeNode* invertTree(TreeNode* root) {
		queue<TreeNode*> q;
		if(root) q.push(root);

		while (!q.empty())
		{
			int size = q.size();
			TreeNode* cur;

			for (int i = 0; i < size; ++i)
			{
				cur = q.front();
				q.pop();
				if (cur->left) q.push(cur->left);
				if (cur->right) q.push(cur->right);
				swap(cur->left, cur->right);
			}
		}
		return root;
    }
};