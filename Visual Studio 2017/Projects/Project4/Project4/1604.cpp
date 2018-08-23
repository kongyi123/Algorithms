#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;
double rec_line[4][4];
double new_line[100][4];
double dat_line[100][4];
int ncnt;

double x1, y1, x2, y2;

int solve() { // 영역의 수를 카운트하여 반환
	int cnt = 0;
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= 4;j++) {

		}
	}
	return cnt;
}

int main(void) {
	scanf("%d", &N);
	for (int i = 1;i <= N;i++) {
		for (int j = 0;j <= 3;j++) {
			scanf("%d", &dat_line[i][j]);
		}
	}

	printf("%d", solve());
	return 0;
}