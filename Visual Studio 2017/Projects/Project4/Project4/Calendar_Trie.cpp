// Calendar 예약 프로그램을 작성하여라.

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <cstdio>

FILE *in = fopen("input.txt", "r");
FILE *out = fopen("output.txt", "w");

using namespace std;

void print();

struct Parse {
	int t = 0;
	int Int(char *p) {
		int pow = 1;
		for (int i = strlen(p) - 1;i >= 0;i--) {
			t += pow*(p[i] - '0');
			pow *= 10;
		}
		return t;
	}
} PARSE;

// 중요포인트.
// 전역 임시변수를 만드는 법임. 자바에 Parse.Int() 이런함수가 있는 이유.
struct String {
	char *c = new char[10];
	String(char*) {}
	String() {}
	char *str(int num) {
		int cnt = 0;
		char tmp[8];
		while (num != 0) {
			tmp[cnt++] = (num % 10) + '0';
			num = num / 10;
		}
		for (int i = 0;i < cnt;i++) c[i] = tmp[cnt - i - 1];

		c[cnt] = '\0';
		return c;
	}

	char* operator+(char b) {
		int clen = strlen(c);
		int i;
		c[clen] = b;
		c[clen + 1] = '\0';
		c[i] = '\0';
		return c;
	}

} STRING;


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
		delList = NULL;
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
		if (delList) {
			delete delList;
			delList = NULL;
		}
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

	LinkedList<String>* delList;

	void dA(Trie *cur, String temp) {
		for (int i = 0;i <= 9;i++) {
			if (cur->next[i] != NULL) {
				dA(cur->next[i], temp + char(i+'0'));
			}
		}

		if (cur->finish == true) {
			cur->finish = false;
			cnt--;
			delList->add(temp);
		}
	}

	LinkedList<String>* delAll() {
		if (delList != NULL) delete delList;
		delList = new LinkedList<String>();
		dA(this, NULL);
		for (int i = 0;i <= 9;i++) {
			if (next[i] != NULL) {
				delete next[i];
				next[i] = NULL;
			}
		}
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
	DATE() {}
	void nextYear();
	void nextMonth();
	void nextWeek();
	void nextDay();
	char* string();

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

char* DATE::string() {
	return STRING.str(year * 10000 + month * 100 + day);
}


void init();
int insert(DATE date, int t, int num, int id);
void del(DATE date, int t);
int search(DATE from, DATE to);

int main(void) {
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
		cal[date.year - 2000][date.month][date.day]->add(STRING.str(id));
		list[id]->add(date.string());
		cnt++;
		break;

	case 1:
		for (int i = 1;i <= num;i++) {
			cal[date.year - 2000][date.month][date.day]->add(STRING.str(id));
			list[id]->add(date.string());
			date.nextDay();
			cnt++;
		}
		break;

	case 2:
		for (int i = 1;i <= num;i++) {
			cal[date.year - 2000][date.month][date.day]->add(STRING.str(id));
			list[id]->add(date.string());
			date.nextDay();date.nextDay();
			cnt++;
		}
		break;

	case 3:
		for (int i = 1;i <= num;i++) {
			cal[date.year - 2000][date.month][date.day]->add(STRING.str(id));
			list[id]->add(date.string());
			date.nextWeek();
			cnt++;
		}
		break;

	case 4:
		for (int i = 1;i <= num;i++) {
			cal[date.year - 2000][date.month][date.day]->add(STRING.str(id));
			list[id]->add(date.string());
			date.nextMonth();
			cnt++;
		}
		break;

	case 5:
		for (int i = 1;i <= num;i++) {
			cal[date.year - 2000][date.month][date.day]->add(STRING.str(id));
			list[id]->add(date.string());
			date.nextYear();
			cnt++;
		}
		break;

	case 6:
		for (int i = 1;i <= num;i++) {
			cal[date.year - 2000][date.month][date.day]->add(STRING.str(id));
			list[id]->add(date.string());
			for (int j = 1;j <= 5;j++) date.nextDay();
			cnt++;
		}
		break;

	case 7:
		for (int i = 1;i <= num;i++) {
			cal[date.year - 2000][date.month][date.day]->add(STRING.str(id));
			list[id]->add(date.string());
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
		if (cal[date.year - 2000][date.month][date.day] != NULL)
			cal[date.year - 2000][date.month][date.day]->delAll();
		break;

	case 1:
		if (cal[date.year - 2000][date.month][date.day] != NULL) {
			LinkedList<String>* delList = cal[date.year - 2000][date.month][date.day]->delAll();
			while (!delList->isEmpty()) {
				int id = PARSE.Int(delList->pull());
				LinkedList<int>* delList2 = list[id]->delAll();
				while (!delList2->isEmpty()) {
					int dint = delList2->pull();
					
				}
			}

		}

		break;
	}
}

