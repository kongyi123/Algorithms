// bst
/*
	이전까지 풀던게 다들 너무 느려서
	결국은 logk + logk 형태가 나와야 된다고 생각하다가
	브레인스토밍하다 떠오른게 bst
	(아마 logk니까 자연히 bst가 떠오른 것 같음)
*/


#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

class Node {
public:
	int val;
	int valCnt;
	int leftCnt, rightCnt;
	Node* left;
	Node* right;
	Node() {}
	Node(int value) {
		this->val = value;
		left = right = 0;
		rightCnt = leftCnt = 0;
		this->valCnt = 1;
	}
};


class MedianFinder {
public:
	Node* tree;
	int cnt;
	/** initialize your data structure here. */

	double getMedian(Node* root, int cnt) {
		if (root->leftCnt >= cnt) {
			return getMedian(root->left, cnt);
		}
		else if (root->leftCnt + root->valCnt >= cnt) {
			return root->val;
		}
		else {
			return getMedian(root->right, cnt - (root->leftCnt + root->valCnt));
		}
		return 0;
	}


	void put(Node* root, int num) {
		if (root->val == num) {
			root->valCnt++;
		}
		else if (root->val > num) {
			if (root->leftCnt == 0) {
				root->leftCnt++;
				root->left = new Node(num);
			}
			else {
				root->leftCnt++;
				put(root->left, num);
			}
		}
		else {
			if (root->right == 0) {
				root->rightCnt++;
				root->right = new Node(num);
			}
			else {
				root->rightCnt++;
				put(root->right, num);
			}
		}
	}

	MedianFinder() {
		tree = 0;
		cnt = 0;
	}

	void addNum(int num) {
		cnt++;
		if (tree == 0) {
			tree = new Node(num);
		}
		else {
			put(tree, num);
		}
	}

	double findMedian() {
		if (cnt < 0) return 0;
		if (cnt % 2 == 0) {
			return (double)(getMedian(tree, cnt / 2) + getMedian(tree, cnt / 2 + 1)) / 2;
		}
		else {
			return getMedian(tree, cnt / 2 + 1);
		}
	}
};



/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */


int main(void) {
	MedianFinder* obj = new MedianFinder();
	double param;
	obj->addNum(-1);
	param = obj->findMedian(); printf("%lf\n", param);
	obj->addNum(-2);
	param = obj->findMedian(); printf("%lf\n", param);
	obj->addNum(-3);
	param = obj->findMedian(); printf("%lf\n", param);
	obj->addNum(-4);
	param = obj->findMedian(); printf("%lf\n", param);
	obj->addNum(-5);
	param = obj->findMedian(); printf("%lf\n", param);
	return 0;
}