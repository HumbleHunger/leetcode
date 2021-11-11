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
    vector<int> rightSideView(TreeNode* root) {
		vector<int> ret;
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
				cur->next = q.front();
				if (cur->left) q.push(cur->left);
				if (cur->right) q.push(cur->right);
			}
			ret.push_back(cur->val);
		}
		return ret;
    }
};