// 49
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int dir[5][7] = {
	{0, 0, 0, 0, 0, 0, 0},
	{0, 4, 2, 1, 6, 5, 3},
	{0, 3, 2, 6, 1, 5, 4},
	{0, 5, 1, 3, 4, 6, 2},
	{0, 2, 6, 3, 4, 1, 5} };

int val[7];
int d[7];
int map[21][21];
int n, m, x, y, k;

void go(int direction) { // �ش� �������� ������ (�� �� �� ��)
	int t[7];
	for (int i = 1;i <= 6;i++) t[i] = d[i];
	for (int i = 1;i <= 6;i++) 
		d[i] = t[dir[direction][i]];
}

void trans(int y, int x) {
	if (map[y][x] == 0) { //  �̵��� ĭ�� �� �ִ� ���� 0�̸�, �ֻ����� �ٴڸ鿡 �� �ִ� ���� ĭ�� ����ȴ�.
		map[y][x] = d[6];
	}
	else {	// 0�� �ƴ� ��쿡�� ĭ�� �� �ִ� ���� �ֻ����� �ٴڸ����� ����Ǹ�, ĭ�� �� �ִ� ���� 0�� �ȴ�.
		d[6] = map[y][x];
		map[y][x] = 0;
	}
}

int main(void) {
	scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			scanf("%d", &map[i][j]);
		}
	}

	int xyp[5][2] = { {0,0}, {0, 1}, {0, -1}, {-1, 0}, {1, 0} };
	int pos_y, pos_x;
	pos_y = x;
	pos_x = y;
	for (int i = 1;i <= k;i++) {
		int temp;
		scanf("%d", &temp);
		int ny = pos_y + xyp[temp][0];
		int nx = pos_x + xyp[temp][1];
		if (ny < 0 || ny >= n) continue;
		if (nx < 0 || nx >= m) continue;
		pos_y = ny;
		pos_x = nx;
		go(temp);
		trans(pos_y, pos_x);
		printf("%d\n", d[1]);
	}


	return 0;
}