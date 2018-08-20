// 30

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define INF 0x7fffffff

int N, half;
int dat[30][30];
int min = INF;
int total;

// 뽑은 사람 수, bitmask주소, 남은 사람중 가장 작은 번호
inline int abs(int val) {
	if (val < 0) return -val;
	return val;
}

int sum1, sum2;
void back(int cnt, int bitmask, int next) {
	if (cnt == half) {
		sum1 = sum2 =  0;
		for (int i = 1;i <= N;i++) {
			if (bitmask & (1 << (i - 1))) continue;
			for (int j = 1;j <= N;j++) {
				if (bitmask & (1 << (j - 1))) continue;
				sum2 += dat[i][j];
			}
		}

		for (int i = 1;i <= N;i++) {
			if (!(bitmask & (1 << (i - 1)))) continue;
			for (int j = 1;j <= N;j++) {
				if (!(bitmask & (1 << (j - 1)))) continue;
				sum1 += dat[i][j];
			}
		}

		if (min > abs(sum1 - sum2)) {
			min = abs(sum1 - sum2);
		}
		return;
	}

	for (int i = next;i <= N;i++) {
		back(cnt + 1, bitmask | (1 << (i - 1)), i + 1);
	}
}

int main(void) {
	scanf("%d", &N);
	half = N / 2;
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			scanf("%d", &dat[i][j]);
			total += dat[i][j];
		}
	}

	back(0, 0, 1);
	printf("%d", min);
	return 0;
}