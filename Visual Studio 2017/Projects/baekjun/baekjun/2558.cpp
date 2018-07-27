#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int a, b;
	fscanf(stdin, "%d%d", &a, &b);
	fprintf(stdout, "%d", a + b);
	return 0;
}