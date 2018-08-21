#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;
int dy[40][5];

int main(void) {
	scanf("%d", &N);
	dy[1][2] = 1;
	dy[1][3] = 1;
	dy[0][4] = 1;

	for (int i = 2;i <= N;i++) {
		dy[i][0] = dy[i - 1][2];
		dy[i][1] = dy[i - 1][3];
		dy[i][2] = dy[i - 1][4] + dy[i - 1][0];
		dy[i][3] = dy[i - 1][4] + dy[i - 1][1];
		dy[i][4] = dy[i - 2][4] + dy[i][0] + dy[i][1];
	}

	printf("%d", dy[N][4]);
	return 0;
}