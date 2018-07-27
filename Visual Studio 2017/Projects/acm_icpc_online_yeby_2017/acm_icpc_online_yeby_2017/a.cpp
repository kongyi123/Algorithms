#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	long long a;
	long long b;

	fscanf(stdin, "%lld %lld", &a, &b);
	fprintf(stdout, "%lld", a*b);
	return 0;
}