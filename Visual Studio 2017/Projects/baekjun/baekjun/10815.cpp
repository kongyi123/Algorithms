#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int data[510000];
int n;

void swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}

int search(int s, int e, int val) {
	
	while (s <= e) {
		int mid = (s + e) / 2;
		if (val == data[mid]) return mid;
		else if (val < data[mid]) e = mid - 1;
		else s = mid + 1;
	}

	return -1;
}

int main(void) {
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i++) {
		fscanf(stdin, "%d", &data[i]);
		for (int j = i;j > 1;j = j / 2) {
			if (data[j] > data[j / 2]) swap(data[j], data[j / 2]);
		}
	}

	for (int i = 1;i <= n;i++) {
		swap(data[1], data[n - i + 1]);
		for (int j = 1;;) {
			int k = j * 2;
			if (k > n - i) break;
			if (k + 1 <= n - i && data[k] < data[k+1]) k++;
			if (data[j] < data[k]) {
				swap(data[j], data[k]);
				j = k;
			}
			else break;
		}
	}

	int m;
	fscanf(stdin, "%d", &m);
	for (int i = 1;i <= m;i++) {
		int a;
		fscanf(stdin, "%d", &a);
		if (search(1, n, a) != -1) fprintf(stdout, "1 ");
		else fprintf(stdout, "0 ");
	}
	return 0;
}