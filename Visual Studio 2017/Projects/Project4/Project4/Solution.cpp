/*

<����ü ���� ����- �����Ϸ��� ������ ����>

�Լ��� ��� - �Լ��� ���� �����ϴ� ��� �ڵ��� ���ʿ� �� �Լ��� ���Ǹ� �ϴ���
�Լ� ȣ��� �Լ� ���Ǻκ��� �ּҸ� �Ѿ� �����ϱ� ������ �ڵ������ �Լ� caller�� �Լ� ���Ǻ��� ���ʿ� �ִ� �Ʒ��ʿ� �ֵ� ���� ����.

����ü�ǰ�� - �޸� �� ����ü type�� ������ ������ ��(��, ����ü�� ȣ���� ��) ����ü�� �����ڸ� �ʼ������� ȣ���ϰ� �Ǿ��ִ�.
�׷���, ����ü�� ���� �����ϴ� ��쿡�� caller�� ����ü�� �ּҴ� �˸������� �����ڴ� ���ǰ� ���� �ʱ� ������ caller�� �����ڸ� ȣ���� �� �����Ƿ�
������ ������ �߻��Ѵ�. ��, �����ڸ� ���� ȣ������ �ʴ� ����ü ������ Ÿ���� ������ �޸� �� �����ϴ� ���� ���� ������ ���� �ʴ´�.
���ư� �� ������ new�� ���� ����ü�� �������ַ��� �����ڸ� ȣ���ϰԵǱ� ������ �ڵ��� ���濡 ����ü�� ���ǰ� �ݵ�� �ʿ��ϴ�.

��� => �Լ��� �׳� ���� �����ؼ� �˴���� ����ȴ�.
����ü�� ������ ���� �����Ͽ� ����ǰ�
+ �� ����ü ������ �����ؼ� ������ �����ͺ����� ����ϰ� ����ü�� �Լ� ������ �� �ڿ�   ����ü ���� �ؿ� �Լ����Ǹ� ���ش�.


<delete�� ���� ���� ���>
�޸� ������ ����� ���� ���ϸ� Dangling Object�� ���ܼ�
(new�� �ϰ� delete�� ���� ����) �޸� ��뷮�� ���������� �����Ͽ� ��ð� ������ �޸� 
���ҽ��� �� ��ų ���� �ְ� �������� ������ �̹� ������ ��ü�� ���� 
Dangling Pointer(�̹� ������ ��ü�� ����Ű�� ������)�� ���� Access Violation�̳� �������� ���� �� ���� �ֽ��ϴ�.

���������� ���α׷� ����ÿ� �̹�ȯ�� �޸� ���ҽ��� �Ϲ������� ���μ��� ������ ������鼭 �ϰ� ��ȯ�ǰ� �Ǿ� �ֽ��ϴ�. 
������ ��� ���α׷��� �׷��� �ü���� ���װ� �־ 100% ��ȯ�ȴٰ� ������ ���� ���մϴ�. �� 9X�������� 50% ���� �ǰ� 
�� ������ �ü������ �� 90%? �ֱ��� �ü������ 99.9999% ���� �ȴٰ� �� �� �ְ����� �ݴ�� 100%�� �ƴմϴ�.

*/


#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

FILE *in = fopen("input.txt", "r");
FILE *out = fopen("output.txt", "w");

using namespace std;

struct DATE {
public:
	int year;
	int month;
	int day;

	DATE(char *d);
	DATE() {}
};

DATE::DATE(char *d) {
	this->year = 2000 + (d[2] - '0') * 10 + (d[3] - '0') * 1;
	this->month = (d[4] - '0') * 10 + (d[5] - '0') * 1;
	this->day = (d[6] - '0') * 10 + (d[7] - '0') * 1;
}

template <typename T>
struct LinkedList {
	struct DATE;
	struct Node {
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






void init();
void insert(DATE date, int t, int num);
//void del(DATE date, int t);
//void search(DATE from, DATE to);

LinkedList<DATE>* list[1000];
LinkedList<int>* table[100][13][32];

void init() {

	for (int i = 0;i < 1000;i++) {
		if (list[i] != NULL) delete list[i];
		list[i] = new LinkedList<DATE>();
	}
	
	for (int i = 0;i < 100;i++) {
		for (int j = 1;j <= 12;j++) {
			for (int k = 1;k <= 31;k++) {
				if (table[i][j][k] != NULL) delete table[i][j][k];
				table[i][j][k] = new LinkedList<int>();
			}
		}
	}
}

void insert(DATE date, int t, int num) {

}



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
