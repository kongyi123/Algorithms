#include <stdio.h>
#define NULL 0
#define INF 1000000000

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct dpVal {
	int childOnCamera;
	int curNoMonitor;
	int curOnCamera;
};

int min(int a, int b) {
	if (a > b) return b;
	return a;
}

int min(int a, int b, int c) {
	return min(min(a, b), c);
}

dpVal tour(TreeNode* cur) {
	dpVal left, right;
	dpVal temp;
	temp.childOnCamera = temp.curOnCamera = temp.curNoMonitor = INF;

	if (cur->left && cur->right) {
		left = tour(cur->left);
		right = tour(cur->right);
		temp.childOnCamera = min(left.curOnCamera + min(right.childOnCamera, right.curNoMonitor+1, right.curOnCamera), 
									right.curOnCamera + min(left.childOnCamera, left.curNoMonitor+1, left.curOnCamera));
	
		if (left.childOnCamera < INF && right.childOnCamera < INF) temp.curNoMonitor = left.childOnCamera + right.childOnCamera;
		int minLeft = min(left.childOnCamera, left.curOnCamera, left.curNoMonitor);
		int minRight = min(right.childOnCamera, right.curOnCamera, right.curNoMonitor);
		temp.curOnCamera = minLeft + minRight + 1;
	}
	else if (cur->left) {
		left = tour(cur->left);
		temp.childOnCamera = left.curOnCamera;
		
		if (left.childOnCamera < INF) temp.curNoMonitor = left.childOnCamera;

		int minLeft = min(left.childOnCamera, left.curOnCamera, left.curNoMonitor);
		temp.curOnCamera = minLeft + 1;
	}
	else {
		right = tour(cur->right);
		temp.childOnCamera = right.curOnCamera;
	
		if (right.childOnCamera < INF) temp.curNoMonitor = right.childOnCamera;

		int minRight = min(right.childOnCamera, right.curOnCamera, right.curNoMonitor);
		temp.curOnCamera = minRight + 1;
	}

	return temp;
}
 
class Solution {
public:
	int minCameraCover(TreeNode* root) {
		dpVal val = tour(root);
		int min = val.childOnCamera;
		if (min > val.curNoMonitor + 1) min = val.curNoMonitor + 1;
		if (min > val.curOnCamera) min = val.curOnCamera;
		return min;
	}
};

int main(