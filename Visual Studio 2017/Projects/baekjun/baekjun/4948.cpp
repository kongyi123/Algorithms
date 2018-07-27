// 에라토스테네스의 체

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int check[300000];

int main(void) {
	int i, j;
	for (int i = 2;i <= 250000;i++) {
		check[i] = 1;
	}

	for (i = 2;i <= 250000;i++) {
		for (j = i *2;j <= 250000;j+= i) {
			check[j] = 0;
		}
	}

	for (int i = 1;i <= 250000;i++) {
		check[i] = check[i] + check[i - 1];
	}
	int n;
	while (1) {
		fscanf(stdin, "%d", &n);
		if (n == 0) break;
		fprintf(stdout, "%d\n", check[2*n] - check[n]);
		
	}
	return 0;
}