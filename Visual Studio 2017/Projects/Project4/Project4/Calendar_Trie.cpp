// 트라이를 일단 지저분하게 완성을 했다.
// 자료구조의 구현이 익숙하지도 못하고
// 숫자 삭제만 가능한 형태로 만들었는데, 문자 삭제를 어떤식으로 구현할지 고민해봐야.
// 삭제한 리스트를 보유하는 데 LinkedList<String>* 타입이 꼭 필요했는지, 필요하지 않아보이는데 그부분을 검토 해볼 것.

// <다음 구현 할 과제>
// 0. 트라이를 다시 재정리한다. <- 이건 지겨우니까 나중에 하던가..
// 1. 여러가지 해싱기법을 통한 해시
// 2. AVL tree 적용
// 3. 벡터를 직접 구현해볼 것.

// Calendar 예약 프로그램을 작성하여라.

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <cstdio>
#include <time.h>

FILE *in = fopen("input.txt", "r");
FILE *out = fopen("output.txt", "w");

using namespace std;

void print();
// 중요포인트.
// 전역 임시변수를 만드는 법임. 자바에 Parse.Int() 이런함수가 있는 이유.
struct String {
	int len;
	char *c;

	String() {
		c = NULL;
		len = 0;
	}

	String(char* t) {
		if (t == NULL) {
			len = 0;
		}
		else {
			len = strlen(t);
			c = new char[len + 1];
			strcpy(c, t);
			c[len] = '\0';
		}
	}



	int length() {
		return len;
	}

	String operator+(char b) {
		char* tstr = new char[len + 2];
		strcpy(tstr, c);
		tstr[len] = b;
		tstr[len + 1] = '\0';

		String tmp(tstr);

		return tmp; // 임시 객체는 지워지지만 value를 반환 하며, 그 value는 힙으로 할당된 주소값 혹은 int값이기 때문에 전혀문제없음.
	}


} STRING;

struct Parse {
	int t = 0;
	int Int(String p) {
		t = 0;
		int pow = 1;
		for (int i = p.len - 1;i >= 0;i--) {
			t += pow*(p.c[i] - '0');
			pow *= 10;
		}
		return t;
	}
} PARSE;




template <typename T>
struct LinkedList {
	struct Node {
		T val;
		Node* next;
		Node(T val) {
			this->val = val;
			this->next = NULL;
		}
	};

	Node *pStart, *pEnd;
	int cnt;

	LinkedList() {
		pStart = pEnd = NULL;
		cnt = 0;
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

	int size() {
		return cnt;
	}

	void add(T val) {
		cnt++;
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
			cnt--;
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

		return NULL;
	}

	void delOne(T val) {
		if (isEmpty()) return;		// 0개 일 때
		if (pStart == pEnd) {		// 1개 일 때
			if (pStart->val == val) pull();
			return;
		}

		if (pStart->val == val) {	// 2개 이상일 때
			pull();
			return;
		}

		Node* cur = pStart;
		Node* prev = cur;
		cur = cur->next;
		while (cur != NULL) { // 이거 틀려서 정답 안나왔었다 주의할것.
			if (cur->val == val) {
				prev->next = cur->next;
				if (pEnd == cur) pEnd = prev;
				delete cur;
				cnt--;
				return;
			}
			prev = cur;
			cur = cur->next;
		}
	}
};



struct Trie {
	int cnt;
	bool finish;
	Trie* next[10];

	Trie() {
		cnt = 0;
		finish = false;
		for (int i = 0;i <= 9;i++) next[i] = NULL;
	}

	~Trie() {
		for (int i = 0;i <= 9;i++) {
			if (next[i]) {
				delete next[i];
				next[i] = NULL;
			}
		}
	}

	void add(int t) {
		char A[100];
		sprintf(A, "%d", t);
		add(A);
	}

	void add(char *p) {
		cnt++;
		if (*p == '\0') finish = true;
		else {
			int cur = *p - '0';
			if (next[cur] == NULL) next[cur] = new Trie();
			next[cur]->add(p + 1);
		}
	}

