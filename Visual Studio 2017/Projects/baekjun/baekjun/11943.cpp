#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>



int main(void) {
	int a, b, c, d;
	fscanf(stdin, "%d %d", &a, &b);
	fscanf(stdin, "%d %d", &c, &d);
	if (a + d > b + c) {
		fprintf(stdout, "%d", b + c);
	}
	else {
		fprintf(stdout, "%d", a + d);
	}
	return 0;
}