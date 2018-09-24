// 머지소트, 내장 sort함수, 힙소트 성능비교

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#define REPEAT 10

#define MAX_SIZE 1000000

using namespace std;


int heap[MAX_SIZE + 1];

void heap_sort(int arr[], int n) {
	for (int i = 1; i <= n; i++) {
		heap[i] = arr[i-1];
		for (int j = i; j > 1; j = j >> 1) {
			if (heap[j] > heap[j >> 1]) {
				swap(heap[j], heap[j >> 1]);
			}
		}
	}

	for (int i = 1;i <= n;i ++) {
		swap(heap[1], heap[n - i + 1]);
		for (int j = 1; ; ) {
			int k = j << 1;
			if (k > n - i) break;
			if (k + 1 <= n - i && heap[k] < heap[k + 1]) k++;
			if (heap[j] < heap[k]) {
				swap(heap[j], heap[k]);
				j = k;
			}
			else break;
		}
	}
	
	for (int i = 0;i < n;i++) arr[i] = heap[i+1];
}


int sorted[MAX_SIZE + 1];

void merge_sort(int arr[], int size) {
	if (size == 1) return;

	int mid = size / 2;
	merge_sort(arr, mid);
	merge_sort(arr + mid, size - mid);

	int i = 0, j = mid, k = 0;
	while(i < mid && j < size)  
		sorted[k++] = arr[i] <= arr[j] ? arr[i++] : arr[j++];
	
	while (i < mid) sorted[k++] = arr[i++];
	while (j < size) sorted[k++] = arr[j++];

	for (i = 0;i < size;i++) arr[i] = sorted[i];
}

void main(){
	clock_t begin, end;
	int i;
	int n;
	int dat[MAX_SIZE];
	srand((unsigned int)time(NULL));

	n = 1000000;

	//freopen("input.txt", "r", stdin);
	//scanf("%d", &n);
	begin = clock();
	for (int k = 1;k <= REPEAT;k ++ ) {
		for (int i = 0;i < n;i++) {
			//scanf("%d", &dat[i]);
			dat[i] = rand() % 1000000000 + 1;
		}


		merge_sort(&dat[1], n);
	}
	end = clock();
	printf("merge sort time = %d\n", end - begin);
	
	begin = clock();
	for (int k = 1;k <= REPEAT;k++) {
		for (int i = 0;i < n;i++) {
			//scanf("%d", &dat[i]);
			dat[i] = rand() % 1000000000 + 1;
		}
		sort(dat, dat+n);
	}
	end = clock();
	printf("inner function sort time = %d\n", end - begin);

	begin = clock();
	for (int k = 1;k <= REPEAT;k++) {
		for (int i = 1;i <= n;i++) {
			//scanf("%d", &dat[i]);
			dat[i] = rand() % 1000000000 + 1;
		}
		heap_sort(dat, n);
	}
	end = clock();
	printf("array heap sort time = %d\n", end - begin);

}
