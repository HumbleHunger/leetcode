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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ret;
		vector<int> temp;

		TreeNode* cur;
		q.push(root);
		while (!q.empty())
		{
			int size = q.size();
			// 处理每层各元素			
			for (int i = 0; i < size; ++i)
			{
				cur = q.front();
				q.pop();
				temp.push_back(cur->val);
				if(cur->left) q.push(cur->left);
				if(cur->right) q.push(cur->right);
			}
			ret.push_back(temp);
			temp.resize(0);
		}
		reverse(ret);
		return ret;
    }

};