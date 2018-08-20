#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int data[30][30];
bool check[30][30];
int dir[4][2] = { { 0, 1 },{ 1, 0 },{ 0, -1 },{ -1, 0 } };

int ans[900];
int cnt;

int back(int y, int x) {

	int cnt = 0;
	for (int i = 0;i <= 3;i++) {
		int ny = y + dir[i][0];
		int nx = x + dir[i][1];
		if (check[ny][nx] == 0 && data[ny][nx] == 1) {
			check[ny][nx] = 1;
			cnt += back(ny, nx) + 1;
		}
	}

	return cnt;
}

void swap(int &a, int &b) {
	int t;
	t = a;
	a = b;
	b = t;
}

int main(void) {
	int n;
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			fscanf(stdin, "%1d", &data[i][j]);
		}
	}

	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			if (check[i][j] == 0 && data[i][j] == 1) {
				check[i][j] = 1;
				ans[++cnt] = back(i, j) + 1;
			}
		}
	}

	for (int i = 1;i <= cnt;i++) {
		for (int j = i + 1;j <= cnt;j++) {
			if (ans[i] > ans[j]) swap(ans[i], ans[j]);
		}
	}

	fprintf(stdout, "%d\n", cnt);
	for (int i = 1;i <= cnt;i++) {
		fprintf(stdout, "%d\n", ans[i]);
	}

	return 0;
}