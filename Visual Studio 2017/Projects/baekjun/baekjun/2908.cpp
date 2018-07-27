#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int reverse(int val) {
	int a, b, c;
	a = val % 10;
	b = (val / 10) % 10;
	c = (val / 100) % 10;

	return a * 100 + b * 10 + c;
}

int main(void) {
	int a, b;
	int ra, rb;
	fscanf(stdin, "%d%d", &a, &b);
	ra = reverse(a);
	rb = reverse(b);

	if (ra > rb) fprintf(stdout, "%d", ra);
	else fprintf(stdout, "%d", rb);
	return 0;
}
