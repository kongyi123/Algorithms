#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void) {
	long long a, b, c;

	scanf("%lld%lld%lld", &a, &b, &c);
	if (c-(a+b) >= 0 && a*b*4 < (c - (a + b)) * (c - (a + b)))
		printf("Yes");
	else printf("No");
	return 0;
}