#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <ctime>
#include <cstdlib>

using namespace std;

FILE *out = fopen("output.txt", "w");

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

	int str() {
		int t;
		t = this->year * 10000;
		t += this->month * 100;
		t += this->day;
		return t;
	}

	bool isError(int e, int num) {
		DATE d2;
		d2.year = this->year;
		d2.month = this->month;
		d2.day = this->day;

		switch (e) {
		case 0:
			break;

		case 1:
			for (int i = 1;i <= num;i++) {
				d2.nextDay();
			}
			break;

		case 2:
			for (int i = 1;i <= num;i++) {
				d2.nextDay();d2.nextDay();
			}
			break;

		case 3:
			for (int i = 1;i <= num;i++) {
				d2.nextWeek();
			}
			break;

		case 4:
			for (int i = 1;i <= num;i++) {
				d2.nextMonth();
			}
			break;

		case 5:
			for (int i = 1;i <= num;i++) {
				d2.nextYear();
			}
			break;

		case 6:
			for (int i = 1;i <= num;i++) {
				for (int j = 1;j <= 5;j++) d2.nextDay();
			}
			break;

		case 7:
			for (int i = 1;i <= num;i++) {
				for (int j = 1;j <= 3;j++) d2.nextDay();
				d2.nextWeek();
			}
			break;
		}
		if (d2.year > 2000 || (d2.year == 2000 && d2.month != 1)) { return true; }
/*		if (d2.year > 2099) {
			return true;
		}*/
		else return false;
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


int main() {
	srand((unsigned int)time(NULL));
	int T = 10;
	int flag;
	fprintf(out, "%d\n", T);
	DATE date;
	for (int k = 1;k <= T;k++) {
		int N = 99999;
		fprintf(out, "%d\n", N);
		int type;
		int a, b, c, d, e, f;
		flag = 0;
		for (int i = 1;i <= N;i++) {
			if (flag == 1) {
				type = 0;
				flag = 0;
			}
			else {
				type = rand() % 3;
			}
			switch (type) {
			case 0:
//				date.year = 2000 + rand() % 100;
				date.year = 2000;
//				date.month = rand() % 12 + 1;
				date.month = 1;
				if (date.month == 2) date.day = rand() % 28 + 1;
				else date.day = rand() % 30 + 1;

				e = rand() % 8;
//				f = rand() % 100;
				f = rand() % 30;

				if (!date.isError(e, f)) fprintf(out, "0 %d %d %d\n", date.str(), e, f);
				else {
					flag = 1;
					i--;
					continue;
				}

				break;

			case 1:
				//				b = rand() % 12 + 1;
				b = 1;
				if (b == 2) c = rand() % 28 + 1;
				else c = rand() % 30 + 1;
				//				a = 20000000 + (rand() % 100) * 10000 + b * 100 + c;
				a = 20000000 + b * 100 + c;
				e = rand() % 2;
				fprintf(out, "1 %d %d\n", a, e);

				break;

			case 2:
//				b = rand() % 12 + 1;
				b = 1;
				if (b == 2) c = rand() % 28 + 1;
				else c = rand() % 30 + 1;
				a = 20000000 + b * 100 + c;
				fprintf(out, "2 %d ", a);

				int a2;
				do {
					b = rand() % 12 + 1;
					if (b == 2) c = rand() % 28 + 1;
					else c = rand() % 30 + 1;
					//					a2 = 20000000 + (rand() % 100) * 10000 + b * 100 + c;
					a2 = 20000000 + b * 100 + c;
				} while (a2 <= a);
				
				fprintf(out, "%d\n", a2);

				break;
			}
		}
	}
	
	return 0;
}