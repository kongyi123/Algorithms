/*
	������ �� �غ��� �ڴ�.
	�����ϰ� �ִ� Ǯ�̴� �Ʒ��� ����.

	���� �̵������� ��ȭ�� ������� ���������� �߰������� Ž������ �ʴ� �����
	�ִ밪�� ��� ���� �����ָ鼭  ���� Depth���� �ִ밪�� ���� ������ �� ���ٰ� �ǴܵǴ� ��� ����ġ���ϴ� ������� �ؼ� AC�޾ҽ��ϴ�..
	������� 10�� �̵������� ���� �������ִ� �ִ밪�� 1024�̶��
	�ٷ� �� Depth���� �ִ밪�� 512���Ϸ� ������ ���
	�� ���� Depth���� �ִ밪�� 256���Ϸ� ������ ���
	���� ���̻� ������°� �ǹ̰����� �˴ϴ�.

	��ȿ�������� gravity�� merge�� ������ �ƴ϶� �ѹ��� ó���ؾ� �ð��ʰ��� �ȳ��� ��
*/


#define _CRT_SECURE_NO_WARNINGS
//#include <conio.h>
#include <stdio.h>
#include <algorithm>
#define END_CNT 10

using namespace std;

int dat[22][22];
int N;
int table[22][22];
int dap = -1;
int ini[4][2] = { { 1, N },{ 1, 1 },{ 1, 1 },{ N, 1 } }; // �� N������..... ��� �����ϰ� �־���. ����� �Ǽ� �� �� �ִ� �κ�
int in_d[4][2] = { { 0, -1 },{ 1, 0 },{ 0, 1 },{ -1, 0 } };
int out_d[4][2] = { { 1, 0 },{ 0, 1 },{ 1, 0 },{ 0, 1 } };
int queue[100][2];
int y, x;
int head, tail;
int sy, sx;

void gravity(int dir) {
	// 0==�� 1==�� 2==�� 3==��
	sy = ini[dir][0];
	sx = ini[dir][1];
	for (int i = 1; i <= N; i++) {
		y = sy;
		x = sx;
		head = tail = 0;
		for (int j = 1; j <= N; j++) {
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

pair<int, int> merge(int dir, int before_cnt) {
	int max = 0;
	// 0==�� 1==�� 2==�� 3==��
	sy = ini[dir][0];
	sx = ini[dir][1];
	for (int i = 1; i <= N; i++) {
		y = sy;
		x = sx;
		head = tail = 0;
		for (int j = 1; j <= N; j++) {
			if (max < table[y][x]) max = table[y][x];
			if (table[y][x] != 0 && table[y][x] == table[y - in_d[dir][0]][x - in_d[dir][1]]) {
				table[y - in_d[dir][0]][x - in_d[dir][1]] += table[y][x];
				if (max < table[y - in_d[dir][0]][x - in_d[dir][1]])
					max = table[y - in_d[dir][0]][x - in_d[dir][1]];
				table[y][x] = 0;
				before_cnt--;
			}
			y += in_d[dir][0];
			x += in_d[dir][1];
		}
		sy += out_d[dir][0];
		sx += out_d[dir][1];
	}
	return pair<int, int>(before_cnt, max);
}


pair<int, int> step(int dir, int before_cnt) {
	gravity(dir);
	pair<int, int> t = merge(dir, before_cnt);
	gravity(dir);
	return t;
}

void restore(int copy[][22]) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			table[i][j] = copy[i][j];
		}
	}
}

void backup(int copy[][22]) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			copy[i][j] = table[i][j];
		}
	}
}

void back(int move_count, int before_dir, int block_cnt, int cur_max) {
	if (cur_max << (END_CNT - move_count) <= dap) return;
	if (dap < cur_max) dap = cur_max;
	if (move_count == END_CNT) return;

	int copy[22][22] = { 0, };

	backup(copy);
	for (int dir = 0; dir <= 3; dir++) {
		pair<int, int> t = step(dir, block_cnt);
		if (dir == before_dir && block_cnt == t.first) continue;
		back(move_count + 1, dir, t.first, t.second);
		restore(copy);
	}
}


int main(void) {
	//	freopen("input.txt", "r", stdin); // �ݵ�� ���� �� �ּ�ó�� �� ��.
	scanf("%d", &N);
	ini[0][1] = N;
	ini[3][0] = N;


	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &dat[i][j]);
			table[i][j] = dat[i][j];
			if (table[i][j]) cnt++;
		}
	}

	back(0, -1, cnt, 0); // back(��� �̵� Ƚ��)

	printf("%d", dap);
	return 0;
}

