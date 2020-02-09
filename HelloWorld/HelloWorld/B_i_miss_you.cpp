#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main(void) {
	char A[200];
	scanf("%s", &A);
	int len = strlen(A);
	for (int i = 0; i < len; i++)
		printf("x");
	return 0;
}