#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n;
	fscanf(stdin, "%d", &n);
	n = n+8+48;
	n = n % 60;

	fprintf(stdout, "%c%d", n % 12 + 'A', n % 10);
	return 0;
}