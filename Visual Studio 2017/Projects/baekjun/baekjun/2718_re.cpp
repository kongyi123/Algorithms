#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <memory.h>
#define MAX 10
#define INF 2000000000

int cache[500][20];

int min(int a, int b) {
	if (a > b) return b;
	return a;
}


int tsp(int x, int bitmask) {
	if (cache[x][bitmask] != -1) return cache[x][bitmask];
	if (x == 0) return 0;

	int cnt = 0;
	if (bitmask == 0) cnt = tsp(x - 1, 16);
	if (bitmask == 3) {
		cnt += tsp(x - 1, 12);
		cnt += tsp(x - 1, 16);
	}
	if (bitmask == 6) {
		cnt += tsp(x - 1, 9);
		cnt += tsp(x - 1, 16);
	}
	if (bitmask == 9) cnt += tsp(x - 1, 6);
	if (bitmask == 12) {
		cnt += tsp(x - 1, 3);
		cnt += tsp(x - 1, 16);
	}
	

	if (bitmask == 16) {
		cnt += tsp(x - 1, 0);
		cnt -= tsp(x - 1, 16);
		cnt += tsp(x, 3);
		cnt += tsp(x, 9);
		cnt += tsp(x, 12);
	}

	return cache[x][bitmask] = cnt;
}


int main(void) {
	memset(cache, -1, sizeof(cache));
	
	cache[1][0] = 1;
	cache[1][3] = 1;
	cache[1][12] = 1;
	cache[1][6] = 1;
	cache[1][16] = 1;

	int n;
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i++) {
		int m;
		fscanf(stdin, "%d", &m);
		int result = tsp(m, 16); // 역순이다. 순서?

		fprintf(stdout, "%d\n", result);
	}
	return 0;
}