#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	long a, b;
	scanf("%ld %ld", &a, &b);
	long k = 1;
	int cnt = 0;
	while (1) {
		cnt++;
		k = k * b;
		if (k > a) break;
	}
	printf("%d", cnt);
	return 0;
}