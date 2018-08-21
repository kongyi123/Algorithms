#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int data[510000];
int n, m;

void swap(int &a, int &b) {
	int t;
	t = a;
	a = b;
	b = t;
}

int lower_bound(int val) {
	int s, e;
	int mid;
	s = 1, e = n;
	while (s < e) {
		mid = (s + e) / 2;
		if (data[mid] >= val) e = mid;
		else s = mid + 1;
	}
	
	if (data[s] < val) s++;
	return s;
}

int upper_bound(int val) {
	int s, e;
	int mid;
	s = 1, e = n;
	while (s < e) {
		mid = (s + e) / 2;
		if (data[mid] <= val) s = mid + 1;
		else e = mid;
	}

	if (data[s] <= val) s++;
	return s;
}

int main(void) {
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i++) {
		fscanf(stdin, "%d", &data[i]);
		for (int j = i;j > 1;j /= 2) {
			if (data[j] > data[j / 2]) swap(data[j], data[j / 2]);
		}
	}

	for (int i = 1;i <= n;i++) {
		swap(data[1], data[n - i + 1]);
		for (int j = 1;;) {
			int k = j * 2;
			if (k > n - i) break;
			if (k + 1 <= n - i && data[k] < data[k + 1]) k++;
			if (data[j] < data[k]) {
				swap(data[j], data[k]);
				j = k;
			}
			else break;
		}
	}
	
	int a;
	fscanf(stdin, "%d", &m);
	for (int i = 1;i <= m;i++) {
		fscanf(stdin, "%d", &a);

		fprintf(stdout, "%d ", upper_bound(a) - lower_bound(a));
	}
	return 0;
}