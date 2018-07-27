#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
	long long a, b, c;
	fscanf(stdin, "%lld %lld %lld", &a, &b, &c);
	fprintf(stdout, "%lld", a + b + c);
	return 0;
}