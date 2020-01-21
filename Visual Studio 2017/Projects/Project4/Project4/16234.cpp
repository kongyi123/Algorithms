#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, L, R;
int data[130][130];
int check[130][130];
int teamavr[3000], teamcnt[3000];
// 배열 크기 점검을 안해서 '런타임 에러' 나옴.

int dir[4][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };

int abs(int val) {
	if (val < 0) return -val;
	return val;
}

void back(int y, int x, int team_col) {
	for (int i = 0;i <= 3;i++) {
		int ny = y + dir[i][0];
		int nx = x + dir[i][1];
		if (ny <= 0 || ny > N || nx <= 0 || nx > N) continue;
		int t = abs(data[ny][nx] - data[y][x]);
		if (check[ny][nx] != 0) continue;
		if (L <= t && t <= R) {
			check[ny][nx] = team_col;
			teamavr[team_col] += data[ny][nx];
			teamcnt[team_col] ++;
			back(ny, nx, team_col);
		}
	}
}

void check_clear() {
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			check[i][j] = 0;
		}
	}
}

int process() {
	int col, change;
	int cnt = 0;

	while (1) {

		// 팀 나누기
		col = 0;
		for (int i = 1;i <= N;i++) {
			for (int j = 1;j <= N;j++) {
				if (check[i][j] == 0) {
					col++;
					teamavr[col] = data[i][j];
					teamcnt[col] = 1;
					check[i][j] = col;
					
					back(i, j, col);
				}
			}
		}

//		print();

		// 일괄 처리
		change = 0;
		for (int i = 1;i <= N;i++) {
			for (int j = 1;j <= N;j++) {
				col = check[i][j];
				int newval = teamavr[col] / teamcnt[col];
				if (data[i][j] != newval) {
					change = 1;
					data[i][j] = newval;
				}
			}
		}

		if (change == 0) break;
		cnt++;
		check_clear();
	}

	return cnt;
}

int main(void) {
	scanf("%d%d%d", &N, &L, &R);
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			scanf("%d", &data[i][j]);
		}
	}  

	printf("%d", process());

	return 0;
}