#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n;
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i ++) {
		int a, b;
		fscanf(stdin, "%d %d", &a, &b);
		fprintf(stdout, "You get %d piece(s) and your dad gets %d piece(s).\n", a/b, a%b);
	}
	return 0;
}