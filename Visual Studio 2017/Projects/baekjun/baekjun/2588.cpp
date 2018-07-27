#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int a, b;
	fscanf(stdin, "%d %d", &a, &b);
	int t = b;
	for (int i = 1;i <= 3;i++) {
		fprintf(stdout, "%d\n", a * (t % 10));
		t = t / 10;
	}

	fprintf(stdout, "%d", a * b);
	return 0;
}