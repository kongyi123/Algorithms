// 11Ка

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int data[1100000];
int n, m;

int check(int h) {
	int rest = m;
	for (int i = 1;i <= n;i++) {
		if (data[i] > h) {
			rest = rest - (data[i]- h);
			if (rest <= 0) return 1;
		}
	}

	return 0;
}

int main(void) {
	fscanf(stdin, "%d %d", &n, &m);
	for (int i = 1;i <= n;i++) {
		fscanf(stdin, "%d", &data[i]);
	}

	int s, e;
	s = 1;
	e = 1000000000;
	int max = -1;

	while (s <= e) {
		int mid = (s + e) / 2;
		if (check(mid)) {
			if (max < mid) {
				max = mid;
			}
			s = mid + 1;
		}
		else e = mid - 1;
	}

	fprintf(stdout, "%d", max);
	return 0;
}