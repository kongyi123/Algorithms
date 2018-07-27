#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
	long long n;
	int no = 0;
	fscanf(stdin, "%lld", &n);
	while (n / 2) {
		if (n % 2 == 1) {
			no = 1;
			break;
		}
		n = n / 2;
	}

	fprintf(stdout, "%d", 1 - no);

	return 0;
}