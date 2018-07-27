#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int table[1100000];

void swap(int &a, int &b) {
	int t;
	t = a;
	a = b;
	b = t;
}

int main(void) {
	int n;
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i++) {
		int data;
		fscanf(stdin, "%d", &data);
		table[i] = data;
		for (int j = i;j > 1;j = j >> 1) {
			if (table[j] > table[j >> 1]) swap(table[j], table[j >> 1]);
		}

	}
	for (int i = 1;i <= n;i++) {
		swap(table[1], table[n - i + 1]);
		for (int j = 1;;) {
			int k = j * 2;
			if (k > n - i) break;
			if (k + 1 <= n - i && table[k + 1] > table[k]) k++;
			if (table[k] > table[j]) {
				swap(table[k], table[j]);
				j = k;
			}
			else break;
		}
	}

	for (int i = 1;i <= n;i++) {
		fprintf(stdout, "%d\n", table[i]);
	}
	return 0;
}