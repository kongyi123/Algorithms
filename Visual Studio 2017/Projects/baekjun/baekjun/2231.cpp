#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int creator(int val) {
	int t = val;
	while (val) {
		t = t + (val % 10);
		val = val / 10;
	}

	return t;
}

int main(void) {
	int n;
	fscanf(stdin, "%d", &n);
	int flag = 0;
	for (int i = 1;i <= n;i++) {
		if (creator(i) == n) {
			flag = i;
			break;
		}
	}

	fprintf(stdout, "%d", flag);
	return 0;
}