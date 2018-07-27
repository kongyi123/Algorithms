#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int map[130][130];
long long dy[130][130];

int main(void) {
	int n;
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			fscanf(stdin, "%d", &map[i][j]);
		}
	}

	int i, j;
	long long dap;
	dy[1][1] = 1;
	for (i = 1;i <= n;i++) {
		for (j = 1;j <= n;j++) {
			if (map[i][j] == 0) continue;
			dy[i + map[i][j]][j] = dy[i + map[i][j]][j] + dy[i][j];
			dy[i][j + map[i][j]] = dy[i][j + map[i][j]] + dy[i][j];
		}
	}

	fprintf(stdout, "%lld", dy[n][n]);
	return 0;
}