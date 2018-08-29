// 2018.08.29 
// queue �ۼ��ϴ°� ���� �ʴ�.
// �����ϰ� ���� �� ��.

/* 
	14
	0 10
	// 10
	0 20
	// 10 20
	0 30
	// 10 20 30
	1 
	// 10
	2 
	// 20 30 
	3 0 1 
	// 1 20 30
	3 1 10 
	// 1 10 20 30
	3 3 9 
	// 1 10 20 9 30
	3 5 -2 
	// 1 10 20 9 30 -2
	4 0 
	// 10 20 9 30 -2
	4 2 
	// 10 20 30 -2
	4 3 
	// 10 20 30 
	0 20 
	// 10 20 30 20
	3 4 10 
	// 10 20 30 20 10

	14
	0 10
	0 20
	0 30
	1
	2
	3 0 1
	3 1 10
	3 3 9
	3 5 -2
	4 0
	4 2
	4 3
	0 20
	3 4 10

*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

template <typename T>
struct Queue {
	struct Node { // ��� ����ü
		T val;
		Node* next;
		Node(T val) {
			this->val = val;
			this->next = 0;
		}

		Node() {}
		Node(T val, Node* next) {
			this->val = val;
			this->next = next;
		}
	};

	Node *start, *end;
	int size;
	Queue() {	
		start = end = 0;
		size = 0;
	}

	void add(T t) { // ���κп� �߰�
		if (end == 0) {	// �ƹ��͵� ���� ��
			Node *newNode = new Node(t);
			start = end = newNode;
			size = 1;
		}
		else { // �ϳ� �̻� ���Ұ� ���� ��
			Node *newNode = new Node(t);
			end = end->next = newNode;
			size++;
		}
	}

	void add(int idx, T t) { // Ư�� �ε����� �߰� ~~~ ó��/�߰�/�� ���� ����
		if (idx > size) return; // ����� �Ѿ�� ���
		if (end == 0) add(t); // �ƹ��͵� ���� �� - �׳� add�� �����ϰ� ó��
		else {
			if (idx == 0) { // start �κп� �߰��ϴ� ��� ~ start ������ ó��
				Node *newNode = new Node(t, start);
				start = newNode;
				size++;
			}
			else if (idx == size) { // ���κ� +1 �� ���
				add(t); 
			}
			else { // �߰� �κ��� ���
				Node *cur = start;
				Node *prev = 0;
				for (int i = 1;i <= idx;i++) {
					prev = cur;
					cur = cur->next;
				}
				Node *newNode = new Node(t, cur);
				prev->next = newNode;				// prev ������ ������ ����ϴ� ��� ************** �߿� *******************
				size++;
			}
		}
	}

	T pop() {
		if (end == 0) return (T)NULL;
		else {
			return start->val;
		}
	}

	void print() {
		Node *cur = start;
		for (int i = 1;i <= size;i++) {
			printf("%d ", cur->val);
			cur = cur->next;
		}
		printf("\n");
	}

	void del(int idx) { // ó�� / �߰� / ������ ����
		if (idx >= size) return;
		else {
			if (idx == 0) { // ó�� start �����Ͱ� �ٲ�
				Node *temp = start;
				start = start->next;
				delete temp;
				size--;
			} else if (idx == size - 1) { // ��
				Node *cur = start;
				Node *prev = 0;
				for (int i = 1;i <= idx;i++) {
					prev = cur;
					cur = cur->next;
				}
				delete cur;
				end = prev;
				size--;
			} else { // �߰�
				Node *cur = start;
				Node *prev = 0;
				for (int i = 1;i <= idx;i++) {
					prev = cur;
					cur = cur->next;
				}
				Node *temp = cur;
				prev->next = cur->next;			// �߰� ������ �̷��� ������ next��°�...
				delete temp;
				size--;
			}
		}
	}
};

int n;
Queue<int> q;

int main(void) {
	scanf("%d", &n);
	for (int i = 1;i <= n;i++) {
		int a, b, idx;
		scanf("%d", &a);
		switch (a) {
		case 0:	// �ڿ� �߰�
			scanf("%d", &b);
			q.add(b);
			break;
		case 1: // �տ� pop
			printf("%d\n", q.pop());
			break;

		case 2: // �տ� ����
			q.del(0);
			break;

		case 3: // idx�� �߰�
			scanf("%d %d", &idx, &b);
			q.add(idx, b);

			break;
		case 4: // idx�� �ִ� �� ����
			scanf("%d", &idx);
			q.del(idx);

			break;
		}

		q.print();
	}
	return 0;
}