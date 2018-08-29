// 34
// 채점 데이터가 허접함.
// 마지막 데이터 조건 처리가 안되었는데 억셉받음 - 수정

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
	if (dy[i] != -1) return dy[i];
	for (int j = 1;j <= n;j++) {
		if (i == j + T[j]) {
			//			dy[i] = max(dy[i], back(j - 1) + P[j]);
			int temp = back(j) + P[j];
			if (dy[i] < temp) {
//				path[i] = j;
				dy[i] = temp;
			}
		}
	}
	if (dy[i] == -1) dy[i] = 0;
//	dy[i] = max(dy[i], back(i - 1));

	int temp = back(i - 1);
	if (dy[i] < temp) {
//		path[i] = i - 1;
		dy[i] = temp;
	}
	return dy[i];
}

int main(void) {
	scanf("%d", &n);
	for (int i = 1;i <= n;i++) dy[i] = -1;
	
	for (int i = 1;i <= n;i++) {
		scanf("%d %d", &T[i], &P[i]);
	}

	int ans = -1;
	for (int i = 1;i <= n;i++) {
		int temp = back(i);
		if (i + T[i] - 1 <= n) {
			temp += P[i];
		}
		if (ans < temp) {
			ans = temp;
		}
	}

	printf("%d", ans);
//	printf("\n");
//	for (int i = 1;i <= n;i++) {
//		printf("%d ", path[i]);
//	}
	return 0;
}