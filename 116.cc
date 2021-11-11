class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
		if(root) q.push(root);

		while (!q.empty())
		{
			int size = q.size();
			Node* cur;

			for (int i = 0; i < size; ++i)
			{
				cur = q.front();
				q.pop();
                if (i < size - 1)
				    cur->next = q.front();
				if (cur->left) q.push(cur->left);
				if (cur->right) q.push(cur->right);
			}
		}
        return root;
    }
};