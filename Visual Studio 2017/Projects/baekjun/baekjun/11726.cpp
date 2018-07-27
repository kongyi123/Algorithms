#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int dy[2000];

int main(void) {
	int n;
	fscanf(stdin, "%d", &n);
	dy[1] = 1; dy[2] = 2;
	for (int i = 3;i <= n;i++) {
		dy[i] = (dy[i - 1] + dy[i - 2]) % 10007;
	}

	fprintf(stdout, "%d", dy[n]);
	return 0;
}