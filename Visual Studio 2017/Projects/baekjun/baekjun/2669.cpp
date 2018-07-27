#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int map[120][120];

int main(void) {
	int a, b, c, d;
	for (int i = 1;i <= 4;i++) {
		fscanf(stdin, "%d %d %d %d", &a, &b, &c, &d);
		if (a > c) {
			int t = a;
			a = b;
			b = t;
		}
		if (b > d) {
			int t = b;
			b = d;
			d = t;
		}

		for (int j = a;j <= c - 1;j++) {
			for (int k = b;k <= d - 1;k++) {
				map[j][k] = 1;
			}
		}
	}

	int cnt = 0;
	for (int i = 1;i <= 100;i++) {
		for (int j = 1;j <= 100;j++) {
			if (map[i][j] == 1) cnt++;
		}
	}

	fprintf(stdout, "%d", cnt);
	return 0;
}
