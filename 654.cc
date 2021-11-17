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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		TreeNode* node = NULL;
		if (nums.size() <= 1) {
            if (!nums.size()) return NULL;
			node = new TreeNode(nums[0]);
	    	return node;
	    }

        auto max = std::max_element(nums.begin(), nums.end());
        node = new TreeNode(*max);

        vector<int> left(nums.begin(), max);
        vector<int> right(max + 1, nums.end());
        node->left = constructMaximumBinaryTree(left);
        node->right = constructMaximumBinaryTree(right);

        return  node;
    }
};