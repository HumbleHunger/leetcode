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
		TreeNode* f(vector<int>& inorder, vector<int>& postorder)
		{
			if (postorder.size() == 0) return NULL;

			int rootValue = postorder.back();
			TreeNode* node = new TreeNode(rootValue);

			if (postorder.size() == 1) return node;

			int index;
			for (index = 0; index < inorder.size(); ++index)
			{
				if (inorder[index] == rootValue)
				{
					break;
				}
			}
			
			vector<int> leftInorder(inorder.begin(), inorder.begin() + index);
			vector<int> rightInorder(inorder.begin() + index + 1, inorder.end());

			vector<int> leftpostorder(postorder.begin(), postorder.begin() + leftInorder.size());
			vector<int> rightpostorder(postorder.begin() + leftInorder.size(), postorder.begin() + postorder.size() - 1);

			node->left = f(leftInorder, leftpostorder);
			node->right = f(rightInorder, rightpostorder);

			return node;
		}

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
			return f(inorder, postorder);
    }
};