// 10 - 14 Æ©´×

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>

int temp[100];

void mergesort(int arr[], int s, int e) {
	if (s >= e) return;
	int mid = (s + e) / 2;

	mergesort(arr, s, mid);
	mergesort(arr, mid + 1, e);

	int p = s, q = mid + 1;
	int t = s;
	while (p <= mid && q <= e) temp[t++] = arr[p] < arr[q] ? arr[p++] : arr[q++];
	while (p <= mid) temp[t++] = arr[p++];
	while (q <= e) temp[t++] = arr[q++];

	for (int i = s;i <= e;i++)
		arr[i] = temp[i];
}
/*
int sorted[MAX_SIZE + 1];

void merge_sort(int arr[], int size) {
	if (size == 1) return;

	int mid = size / 2;
	merge_sort(arr, mid);
	merge_sort(arr + mid, size - mid);

	int i = 0, j = mid, k = 0;
	while (i < mid && j < size)
		sorted[k++] = arr[i] <= arr[j] ? arr[i++] : arr[j++];

	while (i < mid) sorted[k++] = arr[i++];
	while (j < size) sorted[k++] = arr[j++];

	for (i = 0;i < size;i++) arr[i] = sorted[i];
}
*/


int n;
int dat[100];

int main(void) {
	scanf("%d", &n);
	for (int i = 1;i <= n;i++) {
		scanf("%d", &dat[i]);
	}
	mergesort(dat, 1, n);

	for (int i = 1;i <= n;i++)
		printf("%3d", dat[i]);

	_getch();
	return 0;
}