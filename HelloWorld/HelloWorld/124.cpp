// 124. Binary Tree Maximum Path Sum
/*

non-empty binary tree가 주어질 때, maximum path sum을 구하여라.
	이 문제에서 path란 x 노드에서 y 노드 까지의 경로를 의미한다. (x,y 는 트리상의 any 노드)
	
	입력 : 자식을 향하는 주소가 두 개 있는 노드들로 구성된 이진 트리의 root
	출력 :int (path에 있는 노드의 value들의 sum의 최대)

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