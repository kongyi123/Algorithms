// greedy

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int heap[20];
int n;

void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}


int main(void) {
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i++) {
		fscanf(stdin, "%d", &heap[i]);
		for (int j = i;j > 1;j = j >> 1) {
			if (heap[j] > heap[j >> 1]) swap(&heap[j], &heap[j >> 1]);
		}
	}

	for (int i = 1;i <= n;i++) {
		swap(&heap[1], &heap[n - i + 1]);
		for (int j = 1;;) {
			int k = j << 1;
			if (k > n - i) break;
			if (k + 1 <= n - i && heap[k] < heap[k + 1]) k++;
			if (heap[j] < heap[k]) {
				swap(&heap[j], &heap[k]);
				j = k;
			}
			else break;
		}
	}
	
	int sum = 0;
	if (n % 2 == 0) {
		for (int i = 1;i <= n/2;i++) {
			sum = sum - heap[i];
			if (i == n / 2) break;
			sum = sum - heap[i];
		}

		for (int i = n;i >= n/2+1;i--) {
			sum = sum + heap[i];
			if (i == n / 2 + 1) break;
			sum = sum + heap[i];
		}
	}
	else {
		for (int i = 1;i <= n / 2 - 1;i++) sum = sum - heap[i]*2;
		for (int i = n;i >= n / 2 + 2;i--) sum = sum + heap[i]*2;
		sum = sum - heap[n / 2] - heap[n / 2 + 1];
	
		int t = 0;
		for (int i = 1;i <= n / 2;i++) t = t - heap[i] * 2;
		for (int i = n;i >= n / 2 + 3;i--) t = t + heap[i] * 2;
		t = t + heap[n / 2 + 1] + heap[n / 2 + 2];
		
		if (sum < t) sum = t;
	}

	fprintf(stdout, "%d", sum);


	return 0;
}