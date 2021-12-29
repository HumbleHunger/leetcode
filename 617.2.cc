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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
			int n = 0;
			if (!root1 && !root2) return nullptr;
			else if (!root1) n = root2->val;
			else if (!root2) n = root1->val;
			else n = root1->val + root2->val;

			TreeNode* node = new TreeNode(n);

			node->left = mergeTrees(root1 ? root1->left : nullptr, root2 ? root2->left : nullptr);
			node->right = mergeTrees(root1 ? root1->right : nullptr, root2 ? root2->right : nullptr);
			return node;
		}
		
};