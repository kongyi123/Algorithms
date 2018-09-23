#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#define INF 0x7fffffff
#define dbg //printf

using namespace std;

int T, N, M;
int dat[4010][4];
int C[16000010], size_;

int sorted[16000010];

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


inline void merge(int list[], int left, int mid, int right) {
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;

	while (i <= mid && j <= right) {
		if (list[i] <= list[j]) sorted[k++] = list[i++];
		else sorted[k++] = list[j++];
	}

	for (l = j; l <= right;l++) sorted[k++] = list[l];
	for (l = i; l <= mid;l++) sorted[k++] = list[l];
	for (l = left;l <= right;l++) list[l] = sorted[l];
}

inline void merge_sort(int list[], int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		merge_sort(list, left, mid);
		merge_sort(list, mid + 1, right);
		merge(list, left, mid, right);
	}
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
	merge_sort(&C[1], 0, N*N-1);

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