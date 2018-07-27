#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n;
	fscanf(stdin, "%d", &n);
	int i = 1;
	int sum = 0;
	int cnt = 0;
	while (1) {
		cnt++;
		sum = sum + i;
		if (sum == n) break;
		i++;
		if (sum + i > n) i = 1;
	}

	fprintf(stdout, "%d", cnt);
	return 0;
}