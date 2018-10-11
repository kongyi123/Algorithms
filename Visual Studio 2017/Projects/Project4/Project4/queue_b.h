// 25 �̰� ������ ������ �ƴϰ����� ���δ�.
// ���� �ڵ带 ���۸��غ���
// ���� ���׿� ���ؼ� ä���� ������ �����͸� ������

#include <stdio.h>

template <typename T>
struct Queue {
	struct Node {
		int val;
		Node* next;
		Node() {}
		Node(int val) {
			this->val = val; this->next = 0;
		}
		Node(int val, Node* next) {
			this->val = val; this->next = next;
		}
	};

	int size;
	Node* start, *end;
	Queue() {
		start = end = 0;
		size = 0;
	}

	void push(int idx, int val);
	void push(int val);
	void pop(int idx);

	T front();
};

template <typename T>
void Queue<T>::push(int val) {
	push(size, val);
}

template <typename T>
T Queue<T>::front() {
	if (size == 0) return (T)0;
	return start->val;
}


template <typename T>
void Queue<T>::push(int idx, int val) {
	if (idx > size) {	// �߸��� �Է�
		printf("�߸� push\n"); return; // �߸� ���� �Է� 
	}

	if (size == 0) {	// �� ���
		Node *newNode = new Node(val);
		start = end = newNode;
		size = 1;
	}
	else { // ���� ���� ���
		Node *newNode = new Node(val); // �� ��� �������
		size++;

		if (idx == 0) { // ó��
			Node *temp = start;
			start = newNode;
			start->next = temp;
		}
		else if (idx == size) { // ��
			end->next = newNode;
			end = end->next;
		}
		else {	// �߰�
			Node *prev = start;
			Node *cur = start;
			for (int i = 1;i <= idx;i++) {
				prev = cur;
				cur = cur->next;
			}

			newNode->next = cur;
			prev->next = newNode;
		}
	}
}

template <typename T>
void Queue<T>::pop(int idx) {
	if (idx >= size) {
		printf("pop �߸���\n"); return;
	}

	if (size == 0) {
		//printf("pop �Ұ� ����");
		return;
	}
	else {
		size--;

		if (idx == 0) {
			Node *temp = start;
			start = start->next;
			delete temp;
		}
		else if (idx == size - 1) {
			Node *cur = start;
			Node *prev = start;
			for (int i = 1;i <= idx;i++) {
				prev = cur;
				cur = cur->next;
			}
			delete cur;
			end = prev;
		}
		else {
			Node *cur = start;
			Node *prev = start;
			for (int i = 1;i <= idx;i++) {
				prev = cur;
				cur = cur->next;
			}
			Node *temp = cur;
			prev->next = cur->next;
			delete temp;
		}
	}
}

