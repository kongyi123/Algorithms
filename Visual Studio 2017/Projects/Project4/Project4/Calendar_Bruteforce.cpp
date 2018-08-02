// Vector 라이브러리를 사용하여 작성한 Calendar 예약 프로그램

#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <vector>
#include <cstdio>

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

void init();
void insert(DATE date, int t, int num, int id);
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

	end = clock();
	fprintf(out, "\n수행시간 : %d\n", end - begin);
	return 0;
}

vector<int> cal[100][13][32];

void init() {
	for (int i = 0;i < 100;i++) {
		for (int j = 1;j <= 12;j++) {
			for (int k = 1;k <= 31;k++) {
				cal[i][j][k].clear();
			}
		}
	}
}
void insert(DATE date, int t, int num, int id) {
	switch (t) {
	case 0:
		cal[date.year - 2000][date.month][date.day].push_back(id);
		break;

	case 1:
		for (int i = 1;i <= num;i++) {
			cal[date.year - 2000][date.month][date.day].push_back(id);
			date.nextDay();
		}
		break;

	case 2:
		for (int i = 1;i <= num;i++) {
			cal[date.year - 2000][date.month][date.day].push_back(id);
			date.nextDay();date.nextDay();
		}
		break;

	case 3:
		for (int i = 1;i <= num;i++) {
			cal[date.year - 2000][date.month][date.day].push_back(id);
			date.nextWeek();
		}
		break;

	case 4:
		for (int i = 1;i <= num;i++) {
			cal[date.year - 2000][date.month][date.day].push_back(id);
			date.nextMonth();
		}
		break;

	case 5:
		for (int i = 1;i <= num;i++) {
			cal[date.year - 2000][date.month][date.day].push_back(id);
			date.nextYear();
		}
		break;

	case 6:
		for (int i = 1;i <= num;i++) {
			cal[date.year - 2000][date.month][date.day].push_back(id);
			for (int j = 1;j <= 5;j++) date.nextDay();
		}
		break;

	case 7:
		for (int i = 1;i <= num;i++) {
			cal[date.year - 2000][date.month][date.day].push_back(id);
			for (int j = 1;j <= 3;j++) date.nextDay();
			date.nextWeek();
		}
		break;
	}
}

int search(DATE from, DATE to) {
	int cnt = 0;
	while (from <= to) {
		cnt += cal[from.year - 2000][from.month][from.day].size();
		from.nextDay();
	}

	return cnt;
}

void del(DATE date, int t) {
	switch (t) {
	case 0:
		cal[date.year - 2000][date.month][date.day].clear();
		break;

	case 1:
		for (int t = 0;t < cal[date.year - 2000][date.month][date.day].size();t ++) {
			int id = cal[date.year - 2000][date.month][date.day].at(t);
			for (int i = 0;i < 100;i++) {
				for (int j = 1;j <= 12;j++) {
					for (int k = 1;k <= 31;k++) {
						for (int l = 0;l < cal[i][j][k].size();) {
							if (cal[i][j][k].at(l) == id) {
								cal[i][j][k].erase(cal[i][j][k].begin() + l);
							}
							else l++;

						}
					}
				}
			}
		}

		cal[date.year - 2000][date.month][date.day].clear();
		break;
	}
}






