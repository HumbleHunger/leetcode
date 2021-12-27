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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> ret;
				if (root) s.push(root);
				TreeNode* node = nullptr;
        while (!s.empty()) {
						node = s.top();
						ret.push_back(node->val);
						s.pop();
						if (node->left) s.push(node->left);
            if (node->right) s.push(node->right);
        }
				reverse(ret.begin(), ret.end());
				return ret;
    }
};