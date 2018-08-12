#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int R, C;
char map[60][60];
int sy, sx;
int queue[80000][4];
int water_visited[60][60], visited[60][60];
// queue[][0] : 1=>water 2=>고슴도치
// queue[][1] : x
// queue[][2] : y
// queue[][3] : dist

int process() {
	int head, tail;
	head = 0, tail = 1;

	for (int i = 1;i <= R;i++) {
		for (int j = 1;j <= C;j++) {
			if (map[i][j] == 'S') {
				sy = i;
				sx = j;
			}
			else if (map[i][j] == '*') {
				queue[tail][0] = 1;
				queue[tail][1] = j; // x
				queue[tail][2] = i; // y
				water_visited[i][j] = 1;
				tail++;
			}
		}
	}

	// 고슴도치 시작위치
	queue[tail][0] = 2;
	queue[tail][1] = sx;
	queue[tail][2] = sy;
	queue[tail][3] = 0;
	tail++;
	visited[sy][sx] = 1;

	int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
	while (head < tail) {
		if (queue[head][0] == 1) { // 물인 경우
			int cx = queue[head][1];
			int cy = queue[head][2];
			for (int i = 0;i <= 3;i++) {
				int nx = cx + dir[i][0];
				int ny = cy + dir[i][1];
				if (nx <= 0 || nx > C) continue;
				if (ny <= 0 || ny > R) continue;
				if (water_visited[ny][nx] == 0 && map[ny][nx] != 'D' && map[ny][nx] != 'X') {
					water_visited[ny][nx] = 1;
					queue[tail][0] = 1;
					queue[tail][1] = nx;
					queue[tail][2] = ny;
					tail++;
				}
			}
		}
		else { // 고슴도치인 경우
			int cx = queue[head][1];
			int cy = queue[head][2];
			for (int i = 0;i <= 3;i++) {
				int nx = cx + dir[i][0];
				int ny = cy + dir[i][1];
				if (nx <= 0 || nx > C) continue;
				if (ny <= 0 || ny > R) continue;
				if (water_visited[ny][nx] == 0 && visited[ny][nx] == 0 && map[ny][nx] != 'X') {
					if (map[ny][nx] == 'D') {
						return queue[head][3]+1;
					}
					visited[ny][nx] = 1;
					queue[tail][0] = 2;
					queue[tail][1] = nx;
					queue[tail][2] = ny;
					queue[tail][3] = queue[head][3] + 1;
					tail++;
				}
			}

		}
		head++;
	}

	return -1;
}

int main(void) {
	scanf("%d %d", &R, &C);
	for (int i = 1;i <= R;i++) {
		scanf("%s", &map[i][1]);
	}

	int ans = process();
	if (ans == -1) printf("KAKTUS");
	else printf("%d", ans);
	return 0;
}