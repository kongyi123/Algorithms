#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
	while (1) {
		int a, b, c;
		fscanf(stdin, "%d%d%d", &a, &b, &c);
		if (a == 0 && b == 0 && c == 0) break;

		if (b*b == a*c) fprintf(stdout, "GP %d\n", c*c/b);
		else fprintf(stdout, "AP %d\n", c * 2 - b);
	}
	return 0;
}