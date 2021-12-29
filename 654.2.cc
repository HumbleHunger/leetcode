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
				if (nums.size() == 0) return nullptr;
				int max = 0;
				for (int i = 1; i < nums.size(); ++i) {
					if (nums[i] > nums[max]) max = i;
				}
				TreeNode* node = new TreeNode(max);

				vector<int> left(nums.begin(), nums.begin() + max);
				vector<int> right(nums.begin() + max + 1, nums.end());
				node->left = constructMaximumBinaryTree(left);
				node->right = constructMaximumBinaryTree(right);
				return node;
    }
};