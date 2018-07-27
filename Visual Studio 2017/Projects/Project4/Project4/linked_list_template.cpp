// �ǹ�. ���ø��� ���� Ŭ������ �и��� �� �ִ� �����?

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
	Node<int>* pStart;
	Node<int>* pEnd;
	int cnt;

	LinkedList() : cnt(0), pStart(NULL), pEnd(NULL) {}
	
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
		cnt++;
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


	int Search(T val) {
		if (cnt == 1) {
			if (pStart->val == val) {
				return 0;
			}
		}
		else if (cnt > 1) {
			Node<int>* cur = pStart;
			Node<int>* prev;
			int t = 0;
			while (cur != NULL) {
				if (cur->val == val) {
					return t;
				}
				prev = cur;
				cur = cur->next;
				t++;
			}
		}

		return -1;
	}


	T pull() {
		if (pStart == NULL) {
			return NULL;
		}
		else {
			Node<int>* prev = pStart;
			T temp = pStart->val;
			pStart = pStart->next;
			delete prev;
			cnt--;
			return temp;
		}
	}


	bool del(T val) { // Ư�� ���� ã�Ƽ� �����ϴ� ���
		if (cnt == 0) return false; // ���� �ƿ�  ���� ���
		
		if (pStart->val == val) {	// ù��° ����� ���� �ش��ϴ� ���
			Node<int>* temp = pStart->next;
			delete pStart;
			pStart = temp;
			cnt --;
			return true;
		}
		else {						// �ش�Ǵ� ���� �ι�° Ȥ�� �� ���Ŀ� �ִ� ���
			Node<int>* prev = pStart;
			Node<int>* cur = pStart->next;
			while (cur != NULL) {
				if (cur->val == val) {
					prev->next = cur->next;
					delete cur;
					cnt--;
					return true;
				}
				prev = cur;
				cur = cur->next;
			}
		}

		return false;
	}


	T get(int idx) {
		if (cnt <= idx) {
			return -1;
		}

		Node<int>* cur = pStart;
		for (int i = 1;i <= idx;i++) {
			cur = cur->next;
		}
		return cur->val;
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
//	fprintf(stdout, "%d\n", q->get(1));

	q->add(1);
	q->add(2);
	q->add(15);

	q->del(2);
	
//	q = make();
	while (!q->isEmpty()) {
		fprintf(stdout, "%d\n", q->pull());
	}

	

	return 0;
}