#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int dat[12][30];
int check[12][30];
int T, H, W;
int max;

int ty, tx;
int er;

void print() {
	for (int i = 1;i <= H;i++) {
		for (int j = 1;j <= W;j++) {
			printf("%3d", check[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}

int space_check(int y, int x) {
	if (check[y][x] == 1) return 0;
	if (check[y + 1][x] == 1) return 0;
	if (check[y][x + 1] == 1) return 0;
	if (check[y + 1][x + 1] == 1) return 0;

	if (dat[y][x] == 1) return 0;
	if (dat[y + 1][x] == 1) return 0;
	if (dat[y][x + 1] == 1) return 0;
	if (dat[y + 1][x + 1] == 1) return 0;

	if (y < 1 || y + 1 > H) return 0;
	if (x < 1 || x + 1 > W) return 0;
	return 1;
}

//  back(현재 고려하고 있는 행, 사각형 둔 개수) 
void back(int row, int x, int cnt) {
	if (max < cnt) {
		//		print();
		max = cnt;
	}

	for (int i = row;i <= H;i++) {
		for (int j = x;j < W;j++) {
			if (dat[i][j] == 0 && check[i][j] == 0) {
				if (space_check(i, j)) {
					check[i][j] = check[i + 1][j] = check[i][j + 1] = check[i + 1][j + 1] = 1;
					back(i, j + 2, cnt + 1);
					check[i][j] = check[i + 1][j] = check[i][j + 1] = check[i + 1][j + 1] = 0;
				}

				if (space_check(i, j + 1)) {
					check[i][j + 1] = check[i + 1][j + 1] = check[i][j + 2] = check[i + 1][j + 2] = 1;
					back(i, j + 3, cnt + 1);
					check[i][j + 1] = check[i + 1][j + 1] = check[i][j + 2] = check[i + 1][j + 2] = 0;
					return;
				}
			}
		}
		x = 1;
	}
}


int main(void) {
	//	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1;tc <= T;tc++) {
		scanf("%d %d", &H, &W);
		for (int i = 1;i <= H;i++) {
			for (int j = 1;j <= W;j++) {
				scanf("%d", &dat[i][j]);
			}
		}

		max = 0;
		back(1, 1, 0);
		printf("#%d %d\n", tc, max);

	}
	return 0;
}
