#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int data[100010];

void swap(int& a, int& b) {
	int t = a;
	a = b;
	b = t;
}

void quicksort(int s, int e, int data[]) {
	int pivotI = s + 1;
	int pivotJ = e;
	if (s < e) {
		while (1) {
			while (data[pivotI] <= data[s] && pivotI <= e) pivotI++;
			while (data[pivotJ] > data[s]) pivotJ--;
			if (pivotI < pivotJ) swap(data[pivotI], data[pivotJ]);
			else break;
		}
		swap(data[pivotJ], data[s]);
		quicksort(s, pivotJ - 1, data);
		quicksort(pivotJ + 1, e, data);
	}
}

int main(void) {
	int n, m;
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i++) {
		fscanf(stdin, "%d", &data[i]);
	}

	quicksort(1, n, data);

	fscanf(stdin, "%d", &m);
	for (int i = 1;i <= m;i++) {
		int t;
		fscanf(stdin, "%d", &t);
		int result = 0;
		int s = 1, e = n;
		while (s <= e) {
			int mid = (s + e) / 2;
			if (data[mid] == t) {
				result = 1;
				break;
			}
			else if (data[mid] < t) {
				s = mid + 1;
			}
			else {
				e = mid - 1;
			}
		}

		fprintf(stdout, "%d\n", result);
	}


	return 0;
}