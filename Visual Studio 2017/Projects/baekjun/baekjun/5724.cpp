#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int sum[110];

int main(void) {
	for (int i = 1;i <= 100;i++) {
		sum[i] = sum[i - 1] + i*i;
	}

	while (1) {
		int n;
		fscanf(stdin, "%d", &n);
		if (n == 0) break;
		else fprintf(stdout, "%d\n", sum[n]);
	}
	return 0;
}