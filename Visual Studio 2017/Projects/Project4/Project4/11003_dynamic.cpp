// 32
// 용량제한에 걸린다..
// 용량제한 = 1024 x 1024 x 256 = 268435456
// 코드 용량 = 5000001 x 22 x 4 = 440000088

// 다이나믹은 세그먼트 트리보다도 용량을 더 많이 잡아먹는다.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cmath>
#define log_ 23
int N, L;
int min[5000001][22];

int MIN(int a, int b) {
	if (a > b) return b;
	return a;
}

int MAX(int a, int b) {
	if (a > b) return a;
	return b;
}

int query(int a, int b) {
	int ans = min[a][0];
	int x = a;
	for (int i = log_;i >= 0;i--) {
		if (x + (1 << i) - 1 <= b) {
			ans = MIN(ans, min[x][i]);
			x = x + (1 << i);
		}
	}

	return ans;
}

int main(void) {
	scanf("%d%d", &N, &L);
	for (int i = 1;i <= N;i++)
		scanf("%d", &min[i][0]);

	for (int j = 1;(1 << j) <= N;j++) { 
		for (int i = 1;i <= N;i++) {
			if (i + (1 << (j - 1)) > N) continue;
			min[i][j] = MIN(min[i][j - 1], min[i + (1 << (j - 1))][j - 1]);
		}
	}

	for (int i = 1;i <= N;i++) {
		printf("%d ", query(MAX(i - L + 1, 1), i));
	}
	return 0;
}