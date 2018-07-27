#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
	int t;
	fscanf(stdin, "%d", &t);
	for (int i = 1;i <= t;i++) {
		int n, m;
		fscanf(stdin, "%d %d", &n, &m);
		int cnt = 0;
		for (int a = 1;a < n;a++) {
			for (int b = a+1;b < n;b++) {
				if ((a*a + b*b + m) % (a*b) == 0) {
					cnt++;
				}
			}
		}

		fprintf(stdout, "%d\n", cnt);
	}
	return 0;
}