
// LinkedList 자료구조를 사용하여 작성한 Calendar 예약 프로그램.



#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <time.h>
#include <vector>

FILE *in = fopen("input.txt", "r");
FILE *out = fopen("output.txt", "w");

using namespace std;

void print();

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

void init();
int insert(DATE date, int t, int num, int id);
int del(DATE date, int t);
int search(DATE from, DATE to);

LinkedList<DATE>* list[1000];
LinkedList<int>* cal[100][13][32];




void init() {
	//	init_t(); // test_code

	for (int i = 0;i < 1000;i++) {
		if (list[i] != NULL) delete list[i];
		list[i] = new LinkedList<DATE>();
	}

	for (int i = 0;i < 100;i++) {
		for (int j = 1;j <= 12;j++) {
			for (int k = 1;k <= 31;k++) {
				if (cal[i][j][k] != NULL) delete cal[i][j][k];
				cal[i][j][k] = new LinkedList<int>();
			}
		}
	}


}

int insert(DATE date, int t, int num, int id) {
	//	DATE d2 = date;
	int cnt = 0;

	switch (t) {

	case 0: // 당일
		cal[date.year - 2000][date.month][date.day]->add(id);
		list[id]->add(date);
		cnt++;
		break;

	case 1: // 1일
		for (int i = 1;i <= num;i++) {
			cal[date.year - 2000][date.month][date.day]->add(id);
			list[id]->add(date);
			date.nextDay();
			cnt++;
		}
		break;

	case 2: // 2일
		for (int i = 1;i <= num;i++) {
			cal[date.year - 2000][date.month][date.day]->add(id);
			list[id]->add(date);
			date.nextDay();date.nextDay();
			cnt++;
		}
		break;

	case 3: // 1주
		for (int i = 1;i <= num;i++) {
			cal[date.year - 2000][date.month][date.day]->add(id);
			list[id]->add(date);
			date.nextWeek();
			cnt++;
		}
		break;

	case 4: // 1달
		for (int i = 1;i <= num;i++) {
			cal[date.year - 2000][date.month][date.day]->add(id);
			list[id]->add(date);
			date.nextMonth();
			cnt++;
		}
		break;

	case 5: // 1년
		for (int i = 1;i <= num;i++) {
			cal[date.year - 2000][date.month][date.day]->add(id);
			list[id]->add(date);
			date.nextYear();
			cnt++;
		}
		break;


	case 6: // 5일
		for (int i = 1;i <= num;i++) {
			cal[date.year - 2000][date.month][date.day]->add(id);
			list[id]->add(date);
			for (int j = 1;j <= 5;j++) date.nextDay();
			cnt++;
		}
		break;

	case 7: // 10일
		for (int i = 1;i <= num;i++) {
			cal[date.year - 2000][date.month][date.day]->add(id);
			list[id]->add(date);
			date.nextWeek();
			for (int j = 1;j <= 3;j++) date.nextDay();
			cnt++;
		}
		break;

	}

	// test_code
	/*	int check_cnt;
	if (cnt != (check_cnt = insert_t(d2, t, num, id))) {
	return -1;
	}
	*/
	return cnt;
} // ok



int main(void) {
	clock_t begin, end;
	begin = clock();
	/*
	LinkedList<int> temptest;
	temptest.add(1);
	temptest.add(2);
	temptest.delOne(2);
	*/

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
				if (insert(DATE(d), t, num, id) == -1) {
					printf("insert error!\n");
				}
				break;
			case 1:
				fscanf(in, "%s %d", d, &t);
				if (del(DATE(d), t) == -1) {
					printf("del error!\n");
				}
				break;
			case 2:
				fscanf(in, "%s %s", d, d2);
				fprintf(out, "%d\n", search(DATE(d), DATE(d2)));
				break;
			}
			//printf("%d\n", i);
		}
	}

	//	print();

	end = clock();

	fprintf(out, "\n시간 : %d\n", end - begin);
	return 0;
}


int search(DATE from, DATE to) {
	//	DATE from2 = from;
	int cnt = 0;
	//	int check_cnt = 0;
	while (from <= to) {
		cnt += cal[from.year - 2000][from.month][from.day]->cnt;
		//		check_cnt += cal_t[from.year - 2000][from.month][from.day].size();
		//		if (cnt != check_cnt) {
		//			cnt = cnt;
		//		}
		from.nextDay();
	}

	/*	// test_code
	//	int check_cnt;
	if (cnt != (check_cnt = search_t(from2, to))) {
	printf("search Error\n");
	}*/
	return cnt;
}


// del함수 구현이 중요. 왜냐면 encapsulation을 지향하는 구현을 하기 어렵기 때문.
int del(DATE date, int t) {
	LinkedList<int>* temp_id_list;
	LinkedList<DATE>* temp_date_list;

	int cnt = 0;
	int cflag;

	switch (t) {

	case 0:
		cflag = 0;
		temp_id_list = cal[date.year - 2000][date.month][date.day];
		while (!(temp_id_list->isEmpty())) {
			int tid = temp_id_list->pull();
			list[tid]->delOne(date);
			cnt++;
		}
		break;

	case 1:
		cflag = 1;
		temp_id_list = cal[date.year - 2000][date.month][date.day];
		while (!(temp_id_list->isEmpty())) {
			int tid = temp_id_list->pull();
			//			cnt++;
			temp_date_list = list[tid];
			while (!(temp_date_list->isEmpty())) {
				DATE tdate = temp_date_list->pull();
				cnt++;
				cal[tdate.year - 2000][tdate.month][tdate.day]->delOne(tid);
			}
		}
		break;

	}

	/*	// test_code
	int check_cnt;
	if (cnt != (check_cnt = del_t(date, t))) {
	return -1;
	}*/
	return 1;

}








void print() {
	fprintf(out, "\n==============================\n");
	fprintf(out, "List\n");
	int flag;
	DATE d;
	for (int i = 0;i < 1000;i++) {
		flag = 0;
		while (!(list[i]->isEmpty())) {
			d = list[i]->pull();
			fprintf(out, "%d.%d.%d ", d.year, d.month, d.day);
			flag = 1;
		}
		if (flag) fprintf(out, "\n");
	}

	int id;

	fprintf(out, "\nCalendar\n");
	for (int i = 0;i < 100;i++) {
		for (int j = 1;j <= 12;j++) {
			for (int k = 1;k <= 31;k++) {
				if (!(cal[i][j][k]->isEmpty())) {
					fprintf(out, "%d.%d.%d : ", 2000 + i, j, k);
				}

				flag = 0;
				while (!(cal[i][j][k]->isEmpty())) {
					id = cal[i][j][k]->pull();
					fprintf(out, "%d ", id);
					flag = 1;
				}
				if (flag) fprintf(out, "\n");
			}
		}
	}


}

