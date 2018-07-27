// 이분검색 기본형
// 이분검색 변형

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int data[110000];

int n;
int t;

void swap(int &a, int &b) {
	int t;
	t = a;
	a = b;
	b = t;
}
/* 기본형
int search(int s, int e, int val) {
	s = 1, e = n;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (val == data[mid]) return mid;
		else if (val < data[mid]) e = mid - 1;
		else s = mid + 1;
	}

	return -1;
}*/

int val;

int search(int s, int e) {
	if (s <= e) {
		int mid = (s + e) / 2;
		if (val == data[mid]) return mid;
		else if (val < data[mid]) return search(s, mid - 1);
		else return search(mid + 1, e);
	}

	return -1;
}

int main(void) {
	int m;
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
			if (k + 1 <= n - i && data[k] < data[k + 1]) k++;
			if (data[j] < data[k]) {
				swap(data[j], data[k]);
				j = k;
			}
			else break;
		}
	}

	fscanf(stdin, "%d", &m);
	for (int i = 1;i <= m;i++) {

		fscanf(stdin, "%d", &t);
	
		val = t;
		int ans = search(1, n);
/*		int s = 1, e = n;
		int ans = 0;
		while (s <= e) {
			int mid = (s + e) / 2;
			if (t == data[mid]) {
				ans = mid;
				break;
			}
			else if (t < data[mid]) {
				e = mid - 1;
			}
			else {
//				if (s == e) {
//					ans = s;
//					break;
//				}
				s = mid + 1;
			}
		}
		*/
		if (ans != -1) fprintf(stdout, "1\n");
		else fprintf(stdout, "0\n");
	}

	return 0;
}
