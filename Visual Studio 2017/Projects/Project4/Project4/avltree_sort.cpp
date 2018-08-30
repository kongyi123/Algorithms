// 높이 때문에 미완
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Node {
	int data;
	int height;
	Node *left;
	Node *right;
	Node(int data) {
		this->data = data;
		height = 1;
		this->left = this->right = 0;
	}
};

struct AVLTree {
	Node *root;
	AVLTree(int data) {
		root = new Node(data);
	}

	Node* RotateLL(Node* node);
	Node* RotateRR(Node* node);
	Node* RotateLR(Node * node);
	Node* RotateRL(Node * node);

	int Height(Node *node);
	int HeightDiff(Node* node);
	Node* Rebalance(Node* node);
	Node* insert(Node* node, int data);

	void inorder(Node* node);
};

Node* AVLTree::RotateLL(Node* node) {
	Node* parentNode = node;
	Node* childNode = parentNode->left;
	parentNode->left = childNode->right;
	childNode->right = parentNode;
	parentNode->height = Height(parentNode);
	childNode->height = Height(childNode);
	return childNode;
}


Node *AVLTree::RotateRR(Node* node) {
	Node* parentNode = node;
	Node* childNode = parentNode->right;
	parentNode->right = childNode->left;
	childNode->left = parentNode;
	parentNode->height = Height(parentNode);
	childNode->height = Height(childNode);
	return childNode;
}

Node* AVLTree::RotateLR(Node* node) {
	Node* parentNode = node;
	Node* childNode = parentNode->left;
	parentNode->left = RotateRR(childNode);

	if (childNode->right) childNode->right->height = Height(childNode->right);
	childNode->height = Height(childNode);
	parentNode->height = Height(parentNode);
	return RotateLL(parentNode);
}

Node *AVLTree::RotateRL(Node* node) {
	Node* parentNode = node;
	Node* childNode = parentNode->right;
	parentNode->right = RotateLL(childNode);

	if (childNode->left) childNode->left->height = Height(childNode->left);
	childNode->height = Height(childNode);
	parentNode->height = Height(parentNode);
	return RotateRR(parentNode);
}

int max(int a, int b) {
	if (a > b) return a;
	return b;
}


int AVLTree::Height(Node* node) {
	if (node == NULL) return 0;
	int t = node->height;
	if (node->left != NULL) t = max(t, node->left->height+1);
	if (node->right != NULL) t = max(t, node->right->height+1);
	return node->height = t;

/*	if (node == NULL) return 0;

	int leftHeight = Height(node->left);
	int rightHeight = Height(node->right);

	if (leftHeight > rightHeight) return leftHeight + 1;
	else return rightHeight + 1;*/
	
}

int AVLTree::HeightDiff(Node* node) {
	if (node == NULL) return 0;
	return - Height(node->left) + Height(node->right);
}

Node* AVLTree::Rebalance(Node* node) {
	int hDiff = HeightDiff(node);
	if (hDiff <= -2) {
		if (HeightDiff(node->left) <= -1) node = RotateLL(node);
		else node = RotateLR(node);
	}
	else if (hDiff >= 2) {
		if (HeightDiff(node->right) >= 1) node = RotateRR(node);
		else node = RotateRL(node);
	}
	
	return node;
}

Node* AVLTree::insert(Node* node, int data) {
	if (node == NULL) {
		node = new Node(data);
		return node;
	}
	else if (node->data > data) {
		node->left = insert(node->left, data);
		node = Rebalance(node);
		node->height = Height(node);
	}
	else { // if (node->data < data) {
		node->right = insert(node->right, data);
		node = Rebalance(node);
		node->height = Height(node);
	}
	return node;
}

void AVLTree::inorder(Node* root) {
	if (root->left != NULL) inorder(root->left);
	printf("%d\n", root->data);
	if (root->right != NULL) inorder(root->right);
}

int main(void) {
	int n;
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	if (n == 0) return 0;
	else {
		int dat;
		scanf("%d", &dat);
		AVLTree t(dat);
		for (int i = 1;i < n;i++) {
			scanf("%d", &dat);
			t.root = t.insert(t.root, dat);
		}
		t.inorder(t.root);
	
	}
	return 0;

}