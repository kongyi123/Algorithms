// 52
// 데이터 x
// 코딩 중간에 집중을 못해서 정신이 나가는 상태가 반드시 생긴다.
// 따라서 테스트 데이터는 10개이상 반드시 만들어볼 것.


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, M;
int table[10][10];
int cctv_dir[10];
int ccnt;

int min = 0x7fffffff;

int dat[10][10];

int ini_empty_cnt;

int line(int sy, int sx, int dy, int dx) { // 새로 생긴 cctv영역 표시된 부분의 개수
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

void turn(int &dy, int &dx) { // 시계방향으로 회전
	int ty = dy;
	int tx = dx;
	dy = -tx;
	dx = ty;
}

int dir[4][2] = { { 0, 1 }, { 0, -1 }, {-1, 0}, {1, 0} };

int project_unit(int y, int x, int type, int t) { // 방향과 종류에 따라 투사
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

int project() { // 전체 투사해서 감시가능한 영역의 칸수 반환
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

void back(int cctv_cnt) { // 방향이 결정된 cctv의 개수
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