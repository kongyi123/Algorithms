#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define MAX 10
#define INF 2000000000

int cache[20][20];

int min(int a, int b) {
	if (a > b) return b;
	return a;
}


int tsp(int x, int bitmask_x, int bitmask_xp1) {
	if (bitmask_x == (1 << x) - 1) { // ÇöÀç ±îÁö ²Ë Ã¡À» ¶§


		tsp(x + 1, bitmask_xp1, 0); // ´ÙÀ½ Ä­À¸·Î ¤¡¤¡
	}
	
	int ret = INF;

	for (int i = 0;i <= 3;i++) {
		if (bitmask_x & (1 << i) == 0) {			
			// -
			//ret = min(ret, tsp(x, bitmask_x | (1 << i), bitmask_xp1 | (1 << i)) + 1);
			tsp(x, bitmask_x | (1 << i), bitmask_xp1 | (1 << i));

			// |
			//ret = min(ret, tsp(x, bitmask_x | ((1 << i) + (1 << (i+1))), bitmask_xp1) + 1);	
		}
	}


	return cache[x][bitmask_x] = ret;
}


int main(void) {
	
	int result = tsp(1, 0, 0);
	fprintf(stdout, "%d", result);
	return 0;
}