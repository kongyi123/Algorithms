#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
	int n;
	long long sum = 0, sum2 = 0;
	int a, b;
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i++) {
		sum = 0;
		fscanf(stdin, "%d %d", &a, &b);
		for (int j = 1;j <= a;j++) {
			sum += b;
			sum = sum % 1000000007;
		}

		int t = 1;
		for (int j = 1;j <= b - 1;j++) t = t * 2;

		for (int j = 1;j <= t;j++) {
			sum2 = sum2 + sum;
			sum2 = sum2 % 1000000007;
		}

	}

	fprintf(stdout, "%lld", sum2);
	return 0;
}