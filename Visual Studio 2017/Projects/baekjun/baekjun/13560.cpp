#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
//#include <conio.h>

int data[10010];
int table[10010];

void swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}

int abs(int a) {
	if (a < 0) return -a;
	return a;
}

int main(void) {
	int n;
	fscanf(stdin, "%d", &n);
	int sum = 0;
	for (int i = 1;i <= n;i++) {
		fscanf(stdin, "%d", &data[i]);
		sum += data[i];
		for (int j = i;j > 1;j = j / 2) {
			if (data[j] > data[j / 2]) swap(data[j], data[j / 2]);		// 제일 큰놈을 root로
		}
	}

	for (int i = 1;i <= n;i++) {
		swap(data[1], data[n - i + 1]);
		for (int j = 1;;) {
			int k = j * 2;
			if (k > n - i) break;
			if (k + 1 <= n - i && data[k] < data[k + 1]) k++;
			if (data[k] > data[j]) {
				swap(data[k], data[j]);
				j = k;
			}
			else break;
		}
	}

	int flag = 0;

	for (int i = n - 1;i >= 0;i--) {
		table[i] = i-data[i + 1];
	}

	int er = 1;

	if (sum != n*(n - 1) / 2) er = -1;
	for (int i = n-1;i >= 0;i--) {
		if (table[i] > 0) {
			if (i - 2 >= 0) {
				for (int j = i - 2;j >= 0 && table[i] > 0;) {
					if (table[j] < 0) {
						table[j]++;
						table[i]--;
					}
					else j--;
				}
			}

			if (table[i] != 0) {
				er = -1;break;
			}
		}
	}

	fprintf(stdout, "%d", er);
	//_getch();								// 디버깅용
	return 0;
}