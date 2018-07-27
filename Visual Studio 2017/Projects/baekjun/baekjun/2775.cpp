#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int table[16][16];

int main(void) {
	int t;
	int n;
	int k;
	fscanf(stdin, "%d", &t);

	for (int i = 1;i <= 15;i++) table[0][i] = i;

	for (int i = 1;i <= 15;i++) {
		table[i][1] = 1;
		for (int j = 2;j <= 15;j++) {
			table[i][j] = table[i - 1][j] + table[i][j - 1];
		}
	}

	for (int i = 1;i <= t;i++) {
		fscanf(stdin, "%d%d", &k, &n);
		fprintf(stdout, "%d\n", table[k][n]);

	}
	return 0;
}