	bool search(char *p) {
		if (*p == '\0') return finish;
		int cur = *p - '0';
		if (next[cur] == NULL) return false;

		return next[cur]->search(p + 1);
	}


	void dA(LinkedList<String>* delList, int temp) {
		for (int i = 0;i <= 9;i++) {
			if (next[i] != NULL) next[i]->dA(delList, temp * 10 + i);			
		}

		if (finish == true) {
			finish = false;
			cnt--;
			char A[100];
			sprintf(A, "%d", temp);
			delList->add(A);
		}
	}

	int delOne(char* p) {
		if (finish == true && *p == '\0') {
			finish = false;
			cnt--;
			return 1;
		}
		if (*p == '\0') return 0;
		
		int cur = *p - '0';
		if (next[cur] == NULL) return 0;

		int flag = next[cur]->delOne(p + 1);
		if (flag == 1) cnt--;
		return flag;
	}

	LinkedList<String>* delAll() {
		LinkedList<String>* delList = new LinkedList<String>();
		this->dA(delList, 0);
		for (int i = 0;i <= 9;i++) {
			if (next[i] != NULL) {
				delete next[i];
				next[i] = NULL;
			}
		}
		cnt = 0;
		return delList;
	}


};



int DayOfMonth(int yy, int mm) {
	if (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12) {
		return 31;
	}
	else if (mm == 2) return 28;
	return 30;
}

struct DATE {
	int year;
	int month;
	int day;

	DATE(char *d);
	DATE(int x) {
		this->year = x / 10000;
		x %= 10000;
		this->month = x / 100;
		x %= 100;
		this->day = x;
	}
	DATE() {}
	void nextYear();
	void nextMonth();
	void nextWeek();
	void nextDay();
	int Int();

	bool operator<=(DATE d) {
		if (this->year < d.year) {
			return true;
		}
		else if (this->year == d.year) {
			if (this->month < d.month) {
				return true;
			}
			else if (this->month == d.month) {
				if (this->day <= d.day) {
					return true;
				}
			}
		}
		return false;
	}

