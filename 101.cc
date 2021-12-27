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
		bool isSymmetric(TreeNode* root) {
			deque<TreeNode*> dq;
			dq.push_back(root->left);
			dq.push_back(root->right);
			while (!dq.empty()) {
					TreeNode* leftnode = dq.front();
					dq.pop_front();
					TreeNode* rightnode = dq.front();
					dq.pop_front();

					if (!leftnode && !rightnode) continue;					
					if ((!leftnode && rightnode) || (leftnode && !rightnode) || leftnode->val != rightnode->val) return false;

					dq.push_back(leftnode->left);
					dq.push_back(rightnode->right);
					dq.push_back(leftnode->right);
					dq.push_back(rightnode->left);
			}
		
			return true; 
		}
};