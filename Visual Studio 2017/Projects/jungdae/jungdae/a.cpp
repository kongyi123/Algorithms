#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int sum(int& a, int& b) {
	return a + b;
}

int main(void) {
	int k1 = 1;
	int k2 = 2;
	printf("%d", sum(k1, k2));

	while (1);
	return 0;
}