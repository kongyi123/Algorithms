#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int n, k;
int data[11000];

int main(void) {
	fscanf(stdin, "%d %d", &k, &n);
	for (int i = 1;i <= k;i++) {
		fscanf(stdin, "%d", &data[i]);
	}

	long long s = 1;
	long long e = 2147483647;
	long long mid;
	int cnt;
	long long max = -1;
	while (s <= e) {
		mid = (s + e) / 2;
		
		cnt = 0;
		for (int i = 1;i <= k;i++) cnt = cnt + data[i] / mid;
		
		if (cnt >= n) {
			s = mid + 1;
			if (max < mid) max = mid;
		}
		else e = mid - 1;

	}

	fprintf(stdout, "%lld", max);
	return 0;
}