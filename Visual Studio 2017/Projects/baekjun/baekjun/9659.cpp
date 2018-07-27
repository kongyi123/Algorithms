#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n;

int main(void) {
	fscanf(stdin, "%lld", &n);
	if (n % 4 == 0) {
		fprintf(stdout, "CY");
	}
	else fprintf(stdout, "SK");
	return 0;
}