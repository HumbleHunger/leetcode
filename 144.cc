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
    vector<int> preorderTraversal(TreeNode* root) {
		vector<int> ret;
		TreeNode* current = root;
		stack<TreeNode*> s;
		s.push(current);
		while (current != NULL && !s.empty())
		{
			TreeNode* node = s.top();
			s.pop();
			ret.push_back(node->val);
			if (node->right != NULL) s.push(node->right);
			if (node->left != NULL) s.push(node->left);
		}
		return ret;
    }
};