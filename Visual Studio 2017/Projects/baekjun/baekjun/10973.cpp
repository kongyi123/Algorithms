#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int data[11000];
int check[11000];

int main(void) {
	int n;
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i++) {
		fscanf(stdin, "%d", &data[i]);
	}

	int p = 0;
	for (int i = n-1;i >= 1;i--) {
		if (data[i] > data[i + 1]) {
			p = i;
			break;
		}
	}

	if (p == 0) fprintf(stdout, "-1");
	else {
		for (int i = 1;i < p;i++) {
			check[data[i]] = 1;
			fprintf(stdout, "%d ", data[i]);
		}

		int t;
		for (int i = data[p] - 1;i >= 1;i--) {
			if (check[i] == 0) {
				t = i;
				break;
			}
		}
		data[p] = t; check[t] = 1;

		fprintf(stdout, "%d ", t);
		for (int i = n;i >= 1;i--) {
			if (check[i] == 0) fprintf(stdout, "%d ", i);
		}
	}
	return 0;
}