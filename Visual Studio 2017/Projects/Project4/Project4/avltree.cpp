#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <stdio.h>
#include <memory.h>

int MAX(int a, int b) {
	if (a > b) return a;
	return b;
}

int MIN(int a, int b) {
	if (a > b) return b;
	return a;
}

typedef struct node {
	int key;
	struct node * left, *right;
	int height; // ����
}Node;

Node * new_node(int key) {
	Node * newNode = new Node();
	newNode->key = key;
	newNode->height = 0; //���ο� ���� �⺻������ �ܸ� ����� height�� ������.
	newNode->left = newNode->right = NULL;
	return newNode;
}

int height(Node * node) {
	if (node == NULL) return -1;
	return node->height;
}

Node * right_rotate(Node * node) {
	Node * l = node->left;
	Node * r = l->right;

	l->right = node;
	node->left = r;

	node->height = 1 + MAX(height(node->left), height(node->right));
	l->height = 1 + MAX(height(l->left), height(l->right));

	return l;
}


Node * left_rotate(Node * node) {
	Node * r = node->right;
	Node * l = r->left;

	r->left = node;
	node->right = l;

	node->height = 1 + MAX(height(node->left), height(node->right));
	r->height = 1 + MAX(height(r->left), height(r->right));

	return r;
}



int balance(Node * node) {
	if (node == NULL) return 0;
	// ���� ����Ʈ���� ���̸� ���Ѵ�.
	return height(node->left) - height(node->right);
}

Node * insert(Node * node, int key) {

	// 1. ���� Binary Search Tree�� ���԰� ���� �����Ѵ�.
	if (node == NULL)
		return(new_node(key));

	if (key < node->key)node->left = insert(node->left, key);
	else node->right = insert(node->right, key);
//	else if (key > node->key) node->right = insert(node->right, key);
//	else return node; //���� ���� ��쿡�� BST�� ���԰� ���� �ʰ� �ٷ� �������ش�.

					  // 2. height���� �������ش�.
	node->height = 1 + MAX(height(node->left), height(node->right));

	// 3. balance���� Ȯ���� �Ѵ�.(-1�̸� 1�ʰ��� �ұ���)
	int bal = balance(node);

	// 4. �ұ����� ��쿡 rotation!
	// LL
	if (bal > 1 && key < node->left->key) return right_rotate(node);

	// RR
	if (bal < -1 && key > node->right->key) return left_rotate(node);

	// LR �ι�ȸ��(left->right)
	if (bal > 1 && key > node->left->key) {
		node->left = left_rotate(node->left);
		return right_rotate(node);
	}

	// RL
	if (bal < -1 && key < node->right->key) {
		node->right = right_rotate(node->right);
		return left_rotate(node);
	}

	return node;
}

void inorder(Node* node) {
	if (node->left != NULL) inorder(node->left);
	printf("%d\n", node->key);
	if (node->right != NULL) inorder(node->right);
}



int main(void) {
	clock_t begin, end;
	begin = clock();
	int n;
	Node* root = NULL;
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	if (n == 0) return 0;
	else {
		int dat;
		for (int i = 1;i <= n;i++) {
			scanf("%d", &dat);
			root = insert(root, dat);
		}
//		inorder(root);

	}
	end = clock();
	printf("time = %d\n", end - begin);
	return 0;

}