#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int dy[30][20];

int main(void) {
	int n;
	fscanf(stdin, "%d", &n);

	dy[1][0] = 1;
	dy[1][3] = 1;
	dy[1][12] = 1;
	dy[1][6] = 1;
	dy[1][16] = 1;

	for (int i = 2;i <= 30;i++) {
		dy[i][0] = dy[i - 1][16];
		dy[i][3] = dy[i - 1][12] + dy[i - 1][16];
		dy[i][6] = dy[i - 1][9] + dy[i - 1][16];
		dy[i][9] = dy[i - 1][6];
		dy[i][12] = dy[i - 1][3] + dy[i - 1][16];
		dy[i][16] = dy[i - 1][0] + dy[i][3] + dy[i][9] + dy[i][12] - dy[i - 1][16];
	}


	for (int i = 1;i <= n;i++) {
		int m;
		fscanf(stdin, "%d", &m);
		fprintf(stdout, "%d\n", dy[m][16]);
	}

	return 0;
}