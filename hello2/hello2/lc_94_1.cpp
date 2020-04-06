/*
Runtime: 4 ms, faster than 38.16% of C++ online submissions for Binary Tree Inorder Traversal.
Memory Usage: 6.9 MB, less than 100.00% of C++ online submissions for Binary Tree Inorder Traversal.
*/
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> nodes;
		stack<TreeNode*> todo;
		while (root || !todo.empty()) {
			while (root) {
				todo.push(root);
				root = root->left;
			}
			root = todo.top();
			todo.pop();
			nodes.push_back(root->val);
			root = root->right;
		}
		return nodes;
	}
};