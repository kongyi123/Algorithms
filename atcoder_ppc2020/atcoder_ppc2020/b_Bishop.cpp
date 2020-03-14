#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	long long n, m;
	scanf("%lld%lld", &n, &m);
	if (n == 1 || m == 1) printf("1");
	else printf("%lld", (n * m + 1) / 2);
	return 0;
}