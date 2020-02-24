#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[110];

int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}

	int min = 2000000000;
	for (int i = 1; i <= 100; i++) { // target
		int sum = 0;
		for (int j = 1;j <= n;j ++) { // source
			sum += ((i - arr[j]) * (i - arr[j]));
		}
		if (min > sum)
			min = sum;
	}

	printf("%d", min);

	return 0;
}