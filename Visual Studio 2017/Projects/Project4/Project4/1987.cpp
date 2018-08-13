#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int R, C;
char data[22][22];

int max = 1;
int visited[22][22];

int dir[4][2] = { {0 ,1}, {1, 0} ,{0, -1}, {-1, 0} };
int check[30];

void back(int x, int y, int dist) {
	if (max < dist) {
		max = dist;
	}

	for (int i = 0;i <= 3;i++) {
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];
		if (nx <= 0 || nx > C) continue;
		if (ny <= 0 || ny > R) continue;
		int ch = data[ny][nx] - 'A';
		if (visited[ny][nx] == 0 && check[ch] == 0) {
			check[ch] = 1;
			visited[ny][nx] = 1;
			back(nx, ny, dist + 1);
			visited[ny][nx] = 0;
			check[ch] = 0;
		}
	}
}

int main(void) {
	scanf("%d %d", &R, &C);
	for (int i = 1;i <= R;i++) {
		scanf("%s", &data[i][1]);
	}
	check[data[1][1] - 'A'] = 1;
	visited[1][1] = 1;
	back(1, 1, 1);
	printf("%d", max);
	return 0;
}