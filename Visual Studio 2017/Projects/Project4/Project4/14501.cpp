// 34

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n;
int dy[20];
int T[20], P[20];

int max(int a, int b) {
	if (a > b) return a;
	return b;
}

int back(int i) {
	if (i < 0) return 0;

	for (int j = 1;j <= n;j++) {
		if (i == j + T[j] - 1) {
			dy[i] = max(dy[i], back(j - 1) + P[j]);
		}
	}

	dy[i] = max(dy[i], back(i - 1));

	return dy[i];
}

int main(void) {
	scanf("%d", &n);
	for (int i = 1;i <= n;i++) {
		scanf("%d %d", &T[i], &P[i]);
	}

	printf("%d", back(n));
	return 0;
}