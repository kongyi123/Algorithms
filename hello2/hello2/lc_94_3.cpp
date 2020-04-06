/*
Runtime: 4 ms, faster than 38.16% of C++ online submissions for Binary Tree Inorder Traversal.
Memory Usage: 7 MB, less than 100.00% of C++ online submissions for Binary Tree Inorder Traversal.
*/
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> nodes;
		while (root) {
			if (root->left) {
				TreeNode* pre = root->left;
				while (pre->right && pre->right != root) {
					pre = pre->right;
				}
				if (!pre->right) {
					pre->right = root;
					root = root->left;
				}
				else {
					pre->right = NULL;
					nodes.push_back(root->val);
					root = root->right;
				}
			}
			else {
				nodes.push_back(root->val);
				root = root->right;
			}
		}
		return nodes;
	}
};