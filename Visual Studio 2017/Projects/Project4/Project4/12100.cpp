// 1:20
// .... 괜찮긴 했는데.. backup 함수를 안만듦....

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int dat[22][22];
int N;
int table[22][22];
int max = 0;

void gravity(int dir); // 블록의 dir방향으로 이동시킴
void merge(int dir); // 인접한 블록을 역방향으로 합침
void back(int move_count); // 블록을 4 방향으로 이동시켜보면서 back(여지껏 이동시킨횟수)
void step(int dir);

void restore(int copy[][22]); // 블록을 상태를 1step 이전상태로 되돌림
void backup(int copy[][22]);

void print() {
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			printf("%3d", table[i][j]);
		}
		printf("\n");
	}
}

int main(void) {
//	freopen("input.txt", "r", stdin); // 반드시 제출 전 주석처리 할 것.
	scanf("%d", &N);
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			scanf("%d", &dat[i][j]);
			table[i][j] = dat[i][j];
		}
	}

	back(0); // back(블록 이동 횟수)

	printf("%d", max);
	return 0;
}

void restore(int copy[][22]) {
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			table[i][j] = copy[i][j];
		}
	}
}

void backup(int copy[][22]) {
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			copy[i][j] = table[i][j];
		}
	}
}

void back(int move_count) {
	if (move_count == 5) {
		for (int i = 1;i <= N;i++) {
			for (int j = 1;j <= N;j++) {
				if (max < table[i][j]) max = table[i][j];
			}
		}
		return;
	}

	int copy[22][22] = { 0, };

	for (int dir = 0;dir <= 3;dir++) {
		backup(copy);
		step(dir);
		back(move_count + 1);
		restore(copy);
	}
}

void step(int dir) {
	gravity(dir);
	merge(dir);
	gravity(dir);
}


void gravity(int dir) {
	int queue[100][2];
	int head, tail;
	int sy, sx;
	// 0==우 1==상 2==좌 3==하
	int ini[4][2] = { { 1, N },{ 1, 1 },{ 1, 1 },{ N, 1 } };
	int in_d[4][2] = { { 0, -1 },{ 1, 0 },{ 0, 1 },{ -1, 0 } };
	int out_d[4][2] = { { 1, 0 },{ 0, 1 },{ 1, 0 },{ 0, 1 } };
	sy = ini[dir][0];
	sx = ini[dir][1];
	int y, x;
	for (int i = 1;i <= N;i++) {
		y = sy;
		x = sx;
		head = tail = 0;
		for (int j = 1;j <= N;j++) {
			if (table[y][x] == 0) {
				queue[tail][0] = y;
				queue[tail][1] = x;
				tail++;
			}
			else if (head < tail) {
				table[queue[head][0]][queue[head][1]] = table[y][x];
				head++;
				table[y][x] = 0;
				queue[tail][0] = y;
				queue[tail][1] = x;
				tail++;
			}
			y += in_d[dir][0];
			x += in_d[dir][1];
		}
		sy += out_d[dir][0];
		sx += out_d[dir][1];
	}
}

void merge(int dir) {
	int head, tail;
	int sy, sx;
	// 0==우 1==상 2==좌 3==하
	int ini[4][2] = { { 1, N },{ 1, 1 },{ 1, 1 },{ N, 1 } };
	int in_d[4][2] = { { 0, -1 },{ 1, 0 },{ 0, 1 },{ -1, 0 } };
	int out_d[4][2] = { { 1, 0 },{ 0, 1 },{ 1, 0 },{ 0, 1 } };
	sy = ini[dir][0];
	sx = ini[dir][1];
	int y, x;
	for (int i = 1;i <= N;i++) {
		y = sy;
		x = sx;
		head = tail = 0;
		for (int j = 1;j <= N;j++) {
			if (table[y][x] != 0 && table[y][x] == table[y-in_d[dir][0]][x-in_d[dir][1]]) {
				table[y - in_d[dir][0]][x - in_d[dir][1]] += table[y][x];
				table[y][x] = 0;
			}

			y += in_d[dir][0];
			x += in_d[dir][1];
		}
		sy += out_d[dir][0];
		sx += out_d[dir][1];
	}
}

