#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int table[310][310];

int main(void) {
	int n, m;
	fscanf(stdin, "%d %d", &n, &m);
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			fscanf(stdin, "%d", &table[i][j]);
			table[i][j] = table[i][j - 1] + table[i][j];
		}
	}

	int k;
	fscanf(stdin, "%d", &k);
	for (int i = 1;i <= k;i++) {
		int sum = 0;
		int a, b, c, d;
		fscanf(stdin, "%d %d %d %d", &a, &b, &c, &d);
		for (int j = a;j <= c;j++) {
			sum = sum + table[j][d] - table[j][b - 1];
		}
		fprintf(stdout, "%d\n", sum);
	}
	return 0;
}