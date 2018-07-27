// 의문. 템플릿이 들어가는 클래스를 분리할 수 있는 방법은?

#include <cstdio>
using namespace std;

template<typename T>
struct Node {
	T val;
	Node* next;
	Node(T val) {
		this->val = val;
		this->next = NULL;
	}
};	

template<typename T>
struct LinkedList {


	Node<int>* pStart = NULL;
	Node<int>* pEnd = NULL;
	LinkedList() {
		pStart = pStart;
	}
	
	~LinkedList() {
		Node<int>* prev;
		Node<int>* cur = pStart;

		while (cur != NULL) {
			prev = cur;
			cur = cur->next;
			delete prev;
		}
		
	}
	
	void add(T val) {
		if (pStart == NULL) {
			Node<int>* newNode = new Node<int>(val);
			pStart = pEnd = newNode;
		}
		else {
			Node<int>* newNode = new Node<int>(val);
			pEnd->next = newNode;
			pEnd = newNode;
		}
	}

	Node<int>* pull() {
		if (pStart == NULL) {
			return NULL;
		}
		else {
			Node<int>* prev = pStart;
			T temp = pStart->val;
			pStart = pStart->next;
			delete prev;
			return pStart;
		}
	}

	int isEmpty() {
		if (pStart == NULL) return 1;
		return 0;
	}

};

LinkedList<int>* make() {
	LinkedList<int> *t = new LinkedList<int>;
	for (int i = 1;i <= 5;i++) {
		t->add(i);
	}

	return t;
}

int main(void) {
	LinkedList<int>* q = new LinkedList<int>();

	q->add(1);
	q->add(2);
	q->add(15);
	Node<int>* a = q->pull();
	
	delete q;
	
	q = make();
	while (!q->isEmpty()) {
		fprintf(stdout, "%d\n", q->pull());
	}

	return 0;
}