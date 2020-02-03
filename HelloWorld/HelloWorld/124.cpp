// 124. Binary Tree Maximum Path Sum
/*

non-empty binary tree�� �־��� ��, maximum path sum�� ���Ͽ���.
	�� �������� path�� x ��忡�� y ��� ������ ��θ� �ǹ��Ѵ�. (x,y �� Ʈ������ any ���)
	
	�Է� : �ڽ��� ���ϴ� �ּҰ� �� �� �ִ� ����� ������ ���� Ʈ���� root
	��� :int (path�� �ִ� ����� value���� sum�� �ִ�)

*/

#define NULL 0
#define INF 2000000000

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	int max = -INF;

	int traversal(TreeNode* cur) {
		int left_val, right_val;
		left_val = right_val = 0;
		if (cur->left) left_val = traversal(cur->left);
		if (cur->right) right_val = traversal(cur->right);
		
		if (max < left_val + right_val + cur->val) {
			max = left_val + right_val + cur->val;
		}

		int tmp = 0;	
		if (tmp < right_val) tmp = right_val;
		if (tmp < left_val) tmp = left_val;
		cur->val += tmp;
		if (max < cur->val) max = cur->val;
		return cur->val;
	}
	int maxPathSum(TreeNode* root) {
		traversal(root);
		return max;
	}
};

int main(void) {
	return 0;
}