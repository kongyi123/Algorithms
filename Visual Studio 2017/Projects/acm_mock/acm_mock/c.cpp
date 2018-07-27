// 12ºÐ°É¸²

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
	int n, k, a;
	int min = 2000000000;
	fscanf(stdin, "%d %d %d", &n, &k, &a);
	for (int i = 1;i <= n;i++) {
		int t, s;
		fscanf(stdin, "%d %d", &t, &s);
		int sec = 0;
		int rest = k;
		while (rest > 0) {
			for (int i = 1;i <= t;i++) {
				rest -= a;
				sec = sec + 1;
				if (rest <= 0) break;
			}
			if (rest <= 0) break;
			sec = sec + s;
		}

		if (min > sec) min = sec;
	}

	fprintf(stdout, "%d", min);
	return 0;
}