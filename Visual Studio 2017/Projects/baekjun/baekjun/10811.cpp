#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int num[200];

int main(void) {
	int n, m;
	fscanf(stdin, "%d %d", &n, &m);
	for (int i = 1;i <= n;i++) num[i] = i;
	for (int i = 1;i <= m;i++) {
		int a, b;
		fscanf(stdin, "%d %d", &a, &b);
		int mid = (a + b) / 2; 
		for (int j = a;j <= mid;j++) {
			int t = num[j];
			num[j] = num[b - j + a];
			num[b - j + a] = t;
		}
	}

	for (int i = 1;i <= n;i++) fprintf(stdout, "%d ", num[i]);

	return 0;
}