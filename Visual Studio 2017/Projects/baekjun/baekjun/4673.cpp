#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int check[10001];

int r(int val) {
	int a = val;
	while (val > 0) {
		a = a + val % 10;
		val = val / 10;
	}
	
	return a;
}

int main(void) {
	for (int i = 1;i <= 10000;i++) {
		if (r(i) <= 10000) {
			check[r(i)] = 1;
		}
	}

	for (int i = 1;i <= 10000;i++) {
		if (check[i] == 0) fprintf(stdout, "%d\n", i);
	}
	return 0;
}
