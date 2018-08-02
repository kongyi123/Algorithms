/*

<구조체 전방 선언- 컴파일러의 구조와 관계>

함수의 경우 - 함수를 전방 선언하는 경우 코드의 뒤쪽에 그 함수를 정의를 하더라도
함수 호출시 함수 정의부분의 주소를 쫓아 수행하기 때문에 코드상으로 함수 caller가 함수 정의부의 윗쪽에 있던 아랫쪽에 있든 관계 없다.

구조체의경우 - 메모리 상에 구조체 type의 변수를 생성할 때(즉, 구조체를 호출할 때) 구조체의 생성자를 필수적으로 호출하게 되어있다.
그런데, 구조체를 전방 선언하는 경우에는 caller에 구조체의 주소는 알리겠지만 생성자는 정의가 되지 않기 때문에 caller가 생성자를 호출할 수 없으므로
컴파일 에러가 발생한다. 단, 생성자를 아직 호출하지 않는 구조체 포인터 타입의 변수를 메모리 상에 생성하는 것은 전혀 문제가 되지 않는다.
나아가 그 변수에 new를 통해 구조체를 생성해주려면 생성자를 호출하게되기 때문에 코드의 전방에 구조체의 정의가 반드시 필요하다.

요약 => 함수는 그냥 전방 선언해서 알던대로 쓰면된다.
구조체는 무조건 전방 정의하여 쓰면되고
+ 두 구조체 변수를 교차해서 쓰려면 포인터변수를 사용하고 구조체에 함수 선언을 한 뒤에   구조체 정의 밑에 함수정의를 해준다.


<delete를 하지 않은 경우>
메모리 관리를 제대로 하지 못하면 Dangling Object가 생겨서
(new를 하고 delete를 하지 않음) 메모리 사용량이 지속적으로 증가하여 장시간 구동시 메모리 
리소스를 고갈 시킬 수도 있고 로직상의 오류로 이미 지워진 객체에 대해 
Dangling Pointer(이미 지워진 객체를 가르키는 포인터)가 생겨 Access Violation이나 오동작을 유발 할 수도 있습니다.

마지막으로 프로그램 종료시에 미반환된 메모리 리소스는 일반적으론 프로세스 영역이 사라지면서 일괄 반환되게 되어 있습니다. 
하지만 모든 프로그램이 그렇듯 운영체제도 버그가 있어서 100% 반환된다고 보장은 하지 못합니다. 윈 9X시절에는 50% 정도 되고 
그 이후의 운영체제들은 한 90%? 최근의 운영체제들은 99.9999% 정도 된다고 볼 수 있겠지만 반대로 100%는 아닙니다.

*/

// LinkedList 자료구조를 사용하여 작성한 Calendar 예약 프로그램.


#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <time.h>

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
	this->day ++;
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
void insert(DATE date, int t, int num, int id);
void del(DATE date, int t);
int search(DATE from, DATE to);

LinkedList<DATE>* list[1000];
LinkedList<int>* cal[100][13][32];

void init() {
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

void insert(DATE date, int t, int num, int id) {
	switch (t) {
	
	case 0: // 당일
		cal[date.year - 2000][date.month][date.day]->add(id);
		list[id]->add(date);
		break;

	case 1: // 1일
		for (int i = 1;i <= num;i++) {
			cal[date.year - 2000][date.month][date.day]->add(id);
			list[id]->add(date);
			date.nextDay();
		}
		break;

	case 2: // 2일
		for (int i = 1;i <= num;i++) {
			cal[date.year - 2000][date.month][date.day]->add(id);
			list[id]->add(date);
			date.nextDay();date.nextDay();
		}
		break;

	case 3: // 1주
		for (int i = 1;i <= num;i++) {
			cal[date.year - 2000][date.month][date.day]->add(id);
			list[id]->add(date);
			date.nextWeek();
		}
		break;

	case 4: // 1달
		for (int i = 1;i <= num;i++) {
			cal[date.year - 2000][date.month][date.day]->add(id);
			list[id]->add(date);
			date.nextMonth();
		}
		break;

	case 5: // 1년
		for (int i = 1;i <= num;i++) {
			cal[date.year - 2000][date.month][date.day]->add(id);
			list[id]->add(date);
			date.nextYear();
		}
		break;


	case 6: // 5일
		for (int i = 1;i <= num;i++) {
			cal[date.year - 2000][date.month][date.day]->add(id);
			list[id]->add(date);
			for (int j = 1;j <= 5;j++) date.nextDay();
		}
		break;

	case 7: // 10일
		for (int i = 1;i <= num;i++) {
			cal[date.year - 2000][date.month][date.day]->add(id);
			list[id]->add(date);
			date.nextWeek();
			for (int j = 1;j <= 3;j++) date.nextDay();
		}
		break;

	}
}



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
			id++;
			fscanf(in, "%d", &type);
			switch (type) {
			case 0:
				fscanf(in, "%s %d %d", d, &t, &num);
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

//	print();
	
	end = clock();

	fprintf(out, "\n시간 : %d\n", end - begin);
	return 0;
}

int search(DATE from, DATE to) {
	int cnt = 0;
	while (from <= to) {
		cnt += cal[from.year - 2000][from.month][from.day]->cnt;
		from.nextDay();
	}

	return cnt;
}


// del함수 구현이 중요. 왜냐면 encapsulation을 지향하는 구현을 하기 어렵기 때문.
void del(DATE date, int t) {

	LinkedList<int>* temp_id_list;
	LinkedList<DATE>* temp_date_list;

	switch (t) {

	case 0:
		temp_id_list = cal[date.year - 2000][date.month][date.day];
		while (!(temp_id_list->isEmpty())) {
			int tid = temp_id_list->pull();
			list[tid]->delOne(date);
		}
		break;

	case 1:
		temp_id_list = cal[date.year - 2000][date.month][date.day];
		while (!(temp_id_list->isEmpty())) {
			int tid = temp_id_list->pull();
			temp_date_list = list[tid];
			while (!(temp_date_list->isEmpty())) {
				DATE tdate = temp_date_list->pull();
				cal[tdate.year - 2000][tdate.month][tdate.day]->delOne(tid);
			}
		}
		break;

	}
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

