// 2018.08.29 
// queue 작성하는거 쉽지 않다.
// 만만하게 보지 말 것.

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
	Queue() {	
		start = end = 0;
		size = 0;
	}

	void add(T t) { // 끝부분에 추가
		if (end == 0) {	// 아무것도 없을 때
			Node *newNode = new Node(t);
			start = end = newNode;
			size = 1;
		}
		else { // 하나 이상 원소가 있을 때
			Node *newNode = new Node(t);
			end = end->next = newNode;
			size++;
		}
	}

	void add(int idx, T t) { // 특정 인덱스에 추가 ~~~ 처음/중간/끝 으로 나눔
		if (idx > size) return; // 사이즈를 넘어가는 경우
		if (end == 0) add(t); // 아무것도 없을 때 - 그냥 add와 동일하게 처리
		else {
			if (idx == 0) { // start 부분에 추가하는 경우 ~ start 포인터 처리
				Node *newNode = new Node(t, start);
				start = newNode;
				size++;
			}
			else if (idx == size) { // 끝부분 +1 인 경우
				add(t); 
			}
			else { // 중간 부분인 경우
				Node *cur = start;
				Node *prev = 0;
				for (int i = 1;i <= idx;i++) {
					prev = cur;
					cur = cur->next;
				}
				Node *newNode = new Node(t, cur);
				prev->next = newNode;				// prev 포인터 변수를 사용하는 기법 ************** 중요 *******************
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

	void del(int idx) { // 처음 / 중간 / 끝으로 나눔
		if (idx >= size) return;
		else {
			if (idx == 0) { // 처음 start 포인터가 바뀜
				Node *temp = start;
				start = start->next;
				delete temp;
				size--;
			} else if (idx == size - 1) { // 끝
				Node *cur = start;
				Node *prev = 0;
				for (int i = 1;i <= idx;i++) {
					prev = cur;
					cur = cur->next;
				}
				delete cur;
				end = prev;
				size--;
			} else { // 중간
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
};

int n;
Queue<int> q;

int main(void) {
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
			printf("%d\n", q.pop());
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

		q.print();
	}
	return 0;
}