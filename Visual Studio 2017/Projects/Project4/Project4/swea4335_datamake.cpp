#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
	freopen("input.txt", "w", stdout);
	srand((unsigned int)time(NULL));
	printf("500\n");
	for (int k = 1;k <= 500;k++) {
		printf("20\n");
		for (int i = 1;i <= 20;i++) {
			int a = rand() % 5 + 1;
			int b = rand() % 5 + 1;
			int c = rand() % 5 + 1;
			printf("%d %d %d\n", a, b, c);
		}
	}
	return 0;
}