#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long a, b;

long long gcd(long long a, long long b) {
	while (a % b > 0) {
		long long t = b;
		b = a % b;
		a = t;
	}

	return b;
}

int main(void) {
	fscanf(stdin, "%lld %lld", &a, &b);
	long long g = gcd(a, b);
	for (int i = 1;i <= g;i++) {
		fprintf(stdout, "1");
	}
	return 0;
}