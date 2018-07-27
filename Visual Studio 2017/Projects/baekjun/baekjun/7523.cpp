#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
	int n;
	long long a, b; 
	long long sum = 0;
	fscanf(stdin, "%d", &n);
	
	for (int i = 1;i <= n;i++) {
		fscanf(stdin, "%lld %lld", &a, &b);
		sum = - a * (a - 1) / 2;
		sum = sum + b * (b + 1) / 2;

		fprintf(stdout, "Scenario #%d:\n", i);
		fprintf(stdout, "%lld\n\n", sum);
	}
	return 0;
}