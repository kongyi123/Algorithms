// 23분

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define MID 10000000

int data[510000];
int n, m;

void swap(int &a, int &b) {
	int t;
	t = a;
	a = b;
	b = t;
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

	for (int i = 1;i <= n;i++) fprintf(stdout, "%d ", data[i]);
	fprintf(stdout, "\n");

	int lower_bound;
	int upper_bound;

	fscanf(stdin, "%d", &m);
	for (int i = 1;i <= m;i++) {
		int a;
		fscanf(stdin, "%d", &a);

		int s = 1, e = n;
		while (s < e) {
			int mid = (s + e) / 2;
			if (data[mid] == a) {
				s = mid + 1;
			} 
			else if (data[mid] < a) {
				s = mid + 1;
			}
			else if (data[mid] > a) {
				e = mid;
			}
		}
		lower_bound = e;
		
/*
		s = 1, e = n;
		while (s <= e) {
			int mid = (s + e + 1) / 2;
			if (data[mid] < a) {
				s = mid;
				if (s == e) {
					upper_bound = mid;	// 오른 부분만 봤을 때 내가 있을 수 있는 최초 자리
					break;
				}
			}
			else if (data[mid] >= a) {
				e = mid - 1;
			}
		}

		*/
		fprintf(stdout, "%d ", lower_bound);
		//fprintf(stdout, "%d\n", upper_bound);
	}
	return 0;
}