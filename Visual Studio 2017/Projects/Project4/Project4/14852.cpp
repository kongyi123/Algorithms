#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int dy[1000010];
int N;

int main(void) {
	dy[1] = 1;
	dy[2] = 2;
	scanf("%d", &N);
	for (int i = 3;i <= N;i++) {
		dy[i] = dy[i - 1] + dy[i - 2];
	}

	printf("%d", dy[N]);
	return 0;
}