#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int data[110000];

int main(void) {
	int n;
	int max = -2000000000;
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i++) {
		fscanf(stdin, "%d", &data[i]);
	}

	for (int i = 1;i <= n;i++) {
		for (int j = i;j <= n;j++) {
			int sum = 0;
			for (int k = i;k <= j;k++) {
				sum += data[k];
				if (max < sum) max = sum;
			}
		}
	}

	fprintf(stdout, "%d", max);

}