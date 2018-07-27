#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
	int n, m;
	fscanf(stdin, "%d %d", &n, &m);
	int t = 1;
	for (int i = 1;i <= m;i++) {
		t = t * n;
		n--;
	}

	for (int i = 1;i <= m;i++) {
		t = t / i;
	}


	fprintf(stdout, "%d", t);
	return 0;
}