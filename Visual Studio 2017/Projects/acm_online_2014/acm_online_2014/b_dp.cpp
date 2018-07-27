#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <memory.h>
#define IN stdin
#define OUT stdout

FILE *in = fopen("input.txt", "r");
FILE *out = fopen("output.txt", "w");

int m, n, l, g;
int dy[110][110][220][2];

bool check[110][110][220][2];

int xgc[110][110];
int ygc[110][110];

int solution() {
	memset(check, 0, sizeof(check));
	memset(dy, 0, sizeof(dy));

	int i, j, k;
	// 가로 초기값
	dy[1][1][0][0] = 0;
	check[1][1][0][0] = 1;

	// 세로 초기값
	dy[1][1][0][1] = 0;
	check[1][1][0][1] = 1;

	for (i = 1;i <= m;i++) {
		for (j = 1;j <= n;j++) {
			for (int k = 0;k <= 200;k++) {
				if (check[i][j][k][0] == 1) {
					// 가로 방향 -> 세로
					if (check[i + 1][j][k + 1][1] && dy[i+1][j][k+1][1] > dy[i][j][k][0] + ygc[i][j]) {
						dy[i + 1][j][k + 1][1] = dy[i][j][k][0] + ygc[i][j];
					}
					else if (check[i + 1][j][k + 1][1] == 0) {
						check[i + 1][j][k + 1][1] = 1;
						dy[i + 1][j][k + 1][1] = dy[i][j][k][0] + ygc[i][j];
					}

					// 가로 방향 -> 가로

					if (check[i][j + 1][k][0] && dy[i][j + 1][k][0] > dy[i][j][k][0] + xgc[i][j]) {
						dy[i][j + 1][k][0] = dy[i][j][k][0] + xgc[i][j];
					}
					else if (check[i][j + 1][k][0] == 0) {
						check[i][j + 1][k][0] = 1;
						dy[i][j + 1][k][0] = dy[i][j][k][0] + xgc[i][j];
					}
				}
				
				if (check[i][j][k][1] == 1) {
					// 세로 방향 -> 세로
					if (check[i + 1][j][k][1] && dy[i + 1][j][k][1] > dy[i][j][k][1] + ygc[i][j]) {
						dy[i + 1][j][k][1] = dy[i][j][k][1] + ygc[i][j];
					}
					else if (check[i + 1][j][k][1] == 0) {
						check[i + 1][j][k][1] = 1;
						dy[i + 1][j][k][1] = dy[i][j][k][1] + ygc[i][j];
					}

					// 세로 방향 -> 가로
					if (check[i][j + 1][k + 1][0] && dy[i][j + 1][k + 1][0] > dy[i][j][k][1] + xgc[i][j]) {
						dy[i][j + 1][k + 1][0] = dy[i][j][k][1] + xgc[i][j];
					}
					else if (check[i][j + 1][k + 1][0] == 0) {
						check[i][j + 1][k + 1][0] = 1;
						dy[i][j + 1][k + 1][0] = dy[i][j][k][1] + xgc[i][j];
					}

				}
			}
		}
	}

	int min = 2000000000;
	for (int i = 1;i <= 200;i++) {
		if (check[m][n][i][0] == 1 && g > dy[m][n][i][0]) return i + (n + m - 2)*l;
		if (check[m][n][i][1] == 1 && g > dy[m][n][i][1]) return i + (n + m - 2)*l;
	}

	return -1;
}

int main(void) {
	int t;
	fscanf(IN, "%d", &t);
	for (int i = 1;i <= t;i++) {
		fscanf(IN, "%d %d %d %d", &m, &n, &l, &g);
		for (int i = 1;i <= m;i++) {
			for (int j = 1;j <= n-1;j++) {
				fscanf(IN, "%d", &xgc[i][j]);
			}
		}

		for (int i = 1;i <= m - 1;i++) {
			for (int j = 1;j <= n;j++) {
				fscanf(IN, "%d", &ygc[i][j]);
			}
		}

		int result = solution();
		fprintf(OUT, "%d\n", result);
	}

	return 0;
}