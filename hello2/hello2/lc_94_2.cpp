/*
Runtime: 8 ms, faster than 38.16 % of C++ online submissions for Binary Tree Inorder Traversal.
Memory Usage : 6.9 MB, less than 100.00 % of C++ online submissions for Binary Tree Inorder Traversal.
*/
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> nodes;
		inorder(root, nodes);
		return nodes;
	}
private:
	void inorder(TreeNode* root, vector<int>& nodes) {
		if (!root) {
			return;
		}
		inorder(root->left, nodes);
		nodes.push_back(root->val);
		inorder(root->right, nodes);
	}
};