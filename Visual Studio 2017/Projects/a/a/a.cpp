#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int data[1100][1100];
int dy[1100][1100];

int min(int a, int b) {
	if (a > b) return b;
	return a;
}

int main(void) {
	int n, m;
	fscanf(stdin, "%d %d", &n, &m);

	int max = 0;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			dy[i][j] = 0;
			fscanf(stdin, "%d", &data[i][j]);
			if (data[i][j] == 0) {
				int t = 2000000000;
				t = min(t, dy[i - 1][j]);
				t = min(t, dy[i][j - 1]);
				t = min(t, dy[i - 1][j - 1]);
				if (t == 2000000000) t = 0;
				dy[i][j] = t + 1;
				if (max < dy[i][j]) max = dy[i][j];
			}
		}
	}
	fprintf(stdout, "%d\n", max);

	return 0;
}