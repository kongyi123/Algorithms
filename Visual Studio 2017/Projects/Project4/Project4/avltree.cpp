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
	int height; // 높이
}Node;

Node * new_node(int key) {
	Node * newNode = new Node();
	newNode->key = key;
	newNode->height = 0; //새로운 노드는 기본적으로 단말 노드의 height를 가진다.
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
	// 양쪽 서브트리의 높이를 비교한다.
	return height(node->left) - height(node->right);
}

Node * insert(Node * node, int key) {

	// 1. 먼저 Binary Search Tree의 삽입과 같이 삽입한다.
	if (node == NULL)
		return(new_node(key));

	if (key < node->key)node->left = insert(node->left, key);
	else node->right = insert(node->right, key);
//	else if (key > node->key) node->right = insert(node->right, key);
//	else return node; //값이 같은 경우에는 BST의 삽입과 같지 않고 바로 리턴해준다.

					  // 2. height값을 변경해준다.
	node->height = 1 + MAX(height(node->left), height(node->right));

	// 3. balance한지 확인을 한다.(-1미만 1초과면 불균형)
	int bal = balance(node);

	// 4. 불균형한 경우에 rotation!
	// LL
	if (bal > 1 && key < node->left->key) return right_rotate(node);

	// RR
	if (bal < -1 && key > node->right->key) return left_rotate(node);

	// LR 두번회전(left->right)
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