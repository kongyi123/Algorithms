#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n;
	int a, b, c;
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i++) {
		fscanf(stdin, "%d%d%d", &a, &b, &c);
		fprintf(stdout, "%d\n", 100*((c-1)%a+1) + ((c-1)/a+1));
	}
	return 0;
}
