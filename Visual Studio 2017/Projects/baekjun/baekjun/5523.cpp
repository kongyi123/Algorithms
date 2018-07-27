#include <stdio.h>

int main(void) {
	int n;
	fscanf(stdin, "%d", &n);
	int cnta, cntb;
	cnta = cntb = 0;
	for (int i = 1;i <= n;i++) {
		int a, b;
		fscanf(stdin, "%d %d", &a, &b);
		if (a > b) cnta++;
		if (a < b) cntb++;
	}
	fprintf(stdout, "%d %d", cnta, cntb);
	return 0;
}