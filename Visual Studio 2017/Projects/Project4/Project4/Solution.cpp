// 구조체 선행 정의??

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;

template <typename T>
class LinkedList;

class DATE {
public:
	int year;
	int month;
	int day;

	DATE(char *d) {
		this->year = 2000 + (d[2] - '0') * 10 + (d[3] - '0') * 1;
		this->month = (d[4] - '0') * 10 + (d[5] - '0') * 1;
		this->day = (d[6] - '0') * 10 + (d[7] - '0') * 1;
	}

	DATE() {}
};



FILE *in = fopen("input.txt", "r");
FILE *out = fopen("output.txt", "w");


void init();
void insert(DATE date, int t, int num);
//void del(DATE date, int t);
//void search(DATE from, DATE to);

template<typename T>
class LinkedList<T>;

LinkedList<int*>* list[1000];
LinkedList<int>* table[100][13][32];

void init() {
	for (int i = 0;i < 1000;i++) {
		list[i] = new LinkedList<int*>();
	}
	
	for (int i = 0;i < 100;i++) {
		for (int j = 1;j <= 12;j++) {
			for (int k = 1;k <= 31;k++) {
				table[i][j][k] = new LinkedList<int>();
			}
		}
	}
}

void insert(DATE date, int t, int num) {

}


// 15분
template <typename T>
class LinkedList {
public:
	class DATE;
	class Node {
		T val;
		Node* next;
		Node(T val) {
			this->val = val;
			this->next = NULL;
		}
	};

	Node *pStart, *pEnd;
	
	LinkedList() {
		pStart = pEnd = NULL;
	}

	~LinkedList() {
		Node *cur = pStart;
		while (cur != NULL) {
			Node *tmp = cur;
			cur = cur->next;
			delete tmp;
		}
	}

	int isEmpty() {
		if (pStart == NULL) return 1;
		return 0;
	}

	void add(T val) {
		if (pStart == NULL) {
			pStart = pEnd = new Node(val);
		}
		else {
			Node *tmp = pEnd;
			tmp->next = new Node(val);
			pEnd = tmp->next;
		}
	}

	T pull() {
		if (pStart != NULL) {
			if (pStart == pEnd) {
				T tmp_val = pStart->val;
				delete pStart;
				pStart = pEnd = NULL;
				return tmp_val;
			}
			else {
				T tmp_val = pStart->val;
				Node* tmp = pStart;
				pStart = pStart->next;
				delete tmp;
				return tmp_val;
			}
		}
	}
};




int main(void) {
	int T, N;
	int type, t, num;
	char d[8], d2[8];
	fscanf(in, "%d", &T);
	for (int tc = 1;tc <= T;tc++) {
		fscanf(in, "%d", &N);
		init();
		for (int i = 1;i <= N;i++) {
			fscanf(in, "%d", &type);
			switch (type) {
			case 0:
				fscanf(in, "%s %d %d", d, &t, &num);
				insert(DATE(d), t, num);
				break;
			case 1:
				fscanf(in, "%s %d", d, &t);
				//del(DATE(d), t);
				break;
			case 2:
				fscanf(in, "%s %s", d, d2);
				//search(DATE(d), DATE(d2));
				break;
			}
		}
	}
	return 0;
}
