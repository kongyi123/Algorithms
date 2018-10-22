#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;
int map[11][11];
int r_check[11][11]; // 행, 번호
int c_check[11][11]; // 열, 알파벳(order)

int list[100][2], lcnt;
int is[11][11];
int rect[11][11];

void swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}

int end;

int dir[2][2] = { {0, 1}, {1, 0} };

void back(int sy, int sx, int cnt) {
	
	if (end == 1) return;
	if (sy == 8 && sx == 9) {
		for (int i = 0;i < 9;i++) {
			for (int j = 0;j < 9;j++) {
				printf("%d", map[i][j]);
			}
			printf("\n");
		}
		end = 1;
		return;
	}

	if (sx == 9) back(sy + 1, 0, cnt);
	int j = sx;
	int i = sy;
	if (map[i][j] != 0) back(sy, sx + 1, cnt);
	for (int k = 1;k <= lcnt;k++) {
		int a = list[k][0], b = list[k][1];
		for (int re = 1;re <= 2;re++) {
			for (int l = 0;l <= 1;l++) {
				if (i + dir[l][0] <= 8 && j + dir[l][1] <= 8 && map[i][j] == 0 && map[i + dir[l][0]][j + dir[l][1]] == 0 // 둘 수 있고
					&& r_check[i][a] == 0 && r_check[i + dir[l][0]][b] == 0		   // 행렬 번호 만족
					&& c_check[j][a] == 0 && c_check[j + dir[l][1]][b] == 0
					&& rect[(i) / 3 * 3 + (j) / 3][a] == 0 && rect[(i + dir[l][0]) / 3 * 3 + (j + dir[l][1]) / 3][b] == 0) { // 하면
					
					map[i][j] = a; map[i + dir[l][0]][j + dir[l][1]] = b;
					r_check[i][a] = r_check[i + dir[l][0]][b] = c_check[j][a] = c_check[j + dir[l][1]][b] = 1;
					rect[(i) / 3 * 3 + (j) / 3][a] = rect[(i + dir[l][0]) / 3 * 3 + (j + dir[l][1]) / 3][b] = 1;
					back(i, j + 1 + dir[l][1], cnt + 1);
					if (end == 1) return;
					rect[(i) / 3 * 3 + (j) / 3][a] = rect[(i + dir[l][0]) / 3 * 3 + (j + dir[l][1]) / 3][b] = 0;
					r_check[i][a] = r_check[i + dir[l][0]][b] = c_check[j][a] = c_check[j + dir[l][1]][b] = 0;
					map[i][j] = 0; map[i + dir[l][0]][j + dir[l][1]] = 0;
				}
			}
			swap(a, b);
		}
	}

}

void init() {
	for (int i = 0;i < 10;i++) {
		for (int j = 0;j < 10;j++) {
			map[i][j] = 0;
			r_check[i][j] = 0;
			c_check[i][j] = 0;
			is[i][j] = 0;
			rect[i][j] = 0;
		}
	}

	lcnt = 0;
}

int main(void) {
	int tc = 1;
	while (1) {
		init();

		scanf("%d", &N);
		if (N == 0) break;
		for (int i = 1;i <= N;i++) {
			int a, b;
			char p1[3], p2[3];
			scanf("%d %s %d %s", &a, p1, &b, p2);
			p1[0] -= 'A'; p1[1] -= '1';
			p2[0] -= 'A'; p2[1] -= '1';
			map[p1[0]][p1[1]] = a;
			r_check[p1[0]][a] = 1;
			c_check[p1[1]][a] = 1;

			map[p2[0]][p2[1]] = b;
			r_check[p2[0]][b] = 1;
			c_check[p2[1]][b] = 1;

			rect[(p1[0]) / 3 * 3 + (p1[1]) / 3][a] = 1;
			rect[(p2[0]) / 3 * 3 + (p2[1]) / 3][b] = 1;

			is[a][b] = is[b][a] = 1;
		}

		for (int i = 1;i <= 9;i++) {
			char p[3];
			scanf("%s", p);
			p[0] -= 'A'; p[1] -= '1';
			map[p[0]][p[1]] = i;

			r_check[p[0]][i] = 1;
			c_check[p[1]][i] = 1;
			rect[(p[0]) / 3 * 3 + (p[1]) / 3][i] = 1;
		}

		for (int i = 1;i <= 9;i++) {
			for (int j = i + 1;j <= 9;j++) {
				if (is[i][j] == 0) {
					lcnt++;
					list[lcnt][0] = i;
					list[lcnt][1] = j;
					is[i][j] = 1;
				}
			}
		}

		printf("Puzzle %d\n", tc++);

		end = 0;	
		back(0, 0, 0);

	}

	return 0;
}