// bfs (28Ка)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define IN stdin
#define OUT stdout

//FILE *in = fopen("input.txt", "r");
//FILE *out = fopen("output.txt", "w");

int m, n, k;
int map[102][102];
int visit[102][102];
int dir[4][2] = { {0,1 }, {1, 0}, {-1, 0}, {0, -1} };
int dcnt, dap[10001];

int fill(int y, int x) {
	int queue[20000][2] = { 0, };
	int head = 0, tail = 1;
	int xx, yy;
	int count = 1;
	queue[0][0] = y;
	queue[0][1] = x;
	visit[y][x] = 1;
	while (head < tail) {
		for (int i = 0;i <= 3;i++) {
			yy = queue[head][0] + dir[i][0];
			xx = queue[head][1] + dir[i][1];
			if (visit[yy][xx]) continue;
			if (map[yy][xx]) continue;
			if (0 <= yy && yy <= m - 1) {
				if (0 <= xx && xx <= n - 1) {
					visit[yy][xx] = 1;
					queue[tail][0] = yy;
					queue[tail][1] = xx;
					tail++;
					count++;
				}
			}
		}
		head++;
	}

	return count;
}

int main(void) {
	fscanf(IN, "%d%d%d", &m, &n, &k); // m : y , n : x
	for (int i = 1;i <= k;i++) {
		int x1, y1, x2, y2;
		fscanf(IN, "%d %d %d %d", &x1, &y1, &x2, &y2);
		for (int j = x1;j <= x2 - 1;j++) {
			for (int l = y1;l <= y2 - 1;l++) {
				map[l][j] = 1;
			}
		}
	}

	for (int i = 0;i <= m - 1;i++) {
		for (int j = 0;j <= n - 1;j++) {
			if (visit[i][j] == 0 && map[i][j] == 0) {
				dap[++dcnt] = fill(i, j);
			}
		}
	}

	for (int i = 1;i <= dcnt;i++) {
		for (int j = i + 1;j <= dcnt;j++) {
			if (dap[i] > dap[j]) {
				int t = dap[i];
				dap[i] = dap[j];
				dap[j] = t;
			}
		}
	}

	fprintf(OUT, "%d\n", dcnt);
	for (int i = 1;i <= dcnt;i++) {
		fprintf(OUT, "%d ", dap[i]);
	}
	return 0;
}