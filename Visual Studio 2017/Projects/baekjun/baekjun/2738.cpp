#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int a[110][110];
int b[110][110];

int main(void) {
	int n, m;
	fscanf(stdin, "%d %d", &n, &m);
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			fscanf(stdin, "%d", &a[i][j]);
		}
	}

	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			fscanf(stdin, "%d", &b[i][j]);
		}
	}

	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			fprintf(stdout, "%d ", a[i][j] + b[i][j]);
		}
		fprintf(stdout, "\n");
	}

	return 0;
}