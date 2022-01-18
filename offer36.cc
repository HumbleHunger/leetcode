#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
		Node* pre = nullptr;

    Node* treeToDoublyList(Node* root) {
			if (root == nullptr) return nullptr;

			treeToDoublyList(root->left);

			root->left = pre;
			if (pre) pre->right = root;
			pre = root;
			cout << root->val << endl;

			treeToDoublyList(root->right);
			return root;
		}
};