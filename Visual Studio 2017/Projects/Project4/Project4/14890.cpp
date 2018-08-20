// 1:21
// 1. ������ ����� �� �Լ��� ó���ϸ� ���� �ӵ��� ������ ���̶�� �����Ͽ��� (�ܹ��� ������ �ȵǾ��� �� ������� ���� �پ���״ϱ�)
// 2. ���� ����� ������ ����� �����ڸ� �ۼ����� �ʰ� ���� ���⸸ �����Ͽ��ٰ� ��ŰԵ�
// 3. ���� ȿ������ ����� ã������ �ϴٰ� N������ ���� �ܼ��� �ڵ��ϱ� ���� ���Ʈ ������ ������ �׸�. (�־��� ��� �ð����⵵�� �����Ѵٸ� ���� ȿ�����ְ� �̻� �ַ���� ���� �ʿ� ����)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, L;
int table[110][110];
int dat[110][110];
int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
int diff;

int make_road(int y, int x, int d) {
	// �� �� �Ǵ� �� ���� +/-�������� ���� �� �ִ� ���� �������� ���θ� ����
	
	int ty, tx;
	for (int p = 2;p <= N;p++) {
		diff = dat[y][x] - dat[y - dir[d][0]][x - dir[d][1]];
		if (diff == -1) {
			ty = y; tx = x;
			for (int i = 0;i < L;i++) {
				if (ty > N || ty < 1) return -1;
				if (tx > N || tx < 1) return -1;
				if (table[ty][tx] == 1) return -1;
				if (dat[y][x] != dat[ty][tx]) return -1;
				ty += dir[d][0];
				tx += dir[d][1];
			}

			ty = y; tx = x;
			for (int i = 0;i < L;i++) {
				table[ty][tx] = 1;
				ty += dir[d][0];
				tx += dir[d][1];
			}
		}
		else if (diff >= 2) return -1;
		y += dir[d][0];
		x += dir[d][1];
	}

	return 1;
}

int main(void) {
	scanf("%d %d", &N, &L);
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			scanf("%d", &dat[i][j]);
		}
	}

	int cnt = 0;
	for (int i = 1;i <= N;i++) {
		if (make_road(i, 2, 0) != 1) continue;
		if (make_road(i, N-1, 1) != 1) continue;
		cnt++;
	}

	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			table[i][j] = 0;
		}
	}

	for (int j = 1;j <= N;j++) {
		if (make_road(2, j, 2) != 1) continue;
		if (make_road(N-1, j, 3) != 1) continue;
		cnt++;
	}

	printf("%d", cnt);
		
	return 0;
}