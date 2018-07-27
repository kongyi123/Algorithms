#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 52

int a[MAX];
int b[MAX];

void swap(int &a, int &b) {
	int t;
	t = a;
	a = b;
	b = t;
}

void quicksort(int s, int e, int arr[]) {
	int pivotI = s + 1;
	int pivotJ = e;

	if (s < e) {
		while (1) {
			while (arr[pivotI] <= arr[s] && pivotI <= e) pivotI ++;
			while (arr[pivotJ] > arr[s]) pivotJ--;
			if (pivotI < pivotJ) swap(arr[pivotI], arr[pivotJ]);
			else break;
		}
		swap(arr[pivotJ], arr[s]);
		quicksort(pivotJ + 1, e, arr);
		quicksort(s, pivotJ - 1, arr);
	}
}

int main(void) {
	int i;
	int n;
	fscanf(stdin, "%d", &n);
	for (i = 1;i <= n;i++) {
		fscanf(stdin, "%d", &a[i]);
	}
	quicksort(1, n, a);

	for (i = 1;i <= n;i++) {
		fscanf(stdin, "%d", &b[i]);
	}
	quicksort(1, n, b);

	int sum = 0;
	for (i = 1;i <= n;i++) {
		sum = sum + (a[i] * b[n - i + 1]);
	}

	fprintf(stdout, "%d", sum);
	return 0;

}
