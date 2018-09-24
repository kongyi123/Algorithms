#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#define INF 0x7fffffff
#define dbg //printf

using namespace std;

int T, N, M;
int dat[4010][4];
int C[16000010], size_;


int upper_bound(int s, int e, int val) {
	int mid;
	while (s < e) {
		mid = (s + e) / 2;
		if (C[mid] <= val) s = mid + 1;
		else e = mid;

	}

	if (!(val < C[s])) return s + 1;
	return s;
}

int lower_bound(int s, int e, int val) {
	int mid;
	while (s < e) {
		mid = (s + e) / 2;
		if (C[mid] < val) s = mid + 1;
		else e = mid;
	}

	if (!(val <= C[s])) return s + 1;
	return s;
}

int sorted[16000010];


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



long long process() {
	long long cnt = 0;
	int cur;
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			size_++;
			C[size_] = dat[i][0] + dat[j][1];
		}
	}
	merge_sort(&C[1], N*N);

	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			int a = upper_bound(1, size_, 0 - (dat[i][2] + dat[j][3]));
			int b = lower_bound(1, size_, 0 - (dat[i][2] + dat[j][3]));
			cnt += (a - b);
		}
	}


	return cnt;
}

int main(void) {
	scanf("%d", &N);
	for (int i = 1;i <= N;i++) {
		for (int j = 0;j <= 3;j++) {
			scanf("%d", &dat[i][j]);
		}
	}


	printf("%lld", process());
	return 0;
}