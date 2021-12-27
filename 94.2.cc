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
		stack<TreeNode*> s;
        vector<int> ret;
        TreeNode* cur = root;
        while (cur != nullptr || !s.empty()) {
			if (cur != nullptr) {
				s.push(cur);
                cur = cur->left;
			} else {
                TreeNode* node = s.top();
                ret.push_back(node->val);
                s.pop();
                cur = node->right;
            }
        }
        return ret;
	}	
};