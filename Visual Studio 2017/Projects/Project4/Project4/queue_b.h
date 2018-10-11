// 25 이게 완전한 정답은 아니것으로 보인다.
// 정답 코드를 구글링해보고
// 예외 사항에 대해서 채점이 가능한 데이터를 만들자

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
	if (idx > size) {	// 잘못된 입력
		printf("잘못 push\n"); return; // 잘못 들어온 입력 
	}

	if (size == 0) {	// 빈 경우
		Node *newNode = new Node(val);
		start = end = newNode;
		size = 1;
	}
	else { // 비지 않은 경우
		Node *newNode = new Node(val); // 새 노드 만들어줌
		size++;

		if (idx == 0) { // 처음
			Node *temp = start;
			start = newNode;
			start->next = temp;
		}
		else if (idx == size) { // 끝
			end->next = newNode;
			end = end->next;
		}
		else {	// 중간
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
		printf("pop 잘못됨\n"); return;
	}

	if (size == 0) {
		//printf("pop 할거 없음");
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

