#include <bits/stdc++.h>
using namespace std;
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        deque<TreeNode*> q;
        if (root) q.push_back(root);
        
				while (!q.empty()) {
					vector<int> tmp;
					int size = q.size();
					for (int i = 0; i < size; ++i) {
						TreeNode* cur = q.front();
						q.pop_front();
						tmp.push_back(cur->val);
						if (cur->left) q.push_back(cur->left);
						if (cur->right) q.push_back(cur->right);
					}
					if (ret.size() % 2 != 0) {
						reverse(tmp.begin(), tmp.end());
					}
					ret.push_back(tmp);
				}
				return ret;
    }
};