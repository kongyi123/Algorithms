#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int dataA[7][2] = {
	{0,0},
	{500, 1},
	{300, 2},
	{200, 3},
	{50, 4},
	{30, 5},
	{10, 6}
};

int dataB[6][2] = {
	{0,0},
	{512, 1},
	{256, 2},
	{128, 4}, 
	{64, 8},
	{32, 16}
};

int main(void) {
	int T, a, b;
	int sum;
	int cnt;
	fscanf(stdin, "%d", &T);
	for (int i = 1;i <= T;i++) {
		sum = 0;
		fscanf(stdin, "%d %d", &a, &b);
		if (a != 0) {
			cnt = 0;
			for (int j = 1;j <= 6;j++) {
				cnt += dataA[j][1];
				if (cnt >= a) {
					sum += dataA[j][0];
					break;
				}
			}
		}

		if (b != 0) {
			cnt = 0;
			for (int j = 1;j <= 5;j++) {
				cnt += dataB[j][1];
				if (cnt >= b) {
					sum += dataB[j][0];
					break;
				}
			}
		}

		fprintf(stdout, "%d\n", sum*10000);
	}
	return 0;
}