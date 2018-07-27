#include <stdio.h>

int main(void) {
	int k;
	int a, b;
	fscanf(stdin, "%d", &k);
	a = 1;
	b = 0;
	int a2, b2;
	for (int i = 1;i <= k;i ++) {
		b2 = b + a;
		a2 = b;

		a = a2;
		b = b2;
	}

	fprintf(stdout, "%d %d", a, b);
	return 0;
}