/*
	���� ��� ��̴� �����ε�...
	Ʈ�� Ž���� �־�� ������ ���õ� �κ��� �Ʒ� �ڵ忡 �� ������ Ȯ���ϰ� �����ϰ� �Ѿ ��.


*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	vector<int> arr;
	void back(TreeNode* root) {
		if (root->left != NULL) back(root->left);
		printf("%3d", root->val);
		arr.push_back(root->val);
		if (root->right != NULL) back(root->right);
	}

	void makebal(TreeNode* root, int s, int e) {
		if (s <= e) {
			int mid = (s + e) / 2;
			root->val = arr[mid];
			printf("%3d", root->val);
			if (s <= mid - 1) {
				root->left = new TreeNode(0);
				makebal(root->left, s, mid - 1);
			}

			if (mid + 1 <= e) {
				root->right = new TreeNode(0);
				makebal(root->right, mid + 1, e);
			}
		}

/*
		�Ʒ��� ���� �ϴ� ����� ����, ���ڷ� �������� null�� �Ǿ���ϸ� �����ϴ� �ɷ� �ߴµ�, 
		������ ���ʿ� �ȸ���� �Ŷ� ������ �� ������ �ڲ� ��������... �ƴѰ�����. 
		�ѹ� �ڼ��� ¤�� �Ѿ ��.

		if (s <= e) {
			int mid = (s + e) / 2;
			root->val = arr[mid];
			printf("%3d", root->val);

			root->left = new TreeNode(0);
			root->right = new TreeNode(0);

			makebal(root->left, s, mid - 1);
			makebal(root->right, mid + 1, e);
		} else delete root;

*/
	}

	TreeNode* balanceBST(TreeNode* root) {
		back(root);
		TreeNode* res;
		printf("\n");
		if (!arr.empty()) {
			res = new TreeNode(0);
			makebal(res, 0, arr.size() - 1);
		}
		return res;
	}
};