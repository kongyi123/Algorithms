#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	char A[12], B[12];
	char U[12];
	int n, m;
	scanf("%s %s", &A, &B);
	scanf("%d %d", &n, &m);
	scanf("%s", &U);
	if (strcmp(A, U) == 0 && n > 0) n--;
	if (strcmp(B, U) == 0 && m > 0) m--;
	printf("%d %d", n, m);
	return 0;
}