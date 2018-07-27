// 수열의 합

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int n;
int data[110000];
int sum[110000];

int main(void) {
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i++) {
		fscanf(stdin, "%d", &data[i]);
		sum[i] += sum[i - 1] + data[i];
	}

	int max = -1;
	for (int i = 1;i <= n;i++) {
		for (int j = i;j <= n;j++) {
			if (max < sum[j] - sum[i - 1]) {
				max = sum[j] - sum[i - 1];
			}
		}
	}

	fprintf(stdout, "%d", max);
	return 0;
}