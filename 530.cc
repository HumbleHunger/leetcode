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
/*
class Solution {
public:
    vector<int> nums;
		void f(TreeNode* node) {
			if (!node) return;
			f(node->left);
			nums.push_back(node->val);
			f(node->right);
		}

		int min = INT32_MAX;
    int getMinimumDifference(TreeNode* root) {
			f(root);
			int tmp = 0;
			for (int i = 1; i < nums.size(); ++i) {
				tmp = (nums[i] - nums[i-1] > 0) ? nums[i] - nums[i - 1] : nums[i - 1] - nums[i];
				if (tmp < min) min = tmp;
			}
			return min;
    }
};*/

class Solution {
public:
		int prev = -1;
		int min = INT32_MAX;
		void f(TreeNode* node) {
			if (!node) return;
			f(node->left);
			int tmp = 0;
			if (prev != -1) {
				tmp = (node->val - prev > 0) ? node->val - prev : prev - node->val;
				if (tmp < min) min = tmp;
			}
				prev = node->val;
			f(node->right);
		}
    int getMinimumDifference(TreeNode* root) {
			f(root);
			return min;
		}
};