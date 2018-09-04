#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;
int map[5][1010];
int dy[1010][16][16];

int getbit(int x) {
	int bitmask = 0;
	for (int i = 1;i <= 4;i++) {
		bitmask |= (map[i][x] * (1 << (i-1)));
	}
	return bitmask;
}

int back(int x, int i_1, int i) {
	if (dy[x][i_1][i] != 0) return dy[x][i_1][i];

	int cnt = 0;
	// 2 x 1
	for (int y = 1;y <= 3;y ++) {
		if (map[y][x] == 1 && map[y+1][x] == 1) {
			map[y][x] = map[y + 1][x] = 0;
			int a = getbit(x - 1);
			int b = getbit(x);
			cnt += back(x, a, b);
			map[y][x] = map[y + 1][x] = 1;
		}
	}

	if (i == 0) {
		int a = getbit(x - 2);
		return back(x - 1, a, i_1);
	}

	// 1 x 2
	for (int y = 1;y <= 4;y++) {
		if (map[y][x] == 1 && map[y][x - 1] == 1) {
			map[y][x] = map[y][x - 1] = 0;
			int a = getbit(x - 1);
			int b = getbit(x);
			cnt += back(x, a, b);
			map[y][x] = map[y][x - 1] = 1;
		}
	}

	dy[x][i_1][i] = cnt;

	return cnt;
}

int main(void) {
	dy[0][0][0] = 1;
	

	scanf("%d", &N);
	for (int i = 1;i <= N;i++) {
		map[1][i] = map[2][i] = map[3][i] = map[4][i] = 1;
	}
	printf("%d", back(N, 15, 0));

	return 0;
}