#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#define IN in
#define OUT out

FILE *in = fopen("input.txt", "r");
FILE *out = fopen("output.txt", "w");

int row[200], col[200];
int diag1[400], diag2[400];
int posX[200][200];
int posP[200][200];
char grid[200][200];

int n, m;

void placeX() {
	int i, j;
	for (i = 1;i <= n;i++) {
		if (row[i] == 1) continue;
		for (j = 1;j <= n;j++) {
			if (col[j] == 1) continue;

			// 올릴 수 있을 때.
			posX[i][j] = 1;
			row[i] = col[j] = 1;

			break;
		}
	}
}

void placeP() {
	int i, j;
	int t = 0, cnt = 0;
	int order[300];
	for (i = 1;i <= n - 1;i++) {
		order[++t] = i;
		order[++t] = n * 2 - i;
	}
	order[++t] = i;

	for (i = 1;i <= t;i++) {
		if (diag1[order[i]] == 1) continue;
		int y, x;
		if (order[i] <= n) y = order[i];
		else y = n;
		if (order[i] <= n) x = 1;
		else x = order[i] - n + 1; // 6-5+1 = 2

		while (x <= n && y >= 1) {
			if (diag2[n + y - x] == 1) {
				x++;
				y--;
				continue;
			}

			diag2[n + y - x] = diag1[order[i]] = 1;
			posP[y][x] = 1;
			break;
		}
	}
}

int main(void) {
	int t;
	char buf[10];
	fscanf(IN, "%d", &t);
	for (int i = 1;i <= t;i++) {
		int score = 0;
		memset(row, 0, sizeof(row));
		memset(col, 0, sizeof(col));
		memset(diag1, 0, sizeof(diag1));
		memset(diag2, 0, sizeof(diag2));
		memset(posX, 0, sizeof(posX));
		memset(posP, 0, sizeof(posP));
		memset(grid, 0, sizeof(grid));
		fscanf(IN, "%d %d", &n, &m);
		for (int j = 1;j <= m;j++) {
			char ch;
			int y, x;
			fgets(buf, 10, IN);
			fscanf(IN, "%c %d %d", &ch, &y, &x);
			if (ch == 'x') {
				row[y] = 1;
				col[x] = 1;
				grid[y][x] = 'x';
				score++;
			}
			else if (ch == '+') {
				diag1[y + x - 1] = 1;	// 1 ~ 5 
				diag2[n + y - x] = 1;	// 1 ~ 5
				grid[y][x] = '+';
				score++;
			}
			else if (ch == 'o') {
				row[y] = col[x] = 1;
				diag1[y + x - 1] = diag2[n + y - x] = 1;
				// diag1 왼쪽 위가 첫 인덱스
				// diag2 우측 위가 첫 인덱스
				grid[y][x] = 'o';
				score += 2;
			}
			else grid[y][x] = '.';

		}


		placeX();
		placeP();

		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= n;j++) {
				score += posX[i][j] + posP[i][j];
			}
		}


		int cnt = 0;
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= n;j++) {
				if ((posX[i][j] == 1 || grid[i][j] == 'x') && (posP[i][j] == 1 || grid[i][j] == '+')) {
					cnt++;
				}
				else if (posX[i][j] == 1) cnt++;
				else if (posP[i][j] == 1) cnt++;
			}
		}

		// 점수, 새로 놓는 돌의 개수
		fprintf(OUT, "Case #%d: %d %d\n", i, score, cnt);
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= n;j++) {
				if ((posX[i][j] == 1 || grid[i][j] == 'x') && (posP[i][j] == 1 || grid[i][j] == '+')) {
					fprintf(OUT, "o %d %d\n", i, j);
				}
				else if (posX[i][j] == 1) fprintf(OUT, "x %d %d\n", i, j);
				else if (posP[i][j] == 1) fprintf(OUT, "+ %d %d\n", i, j);
			}
		}
	}

	return 0;
}