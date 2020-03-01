// 5346. Linked List in Binary Tree
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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

bool result;
int a;

void back(ListNode* head, TreeNode* root) {
	if (head->val == root->val) {
		if (head->next == NULL) {
			result = true;
			return;
		}

		if (root->left != NULL) back(head->next, root->left);
		if (root->right != NULL) back(head->next, root->right);
	}
}

void order(ListNode* head, TreeNode* root) {
	if (result == true) return;
	if (a == root->val) back(head, root);

	if (root->left != NULL) order(head, root->left);
	if (root->right != NULL) order(head, root->right);
}

class Solution {
public:
	bool isSubPath(ListNode* head, TreeNode* root) {
		result = false;
		a = head->val;
		order(head, root);
		return result;
	}
};