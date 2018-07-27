#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define MAX 2000000000;

int data[20][20];
int n;
int cache[20][70000];

int min(int a, int b) {
	if (a > b) return b;
	return a;
}

int tsp(int cur, int bitmask) {
	if (bitmask == (1 << n) - 1) return data[cur][1];

	if (cache[cur][bitmask] != 0) return cache[cur][bitmask];

	int ret = MAX;
	for (int i = 1;i <= n;i++) {
		if ((bitmask & (1 << (i - 1))) != 0) continue;
		if (data[cur][i] == 0) continue;
		ret = min(ret, tsp(i, (bitmask | (1 << (i - 1)))) + data[cur][i]);
	}

	return cache[cur][bitmask] = ret;
}

int main(void) {
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			fscanf(stdin, "%d", &data[i][j]);
		}
	}

	fprintf(stdout, "%d", tsp(1, 1));
}