#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int table[1100000];

int main(void) {
	int n;
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i++) {
		table[i] = i;
	}

	int cnt = n;
	for (int i = 2;i<=cnt;i = i+2) {
		table[++cnt] = table[i];
	}

	fprintf(stdout, "%d", table[cnt]);

	return 0;
}