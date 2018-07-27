#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int a, b;
	while (1) {
		fscanf(stdin, "%d %d", &a, &b);
		if (a == 0 && b == 0) break;
		fprintf(stdout, "%d\n", a + b);
	}
	return 0;
}