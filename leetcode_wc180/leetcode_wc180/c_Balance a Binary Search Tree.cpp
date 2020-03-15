/*
	제일 길게 헤맸던 문제인듯...
	트리 탐색에 있어서의 포인터 관련된 부분을 아래 코드에 쓴 내용을 확실하게 정리하고 넘어갈 것.


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
		아래와 같이 일단 만들어 놓고, 인자로 보낸다음 null이 되어야하만 삭제하는 걸로 했는데, 
		로직은 애초에 안만드는 거랑 동일할 것 같은데 자꾸 오류가남... 아닌가보다. 
		한번 자세히 짚고 넘어갈 것.

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