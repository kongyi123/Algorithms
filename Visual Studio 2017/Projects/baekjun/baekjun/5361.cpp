#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

double val[5] = { 350.34, 230.90, 190.55, 125.30, 180.90 };

int main(void) {
	int n, k;
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i++) {
		double sum = 0;
		for (int j = 0;j <= 4;j++) {
			fscanf(stdin, "%d", &k);
			sum = sum + val[j] * k;
		}

		fprintf(stdout, "$%.2f\n", sum);
	}

	

	
	return 0;
}