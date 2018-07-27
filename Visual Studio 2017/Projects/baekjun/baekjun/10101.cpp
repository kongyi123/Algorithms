#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int a, b, c;
	fscanf(stdin, "%d%d%d", &a, &b, &c);
	if (a == 60 && b == 60 && c == 60) fprintf(stdout, "Equilateral");
	else if (a + b + c == 180 && (a == b || b == c || c == a)) fprintf(stdout, "Isosceles");
	else if (a + b + c == 180 && a != b && b != c && c != a) fprintf(stdout, "Scalene");
	else {
		fprintf(stdout, "Error");
	}
	return 0;
}