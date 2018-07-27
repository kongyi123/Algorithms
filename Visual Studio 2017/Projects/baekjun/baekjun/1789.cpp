#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long n;

int back(long long a, long long b) {
	if (a >= b) {
		return a;
	}
	else {
		long long mid = (a + b)/2 + 1;
		long long temp = (long long)mid * (mid + 1) / 2;
		if (temp < n) {
			return back(mid , b);
		} else if (temp > n) {
			return back(a, mid - 1);
		} else {
			return mid;
		}
	}
}


int main(void) {
	fscanf(stdin, "%ld", &n);
	long long int a;
	a = back(1, 100000);

	fprintf(stdout, "%ld", a);
	return 0;
}