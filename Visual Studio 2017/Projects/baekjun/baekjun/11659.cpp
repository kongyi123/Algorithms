#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int data[110000];

int main(void) {
	int n, m;
	fscanf(stdin, "%d %d", &n, &m);
	for (int i = 1;i <= n;i++) {
		fscanf(stdin, "%d", &data[i]);
		data[i] = data[i] + data[i - 1];
	}

	for (int i = 1;i <= m;i++) {
		int a, b;
		fscanf(stdin, "%d %d", &a, &b);
		if (a > b) {
			int t = a;
			a = b;
			b = t;
		}
		fprintf(stdout, "%d\n", data[b] - data[a - 1]);
	}
	return 0;
}