#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, m;
	int arr[200002];
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}


	int cnt = 0;
	double sum = 0;
	double max = 0;
	for (int i = 0; i < n; i++) {
		sum += (double)(arr[i]+1)/2;
		cnt++;

		if (cnt == m) {
			if (i - m >= 0)
				sum -= (double)(arr[i-m]+1)/2;
			if (max < sum)
				max = sum;
			cnt--;
		}
	}
	printf("%lf", max);
	return 0;
}