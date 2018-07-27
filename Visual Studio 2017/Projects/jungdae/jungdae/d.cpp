#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

double heap[9];
int n;

void swap(double &a, double &b) {
	double t;
	t = a;
	a = b;
	b = t;
}


int main(void) {
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= 8;i++) {
		heap[i] = 2000000000;
	}

	for (int i = 1;i <= n;i++) {
		double m;
		fscanf(stdin, "%lf", &m);
		for (int j = 1;j <= 8;j++) {
			if (m < heap[j]) {
				swap(heap[j], m);
			}
		}

	}

	for (int i = 1;i <= 7;i++) {
		fprintf(stdout, "%.3lf\n", heap[i]);
	}

	return 0;
}