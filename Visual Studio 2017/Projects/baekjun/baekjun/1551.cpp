#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int data[50];

int main(void) {
	int n, k;
	char ch;
	fscanf(stdin, "%d %d", &n, &k);
	fscanf(stdin, "%d", &data[1]);
	for (int i = 2;i <= n;i++) {
		fscanf(stdin, "%c", &ch);
		if (ch != ',') continue;
		fscanf(stdin, "%d", &data[i]);
	}

	for (int i = 1;i <= k;i++) {
		for (int j = 1;j < n;j++) {
			data[j] = data[j + 1] - data[j];
		}
		n--;
	}

	for (int i = 1;i <= n;i++) {
		fprintf(stdout, "%d", data[i]);
		if (i == n) break;
		fprintf(stdout, ",");
	}
	return 0;
}