#include <bits/stdc++.h>

using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
			//第一步：如果数组大小为零的话，说明是空节点了。
			if (preorder.size() == 0) return nullptr;

			//第二步：如果不为空，那么取前序数组最后一个元素作为节点元素。
			TreeNode* node = new TreeNode(preorder.front());
			if (inorder.size() == 1) {
				return node;
			}
			//第三步：找到前序数组最后一个元素在中序数组的位置，作为切割点
			int index = 0;
			for (int index = 0; index < inorder.size(); ++index) {
				if (inorder[index] == preorder.front()) break;
			}
			//第四步：切割中序数组，切成中序左数组和中序右数组 （顺序别搞反了，一定是先切中序数组）
			vector<int> leftinorder(inorder.begin(), inorder.begin() + index);
			vector<int> rightinorder(inorder.begin() + index + 1, inorder.end());
			//第五步：切割前序数组，切成前序左数组和前序右数组
			vector<int> leftpreorder(preorder.begin() + 1, preorder.begin() + leftinorder.size() + 1);
			vector<int> rightpreorder(preorder.begin() + leftinorder.size() + 1, preorder.begin() + leftinorder.size() + rightinorder.size() + 1);
			//第六步：递归处理左区间和右区间
			node->left = buildTree(leftinorder, leftpreorder);
			node->right = buildTree(rightinorder, rightpreorder);
			return node;
    }
};