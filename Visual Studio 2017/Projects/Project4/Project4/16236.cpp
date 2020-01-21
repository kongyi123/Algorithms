#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;

int data[30][30];
int check[30][30];
int sy, sx;

int queue[100000][3];
// [0] : y
// [1] : x
// [2] : time

int dir[4][2] = { {0, 1}, {1, 0} ,{-1, 0}, {0, -1} };
int candidate[900][2], ccnt;



void check_clear() {
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			check[i][j] = 0;
		}
	}
}

int process() {
	int find;
	int head, tail;
	int time = 0;
	int csize = 2;
	int eat_cnt = 0;
	while (1) {
		queue[0][0] = sy;
		queue[0][1] = sx;
		queue[0][2] = 0;
		head = 0, tail = 1;
		find = 0;
		check[sy][sx] = 1;
		ccnt = 0;
		while (head < tail) {
			int cy = queue[head][0];
			int cx = queue[head][1];
			for (int i = 0;i <= 3;i++) {
				int ny = cy + dir[i][0];
				int nx = cx + dir[i][1];
				if (ny > N || nx > N || ny <= 0 || nx <= 0) continue;
				if (check[ny][nx] != 0) continue;
				if (data[ny][nx] == 0 || data[ny][nx] == csize) { // 빈공간 혹은 사이즈 같은 물고기 있는 자리라면
					check[ny][nx] = 1;
					queue[tail][0] = ny;
					queue[tail][1] = nx;
					queue[tail][2] = queue[head][2] + 1;
					tail++;
				}
				else { // 물고기를 만났다면
					if (data[ny][nx] < csize) { // 먹을 수 있는 물고기라면
						if (find > 0 && queue[head][2] + 1 > find) continue;
						find = queue[head][2] + 1;
						ccnt++;
						candidate[ccnt][0] = ny;
						candidate[ccnt][1] = nx;
					}
					// 먹을 수 없는 물고기라면 아무일 생기지 않는다.
				}
			}
			head++;
		}

		if (ccnt == 0) { // 먹을 수 있는 물고기가 더이상 없다면
			return time;
		}
		else {

			int ty, tx, tt;
			ty = candidate[1][0];
			tx = candidate[1][1];
			tt = find;
			for (int i = 2;i <= ccnt;i++) {
				if (ty > candidate[i][0]) {
					ty = candidate[i][0];
					tx = candidate[i][1];
				}
				else if (ty == candidate[i][0] && tx > candidate[i][1]) {
					ty = candidate[i][0];
					tx = candidate[i][1];
				}
			}

			data[ty][tx] = 0;
			sy = ty; sx = tx;
			time += tt;

			eat_cnt++;
			if (eat_cnt == csize) {
				csize++; eat_cnt = 0;
			}
		}

		check_clear();
		ccnt = 0;
	}
	return 0;
}

int main(void) {
	scanf("%d", &N);
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			scanf("%d", &data[i][j]);
			if (data[i][j] == 9) {
				sy = i;
				sx = j;
				data[i][j] = 0;
			}
		}
	}

	printf("%d", process());

	return 0;
}