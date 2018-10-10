// 2018.08.29 
// queue 작성하는거 쉽지 않다.
// 만만하게 보지 말 것.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>

template <typename T>
struct Queue {
	struct Node { // 노드 구조체
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
void Queue<T>::add(int idx, T t) { // 특정 인덱스에 추가 ~~~ 처음/중간/끝 으로 나눔
	if (idx > size) return; // 사이즈를 넘어가는 경우
	if (end == 0) { // 빈 경우
		Node *newNode = new Node(t);
		start = end = newNode;
		size++;
	}
	else {
		if (idx == 0) { // start 부분에 추가하는 경우 ~ start 포인터 처리
			Node *newNode = new Node(t, start);
			start = newNode;
			size++;
		}
		else if (idx == size) { // 끝부분 +1 인 경우
			Node *newNode = new Node(t);
			end->next = newNode;
			end = newNode;
			size++;
		}
		else { // 중간 부분인 경우
			Node *cur = start;
			Node *prev = 0;
			for (int i = 1;i <= idx;i++) {	// 첫번째 원소가 idx 0
				prev = cur;
				cur = cur->next;
			}
			Node *newNode = new Node(t, cur);
			prev->next = newNode;			// prev 포인터 변수를 사용하는 기법 ************** 중요 *******************
			size++;
		}
	}
}

template <typename T>
void Queue<T>::del(int idx) { // 처음 / 중간 / 끝으로 나눔
	if (idx >= size) return;
	else {
		if (idx == 0) { // 처음 start 포인터가 바뀜
			Node *temp = start;
			start = start->next;
			delete temp;
			size--;
			if (size == 0) start = end = 0; // 이거 빠지면 안됨!!! 중요. end포인터 관리
		}
		else if (idx == size - 1) { // 끝
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
		else { // 중간
			Node *cur = start;
			Node *prev = 0;
			for (int i = 1;i <= idx;i++) {
				prev = cur;
				cur = cur->next;
			}
			Node *temp = cur;
			prev->next = cur->next;			// 중간 삭제는 이렇게 줄줄이 next라는거...
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
void Queue<T>::add(T t) { // 끝 부분에 추가
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
		case 0:	// 뒤에 추가
			scanf("%d", &b);
			q.add(b);
			break;
		case 1: // 앞에 pop
//			printf("%d\n", q.front());
			break;

		case 2: // 앞에 삭제
			q.del(0);
			break;

		case 3: // idx에 추가
			scanf("%d %d", &idx, &b);
			q.add(idx, b);

			break;
		case 4: // idx에 있는 것 삭제
			scanf("%d", &idx);
			q.del(idx);

			break;
		}

//		printf("출력 "); q.print();
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