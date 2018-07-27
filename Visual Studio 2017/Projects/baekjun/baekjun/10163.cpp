#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int table[200][200];

int main(void) {
	int n;
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i++) {
		int x, y, dx, dy;
		fscanf(stdin, "%d %d %d %d", &x, &y, &dx, &dy);
		for (int j = y;j < y + dy;j++) {
			for (int k = x;k < x + dx;k++) {
				table[j][k] = i;
			}
		}
	}

	for (int k = 1;k <= n;k++) {
		int cnt = 0;
		for (int i = 0;i <= 110;i++) {
			for (int j = 0;j <= 100;j++) {
				if (table[i][j] == k) cnt++;
			}
		}

		fprintf(stdout, "%d\n", cnt);
	}
	return 0;
}