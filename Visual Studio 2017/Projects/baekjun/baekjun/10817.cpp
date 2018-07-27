#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int a, b, c;
	fscanf(stdin, "%d %d %d", &a, &b, &c);
	if (a >= b && b >= c) fprintf(stdout, "%d", b);
	else if (a >= c && c >= b) fprintf(stdout, "%d", c);
	else if (b >= a && a >= c) fprintf(stdout, "%d", a);
	else if (b >= c && c >= a) fprintf(stdout, "%d", c);
	else if (c >= a && a >= b) fprintf(stdout, "%d", a);
	else if (c >= b && b >= a) fprintf(stdout, "%d", b);
	return 0;
}
