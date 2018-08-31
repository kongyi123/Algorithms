// 52
// ������ x
// �ڵ� �߰��� ������ ���ؼ� ������ ������ ���°� �ݵ�� �����.
// ���� �׽�Ʈ �����ʹ� 10���̻� �ݵ�� ���� ��.


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, M;
int table[10][10];
int cctv_dir[10];
int ccnt;

int min = 0x7fffffff;

int dat[10][10];

int ini_empty_cnt;

int line(int sy, int sx, int dy, int dx) { // ���� ���� cctv���� ǥ�õ� �κ��� ����
	int cnt = 0;
	while (1) {
		sy += dy;
		sx += dx;
		if (sy > N || sy < 1) break;
		if (sx > M || sx < 1) break;
		if (table[sy][sx] == 0) table[sy][sx] = 8;
		else if (table[sy][sx] == 6) break;
		else continue;
		cnt++;
	}
	return cnt;
}

void turn(int &dy, int &dx) { // �ð�������� ȸ��
	int ty = dy;
	int tx = dx;
	dy = -tx;
	dx = ty;
}

int dir[4][2] = { { 0, 1 }, { 0, -1 }, {-1, 0}, {1, 0} };

int project_unit(int y, int x, int type, int t) { // ����� ������ ���� ����
	int cnt = 0;
	int dy, dx;
	dy = dir[t][0];
	dx = dir[t][1];
	switch (type) {
	case 1:
		cnt += line(y, x, dy, dx);
		break;
	case 2:
		cnt += line(y, x, dy, dx);
		turn(dy, dx);turn(dy, dx);
		cnt += line(y, x, dy, dx);
		break;
	case 3:
		cnt += line(y, x, dy, dx);
		turn(dy, dx);turn(dy, dx);turn(dy, dx);
		cnt += line(y, x, dy, dx);
		break;
	case 4:
		cnt += line(y, x, dy, dx);
		turn(dy, dx);turn(dy, dx);
		cnt += line(y, x, dy, dx);
		turn(dy, dx);
		cnt += line(y, x, dy, dx);
		break;
	case 5:
		cnt += line(y, x, dy, dx);
		turn(dy, dx);
		cnt += line(y, x, dy, dx);
		turn(dy, dx);
		cnt += line(y, x, dy, dx);
		turn(dy, dx);
		cnt += line(y, x, dy, dx);
		break;
	}
	return cnt;
}


void copy() {
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= M;j++) {
			table[i][j] = dat[i][j];
		}
	}
}

int project() { // ��ü �����ؼ� ���ð����� ������ ĭ�� ��ȯ
	int cnt = 0;
	int cctv_id = 0;
	copy();
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= M;j++) {
			if (table[i][j] >= 1 && table[i][j] <= 5) {
				cctv_id++;
				cnt += project_unit(i, j, table[i][j], cctv_dir[cctv_id]);
			}
		}
	}

	return cnt;
}

void back(int cctv_cnt) { // ������ ������ cctv�� ����
	if (cctv_cnt == ccnt) {
		int temp = ini_empty_cnt - project();
		if (min > temp) min = temp;
		return;
	}
	
	for (int dir = 0;dir <= 3;dir ++) {
		cctv_dir[cctv_cnt+1] = dir;
		back(cctv_cnt + 1);
	}
}

int main(void) {
	scanf("%d %d", &N, &M);
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= M;j++) {
			scanf("%d", &dat[i][j]);
			if (dat[i][j] >= 1 && dat[i][j] <= 5) ccnt++;
			else if (dat[i][j] == 0) ini_empty_cnt++;
			table[i][j] = dat[i][j];
		}
	}

	back(0); 
	printf("%d", min);
	return 0;
}