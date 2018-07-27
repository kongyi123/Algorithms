#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int checkx[600];
int checky[600];

int x[110], y[110];
int xcnt, ycnt;

int data[600][4];

void swap(int &a, int &b) {
	int  t;
	t = a;
	a = b;
	b = t;
}

int main(void) {
	int n;
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i++) {
		int a, b, c, d;
		fscanf(stdin, "%d %d %d %d", &a, &b, &c, &d);
		data[i][0] = a;
		data[i][1] = b;
		data[i][2] = c;
		data[i][3] = d;
		if (checkx[a] == 0) {
			checkx[a] = 1;
			xcnt++;
			x[xcnt] = a;
		}
		if (checky[b] == 0) {
			checky[b] = 1;
			ycnt++;
			y[ycnt] = b;
		}
		if (checkx[c] == 0) {
			checkx[c] = 1;
			xcnt++;
			x[xcnt] = c;
		}
		if (checky[d] == 0) {
			checky[d] = 1;
			ycnt++;
			y[ycnt] = d;
		}
	}

	for (int i = 1;i <= xcnt;i++) {
		for (int j = i + 1;j <= xcnt;j++) {
			if (x[i] > x[j]) swap(x[i], x[j]);
		}
	}

	for (int i = 1;i <= ycnt;i++) {
		for (int j = i + 1;j <= ycnt;j++) {
			if (y[i] > y[j]) swap(y[i], y[j]);
		}
	}

	int sum = 0;
	for (int i = 1;i < ycnt;i++) {
		for (int j = 1;j < xcnt;j++) {
			for (int k = 1;k <= n;k++) {
				if ( data[k][1] <= y[i] && y[i + 1] <= data[k][3]) {
					if (data[k][0] <= x[j] && x[j + 1] <= data[k][2]) {
						sum += (y[i + 1] - y[i])*(x[j + 1] - x[j]);
					}
				}
			}
		}
	}

	fprintf(stdout, "%d", sum);

	return 0;
}