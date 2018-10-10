// 2018.08.29 
// queue �ۼ��ϴ°� ���� �ʴ�.
// �����ϰ� ���� �� ��.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>

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
	Queue() : start(0), end(0), size(0) {}

	void add(int idx, T t);
	void del(int idx);


	void add(T t);
	T front();


	void print();
};

template <typename T>
void Queue<T>::add(int idx, T t) { // Ư�� �ε����� �߰� ~~~ ó��/�߰�/�� ���� ����
	if (idx > size) return; // ����� �Ѿ�� ���
	if (end == 0) { // �� ���
		Node *newNode = new Node(t);
		start = end = newNode;
		size++;
	}
	else {
		if (idx == 0) { // start �κп� �߰��ϴ� ��� ~ start ������ ó��
			Node *newNode = new Node(t, start);
			start = newNode;
			size++;
		}
		else if (idx == size) { // ���κ� +1 �� ���
			Node *newNode = new Node(t);
			end->next = newNode;
			end = newNode;
			size++;
		}
		else { // �߰� �κ��� ���
			Node *cur = start;
			Node *prev = 0;
			for (int i = 1;i <= idx;i++) {	// ù��° ���Ұ� idx 0
				prev = cur;
				cur = cur->next;
			}
			Node *newNode = new Node(t, cur);
			prev->next = newNode;			// prev ������ ������ ����ϴ� ��� ************** �߿� *******************
			size++;
		}
	}
}

template <typename T>
void Queue<T>::del(int idx) { // ó�� / �߰� / ������ ����
	if (idx >= size) return;
	else {
		if (idx == 0) { // ó�� start �����Ͱ� �ٲ�
			Node *temp = start;
			start = start->next;
			delete temp;
			size--;
			if (size == 0) start = end = 0; // �̰� ������ �ȵ�!!! �߿�. end������ ����
		}
		else if (idx == size - 1) { // ��
			Node *cur = start;
			Node *prev = 0;
			for (int i = 1;i <= idx;i++) {
				prev = cur;
				cur = cur->next;
			}
			delete cur;
			end = prev;
			size--;
		}
		else { // �߰�
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

template <typename T>
T Queue<T>::front() {
	if (end == 0) return (T)NULL;
	else {
		return start->val;
	}
}



template <typename T>
void Queue<T>::add(T t) { // �� �κп� �߰�
	add(size, t);
}

template <typename T>
void Queue<T>::print() {
	Node *cur = start;
	for (int i = 1;i <= size;i++) {
		printf("%d ", cur->val);
		cur = cur->next;
	}
	printf("\n");
}

int n;
Queue<int> q;

int main(void) {
	freopen("input.txt", "r", stdin);
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
//			printf("%d\n", q.front());
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

//		printf("��� "); q.print();
	}

	int dcheck[] = { 10, 20, 30, 20, 10 };
	int cnt = 0;
	while (q.front()) {
		if (q.front() == dcheck[cnt]) {
			cnt++;
		}
		q.del(0);
	}

	if (cnt == 5) printf("Accepted!\n");
	_getch();
	return 0;
}