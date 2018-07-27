// 13Ка

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int data[11000];
int n;
int m;

int eval(int limit) {
	int sum = 0;
	int max = 0;
	for (int i = 1;i <= n;i++) {
		if (data[i] > limit) {
			sum += limit;
			if (max < limit)
				max = limit;
		}
		else {
			sum += data[i];
			if (max < data[i])
				max = data[i];
		}
	}

	if (sum > m) return -1;
	return max;
}

int main(void) {
	fscanf(stdin, "%d", &n);
	int sum = 0;
	int ans = 0, max = 0;
	for (int i = 1;i <= n;i++) {
		fscanf(stdin, "%d", &data[i]);
		if (max < data[i]) max = data[i];
		sum += data[i];
	}
	fscanf(stdin, "%d", &m);

	if (sum <= m) ans = max;
	else {
		
		int s = 1, e = 100000;
		int result;
		while (s <= e) {
			int mid = (s + e) / 2;
			if ((result = eval(mid)) != -1) {
				if (ans < result) ans = result;
				s = mid + 1;
			}
			else {
				e = mid - 1;
			}
		}
	}

	fprintf(stdout, "%d", ans);
	return 0;
}