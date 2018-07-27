#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int num[15][10] = {
	{1,1,1,1,1,1,0}, // 0
	{0,0,0,0,1,1,0}, // 1
	{1,0,1,1,0,1,1}, // 2
	{1,0,0,1,1,1,1}, // 3
	{0,1,0,0,1,1,1}, // 4
	{1,1,0,1,1,0,1}, // 5
	{1,1,1,1,1,0,1}, // 6
	{1,0,0,0,1,1,0}, // 7
	{1,1,1,1,1,1,1}, // 8
	{1,1,0,1,1,1,1} }; // 9

struct Time {
	int min_hour;
	int min_min;
	int fail;

	Time() {
		min_hour = min_min = 99;
	}

	int block_find(int arr[]) {	// 7개 단위로 계산
		int flag;
		for (int i = 0;i <= 11;i++) {
			flag = 0;
			for (int j = 0;j <= 6;j++) {
				if (num[i][j] != arr[j]) {
					flag = 1;
					break;
				}
			}

			if (flag == 0) {
				return i;
			}
		}
		
		fail = 1;
		return 0;
	}

	void put(int arr[]) {
		fail = 0;
		int hour, min;
		hour = block_find(&arr[0])*10;
		hour += block_find(&arr[7]);
		min = block_find(&arr[14])*10;
		min += block_find(&arr[21]);

		if (hour >= 24 || min >= 60) fail = 1;
		if (fail == 0) {
			if (hour < min_hour) {
				min_hour = hour;
				min_min = min;
			}
			else if (hour == min_hour && min < min_min) {
				min_min = min;
			}
		}
	}
};


int main(void) {
	int N;
	scanf("%d", &N);
	for (int tc = 1;tc <= N;tc++) {
		int data[100];
		for (int j = 1;j <= 28;j++) {
			scanf("%d", &data[j]);
		}

		Time* t = new Time();
		for (int i = 1;i <= 28;i++) {
			if (data[i] == 0) {
				data[i] = 1;
				t->put(&data[1]);
				data[i] = 0;
			}
			else {
				data[i] = 0;
				t->put(&data[1]);
				data[i] = 1;
			}
		}

		for (int i = 1;i <= 28;i++) {
			for (int j = i+1;j <= 28;j++) {
				if (i != j) {
					if (data[i] == 0) data[i] = 1;
					else data[i] = 0;
					if (data[j] == 0) data[j] = 1;
					else data[j] = 0;

					t->put(&data[1]);

					if (data[i] == 0) data[i] = 1;
					else data[i] = 0;
					if (data[j] == 0) data[j] = 1;
					else data[j] = 0;
				}
			}
		}

		printf("#%d %d %d\n", tc, t->min_hour, t->min_min);
		delete t;
	}

	return 0;
}