#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n;
	fscanf(stdin, "%d", &n);
	int a, b;
	int dap;
	int i;
	a = 1;
	b = 1;
	for (i = 1;;i ++) {
		if (a <= n && n <= b) {
			break;
		}

		a = a + i;
		b = b + (i + 1);
	}

	i++;
	dap = n - a + 1;
	if (i % 2 == 0) {
		fprintf(stdout, "%d/%d", (i - dap), dap);
	} else {
		fprintf(stdout, "%d/%d", dap, i-dap);
	}
	return 0;
}