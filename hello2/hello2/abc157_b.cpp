#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int f(int check[][3]) {
	if (check[0][0] && check[1][1] && check[2][2]) return 1;
	if (check[0][2] && check[1][1] && check[2][0]) return 1;
	for (int i = 0; i <= 2; i++) {
		int flag = 1;
		for (int j = 0; j <= 2; j++) {
			if (check[i][j] == 0) flag = 0;
		}
		if (flag) return 1;
	}
	for (int i = 0; i <= 2; i++) {
		int flag = 1;
		for (int j = 0; j <= 2; j++) {
			if (check[j][i] == 0) flag = 0;
		}
		if (flag) return 1;
	}
	return 0;
}

int main(void) {
	int data[3][3];
	int check[3][3] = { 0, };
	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++) {
			scanf("%d", &data[i][j]);
		}
	}
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		for (int j = 0; j <= 2; j++) {
			for (int k = 0; k <= 2; k++) {
				if (data[j][k] == t) {
					check[j][k] = 1;
					if (f(check)) {
						printf("Yes");
						return 0;
					}
				}
			}
		}
	}
	printf("No");
	return 0;
}
