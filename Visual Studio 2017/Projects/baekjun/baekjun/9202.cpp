// 에라토스테네스의 체 / 소수 구하기

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int check[10000];

int main(void) {
	int t;
	check[1] = 1;
	for (int i = 2;i <= 10000;i++) {
		for (int j = i * 2;j <= 10000;j += i) {
			check[j] = 1;
		}
	}

	fscanf(stdin, "%d", &t);
	for (int i = 1;i <= t;i++) {
		int n;
		fscanf(stdin, "%d", &n);
		for (int j = n/2;j >= 1;j--) {
			if (check[j] == 0 && check[n - j] == 0) {
				fprintf(stdout, "%d %d\n", j, n - j);
				break;
			}
		}
	}
	return 0;
}