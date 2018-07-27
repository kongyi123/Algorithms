#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int cnt[110000];
int adjl[110000];

int main(void) {
	int n, m;
	fscanf(stdin, "%d %d", &n, &m);
	for (int i = 1;i <= m;i++) {
		int a, b;
		fscanf(stdin, "%d %d", &a, &b);
		if (a - b == 1) adjl[b] = 1;
		if (b - a == 1) adjl[a] = 1;
		if (a == 0 && b == n - 1) adjl[b] = 1;
		if (a == n - 1 && b == 0) adjl[a] = 1;

		cnt[a] ++;
		cnt[b] ++;
	}

	int count = 0;
	for (int i = 0;i < n;i++) {
		if (cnt[i] < 2) {
			if (i > 0 && adjl[i - 1] == 0) {
				adjl[i - 1] ++;
				cnt[i]++;
				cnt[i - 1]++;
				count++;
			}
			else if (i == 0 && adjl[n - 1] == 0) {
				adjl[n - 1] ++;
				cnt[i]++;
				cnt[n - 1] ++;
				count++;
			} else if (adjl[i] == 0) {
				adjl[i] ++;
				cnt[i + 1] ++;
				cnt[i] ++;
				count++;
			}

			i--;
			continue;
		}
	}

	fprintf(stdout, "%d", count);

	return 0;
}