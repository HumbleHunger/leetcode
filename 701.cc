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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = root;
        TreeNode* pre = NULL;
        while (node) {
              pre = node;
              if (node->val > val) node = node->left;
              else node = node->right;
        }
        if (!pre) {root = new TreeNode(val); return root;}
        if (pre->val > val) {
              pre->left = new TreeNode(val);
        }
        else {
              pre->right = new TreeNode(val);
        }
      return root;
    }
};
 