	bool operator==(DATE d) {
		if (this->year == d.year && this->month == d.month && this->day == d.day) {
			return true;
		}
		return false;
	}
};

DATE::DATE(char *d) {
	this->year = 2000 + (d[2] - '0') * 10 + (d[3] - '0') * 1;
	this->month = (d[4] - '0') * 10 + (d[5] - '0') * 1;
	this->day = (d[6] - '0') * 10 + (d[7] - '0') * 1;
}

void DATE::nextDay() {
	this->day++;
	if (DayOfMonth(this->year, this->month) < this->day) {
		this->day = 1;
		this->month++;
		if (12 < this->month) {
			this->month = 1;
			this->year++;
		}
	}
}


void DATE::nextWeek() {
	this->day += 7;
	if (DayOfMonth(this->year, this->month) < this->day) {
		this->day %= DayOfMonth(this->year, this->month);
		this->month++;
		if (12 < this->month) {
			this->month = 1;
			this->year++;
		}
	}
}

void DATE::nextMonth() {
	this->month++;
	if (12 < this->month) {
		this->month = 1;
		this->year++;
	}
}

void DATE::nextYear() {
	this->year++;
}

int DATE::Int() {
	return year * 10000 + month * 100 + day;
}


void init();
int insert(DATE date, int t, int num, int id);
void del(DATE date, int t);
int search(DATE from, DATE to);

int main(void) {
	clock_t begin, end;
	begin = clock();

	int T, N;
	int type, t, num, id;
	char d[10], d2[10];
	fscanf(in, "%d", &T);
	for (int tc = 1;tc <= T;tc++) {
		fscanf(in, "%d", &N);
		id = 0;
		init();
		for (int i = 1;i <= N;i++) {
			fscanf(in, "%d", &type);
			switch (type) {
			case 0:
				fscanf(in, "%s %d %d", d, &t, &num);
				id++;
				insert(DATE(d), t, num, id);
				break;
			case 1:
				fscanf(in, "%s %d", d, &t);
				del(DATE(d), t);
				break;
			case 2:
				fscanf(in, "%s %s", d, d2);
				fprintf(out, "%d\n", search(DATE(d), DATE(d2)));
				break;
			}
		}
	}
	end = clock();
	fprintf(out, "\n%d", end - begin);

	return 0;
}

Trie* cal[100][13][31];
Trie* list[1000];

void init() {
	for (int i = 0;i < 100;i++) {
		for (int j = 1;j <= 12;j++) {
			for (int k = 1;k <= 31;k++) {
				if (cal[i][j][k] != NULL) delete cal[i][j][k];
				cal[i][j][k] = new Trie();
			}
		}
	}

	for (int i = 1;i < 1000;i++) {
		if (list[i] != NULL) delete list[i];
		list[i] = new Trie();
	}
}


int insert(DATE date, int t, int num, int id) {
	int cnt = 0;
	switch (t) {
	case 0:
		cal[date.year - 2000][date.month][date.day]->add(id);
		list[id]->add(date.Int());
		cnt++;
		break;

	case 1:
		for (int i = 1;i <= num;i++) {
			cal[date.year - 2000][date.month][date.day]->add(id);
			list[id]->add(date.Int());
			date.nextDay();
			cnt++;
		}
		break;

	case 2:
		for (int i = 1;i <= num;i++) {
			cal[date.year - 2000][date.month][date.day]->add(id);
			list[id]->add(date.Int());
			date.nextDay();date.nextDay();
			cnt++;
		}
		break;

	case 3:
		for (int i = 1;i <= num;i++) {
			cal[date.year - 2000][date.month][date.day]->add(id);
			list[id]->add(date.Int());
			date.nextWeek();
			cnt++;
		}
		break;

	case 4:
		for (int i = 1;i <= num;i++) {
			cal[date.year - 2000][date.month][date.day]->add(id);
			list[id]->add(date.Int());
			date.nextMonth();
			cnt++;
		}
		break;

	case 5:
		for (int i = 1;i <= num;i++) {
			cal[date.year - 2000][date.month][date.day]->add(id);
			list[id]->add(date.Int());
			date.nextYear();
			cnt++;
		}
		break;

	case 6:
		for (int i = 1;i <= num;i++) {
			cal[date.year - 2000][date.month][date.day]->add(id);
			list[id]->add(date.Int());
			for (int j = 1;j <= 5;j++) date.nextDay();
			cnt++;
		}
		break;

	case 7:
		for (int i = 1;i <= num;i++) {
			cal[date.year - 2000][date.month][date.day]->add(id);
			list[id]->add(date.Int());
			for (int j = 1;j <= 3;j++) date.nextDay();
			date.nextWeek();
			cnt++;
		}
		break;
	}

	return cnt;
}

int search(DATE from, DATE to) {
	int cnt = 0;
	while (from <= to) {
		if (cal[from.year-2000][from.month][from.day] != NULL) 
			cnt += cal[from.year-2000][from.month][from.day]->cnt;
		from.nextDay();
	}

	return cnt;
}



void del(DATE date, int t) {
	switch (t) {
	case 0:
		if (cal[date.year - 2000][date.month][date.day] != NULL) {
			LinkedList<String>* delList =  new LinkedList<String>();
			cal[date.year - 2000][date.month][date.day]->delAll();
		}
		break;

	case 1:
		if (cal[date.year - 2000][date.month][date.day] != NULL) {
			LinkedList<String>* delList = cal[date.year - 2000][date.month][date.day]->delAll();
			while (!delList->isEmpty()) {
				int id = PARSE.Int(delList->pull());
				LinkedList<String>* delList2 = list[id]->delAll();
				while (!delList2->isEmpty()) {
					int dint = PARSE.Int(delList2->pull()); // 날짜
					// 그 날짜에 저장된 id를 하나씩 삭제
					DATE d(dint);
					char A[100];
					sprintf(A, "%d", id);
					cal[d.year - 2000][d.month][d.day]->delOne(A);
				}
			}

		}

		break;
	}
}

