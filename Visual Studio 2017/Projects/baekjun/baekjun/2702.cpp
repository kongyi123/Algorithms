#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int g(int a, int b) {
	if (a % b == 0) return b;
	g(b, a%b);
}

int main(void) {
	int n;
	int a, b;
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i++) {
		fscanf(stdin, "%d %d", &a, &b);
		int t = g(a, b);
		fprintf(stdout, "%d %d\n", a*b/t, t);
	}
	return 0;
}