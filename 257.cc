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
    void f(TreeNode* cur, vector<int>& path, vector<string>& ret)
    {
		path.push_back(cur->val);
		// 终止条件
        if (cur->left == NULL && cur->right == NULL)
		{
			int size = path.size();
			string s;
			for (int i = 0; i < size; ++i)
			{
				s += to_string(path[i]);
				s += "->";
			}
			ret.push_back(s);
			return;
		}
		// 单层递归逻辑
		if (cur->left)
		{
			f(cur->left, path, ret);
			path.pop_back();
		}
		if (cur->right)
		{
			f(cur->right, path, ret);
			path.pop_back();
		}
    }

    vector<string> binaryTreePaths(TreeNode* root)
	{
        vector<int> path;
		vector<string> ret;
		f(root, path, ret);
		return ret;
    }
};