#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
	int n;
	int sum = 0;
	int a, b;
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i++) {
		fscanf(stdin, "%d %d", &a, &b);
		sum += (a*b);
	}

	fprintf(stdout, "%d", sum);
	return 0;
}