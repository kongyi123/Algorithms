#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <malloc.h>

using namespace std;

FILE *in = fopen("input.txt", "r");
FILE *out = fopen("output.txt", "w");

template <typename T>
class LinkedList {
public:
	class Node {
	public:
		T val;
		Node *next;
		Node(T val, Node* next) {
			this->val = val;
			this->next = next;
		}
	};

	Node* pStart = NULL;
	Node* pEnd = NULL;
	Node* current;

	T del(int idx) {
		if (pStart == NULL) {
			return -1;
		}
		else {
			if (idx == 0) {
				T temp = pStart->val;
				pStart = pStart->next;
				return temp;
			}
			else {
				Node* before = current = pStart;
				for (int i = 1;i <= idx;i++) {
					before = current;
					current = current->next;
				}
				T temp = current->val;
				before->next = current->next;
				return temp;
			}
		}
	}

	void add(int val) {
		if (pStart == NULL) {
			current = new Node(val, NULL);
			pStart = pEnd = current;
		}
		else {
			current = new Node(val, NULL);
			pEnd->next = current;
			pEnd = current;
		}
	}

	void print() {
		if (pStart == NULL) {
			fprintf(out, "empty");
		}
		else {

			current = pStart;
			while (current != NULL) {
				fprintf(out, "%d ", current->val);
				current = current->next;
			}
		}
	}
};



int main(void) {
	LinkedList<int> q;

	int N;
	fscanf(in, "%d", &N);
	for (int i = 1;i <= N;i++) {
		int val;
		fscanf(in, "%d", &val);
		q.add(val);
	}

	q.del(4);
	q.print();



}