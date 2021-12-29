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
		vector<int> path;
		vector<string> ret;
		void t(TreeNode* node) {
			if (node->left == nullptr && node->right == nullptr) {
				string sPath;
  			for (int i = 0; i < path.size() - 1; i++) { // 将path里记录的路径转为string格式
    	    sPath += to_string(path[i]);
    	    sPath += "->";
    		}
    		sPath += to_string(path[path.size() - 1]); // 记录最后一个节点（叶子节点）
    		ret.push_back(sPath);
			}
			path.push_back(node->val);
			// 左右
			if (node->left) t(node->left);
			if (node->right) t(node->right);
		}

		vector<string> binaryTreePaths(TreeNode* root) {
        if (root) t(root);
				return ret;
    }
};