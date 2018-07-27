#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int num[10000];

int main(void) {
	int n, b;
	fscanf(stdin, "%d %d", &n, &b);
	int cnt = 0;
	while (n / b) {
		num[++cnt] = n % b;
		n = n / b;
	}
	num[++cnt] = n;
	
	for (int i = cnt;i >= 1;i--) {
		if (num[i] >= 10) {
			fprintf(stdout, "%c", num[i] + 'A' - 10);
		}
		else fprintf(stdout, "%d", num[i]);
	}

	return 0;
}