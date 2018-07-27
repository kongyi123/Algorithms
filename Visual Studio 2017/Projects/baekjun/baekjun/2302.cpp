#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int n, m;
int check[50];
int dy[50];

int main(void) {
	fscanf(stdin, "%d", &n);
	fscanf(stdin, "%d", &m);
	for (int i = 1;i <= m;i++) {
		int p;
		fscanf(stdin, "%d", &p);
		check[p] = 1;
	}

	dy[0] = dy[1] = 1;
	for (int i = 1;i <= n;i++) {
		if (check[i] == 1) dy[i] = dy[i - 1];
		else if (check[i-1] == 1) {
			dy[i] = dy[i - 1];
		}
		else dy[i] = dy[i - 1] + dy[i - 2];
	}

	fprintf(stdout, "%d", dy[n]);
	return 0;
}