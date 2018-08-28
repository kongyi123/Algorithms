// 34

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n;
int dy[20];
int T[20], P[20];
int path[20];

int max(int a, int b) {
	if (a > b) return a;
	return b;
}

int back(int i) {
	if (i < 0) return 0;

	for (int j = 1;j <= n;j++) {
		if (i == j + T[j] - 1) {
//			dy[i] = max(dy[i], back(j - 1) + P[j]);
			int temp = back(j - 1) + P[j];
			if (dy[i] < temp) {
				path[i] = j-1;
				dy[i] = temp;
			}
		}
	}

//	dy[i] = max(dy[i], back(i - 1));
	int temp = back(i - 1);
	if (dy[i] < temp) {
		path[i] = i - 1;
		dy[i] = temp;
	}

	return dy[i];
}

int main(void) {
	scanf("%d", &n);
	for (int i = 1;i <= n;i++) {
		scanf("%d %d", &T[i], &P[i]);
	}

	printf("%d", back(n));
	// printf("\n");
//	for (int i = 1;i <= n;i++) {
//		printf("%d ", path[i]);
//	}
	return 0;
}