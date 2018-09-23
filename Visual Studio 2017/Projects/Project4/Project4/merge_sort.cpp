#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#define REPEAT 10

#define MAX_SIZE 1000000

using namespace std;

int sorted[MAX_SIZE];
int heap[MAX_SIZE+1];

void heap_sort(int arr[], int n) {
	for (int i = 1; i <= n; i++) {
		heap[i] = arr[i-1];
		for (int j = i; j > 1; j /= 2) {
			if (heap[j] > heap[j / 2]) {
				swap(heap[j], heap[j / 2]);
			}
		}
	}

	for (int i = 1;i <= n;i ++) {
		swap(heap[1], heap[n - i + 1]);
		for (int j = 1; ; ) {
			int k = j * 2;
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


void merge(int list[], int left, int mid, int right) {
	int i, j, k, l;
	i = left;
	j = mid+1;
	k = left;

	while(i <= mid && j <= right) {
		if(list[i] <= list[j]) sorted[k++] = list[i++];
		else sorted[k++] = list[j++];
	}

	for(l = j; l <= right;l ++) sorted[k++] = list[l];
	for(l = i; l <= mid;l ++) sorted[k++] = list[l];
	for(l = left;l <= right;l ++) list[l] = sorted[l];
}

void merge_sort(int list[], int left, int right){
	int mid;
	if(left < right) {
		mid = (left + right) / 2; 
		merge_sort(list, left, mid); 
		merge_sort(list, mid+1, right); 
		merge(list, left, mid, right); 
	}
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


		merge_sort(dat, 0, n - 1);
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
		for (int i = 0;i < n;i++) {
			//scanf("%d", &dat[i]);
			dat[i] = rand() % 1000000000 + 1;
		}
		heap_sort(dat, n);
	}
	end = clock();
	printf("array heap sort time = %d\n", end - begin);

//	for(i = 0; i < n;i ++) {
//		printf("%d\n", dat[i]);
//	}

}
