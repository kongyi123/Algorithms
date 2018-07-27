#include <stdio.h>

int main(void) {
	int n;
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= 9;i++) {
		fprintf(stdout, "%d * %d = %d\n", n, i, n*i);
	}
}