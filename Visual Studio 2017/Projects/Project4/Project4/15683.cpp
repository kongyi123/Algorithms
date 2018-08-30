// 1:03:00 - 1:23:00
// 데이터x => 가지치기제거, cctv 통과 되는 조건 추가
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int data[10][10];
int table[10][10];
int N, M;

struct Cctv {
	int type;
	int y, x;
	Cctv(int y, int x, int type) {
		this->y = y;
		this->x = x;
		this->type = type;
	}

	Cctv() {}
};

void draw(Cctv t, int dir, int cnt, int empty_count); // # 그렸을 때 새로 없어진 빈공간의 개수
void back(int cnt, int empty_count); // cnt = > 방향이 설정될 cctv의 숫자(번호)
// empty_count => 지도상에 비어있는 공간의 개수
int cctv_cnt;
int min = 0x7fffffff;




Cctv cctv[10];

int right(int queue[][2], int& tail, int y, int x) {
	int cnt = 0;
	for (int j = x + 1;j <= M;j++) {
		if (table[y][j] == 0) {
			table[y][j] = -1;
			queue[tail][0] = y;
			queue[tail][1] = j;
			tail++;
			cnt++;
		}
		else if (table[y][j] != 6) continue;
		else break;
	}
	return cnt;
}

int left(int queue[][2], int& tail, int y, int x) {
	int cnt = 0;
	for (int j = x - 1;j >= 1;j--) {
		if (table[y][j] == 0) {
			table[y][j] = -1;
			queue[tail][0] = y;
			queue[tail][1] = j;
			tail++; cnt++;
		}
		else if (table[y][j] != 6) continue;
		else break;
	}
	return cnt;
}

int up(int queue[][2], int& tail, int y, int x) {
	int cnt = 0;
	for (int i = y - 1;i >= 1;i--) {
		if (table[i][x] == 0) {
			table[i][x] = -1;
			queue[tail][0] = i;
			queue[tail][1] = x;
			tail++; cnt++;
		}
		else if (table[i][x] != 6) continue;
		else break;
	}
	return cnt;
}


int down(int queue[][2], int& tail, int y, int x) {
	int cnt = 0;
	for (int i = y + 1;i <= N;i++) {
		if (table[i][x] == 0) {
			table[i][x] = -1;
			queue[tail][0] = i;
			queue[tail][1] = x;
			tail++; cnt++;
		}
		else if (table[i][x] != 6) continue;
		else break;
	}
	return cnt;
}


void draw(Cctv t, int dir, int cnt, int empty_count) {
	int queue[100][2] = { 0, };
	int tail = 0;
	int new_count = 0;


	if (t.type == 1) {
		if (dir == 0) new_count += right(queue, tail, t.y, t.x);
		else if (dir == 1) new_count += left(queue, tail, t.y, t.x);
		else if (dir == 2) new_count += up(queue, tail, t.y, t.x);
		else if (dir == 3) new_count += down(queue, tail, t.y, t.x);
	}

	if (t.type == 2) {
		if (dir == 0 || dir == 1) { new_count += right(queue, tail, t.y, t.x); new_count += left(queue, tail, t.y, t.x); }
		else if (dir == 2 || dir == 3) { new_count += up(queue, tail, t.y, t.x); new_count += down(queue, tail, t.y, t.x); } // 오타
	}

	if (t.type == 3) {
		if (dir == 0) { new_count += right(queue, tail, t.y, t.x); new_count += up(queue, tail, t.y, t.x); }
		else if (dir == 1) { new_count += left(queue, tail, t.y, t.x); new_count += down(queue, tail, t.y, t.x); }
		else if (dir == 2) { new_count += up(queue, tail, t.y, t.x); new_count += left(queue, tail, t.y, t.x); }
		else if (dir == 3) { new_count += down(queue, tail, t.y, t.x); new_count += right(queue, tail, t.y, t.x); }
	}

	if (t.type == 4) {
		if (dir == 0) { new_count += right(queue, tail, t.y, t.x);new_count += up(queue, tail, t.y, t.x); new_count += left(queue, tail, t.y, t.x); }
		else if (dir == 1) { new_count += right(queue, tail, t.y, t.x); new_count += left(queue, tail, t.y, t.x); new_count += down(queue, tail, t.y, t.x); }
		else if (dir == 2) { new_count += up(queue, tail, t.y, t.x); new_count += left(queue, tail, t.y, t.x); new_count += down(queue, tail, t.y, t.x); }
		else if (dir == 3) { new_count += down(queue, tail, t.y, t.x); new_count += right(queue, tail, t.y, t.x);  new_count += up(queue, tail, t.y, t.x); }
	}

	if (t.type == 5) {
		new_count += right(queue, tail, t.y, t.x); new_count += up(queue, tail, t.y, t.x); new_count += left(queue, tail, t.y, t.x);  new_count += down(queue, tail, t.y, t.x);
	}
	
	back(cnt, empty_count - new_count);
	for (int i = 0;i < tail;i++) 
		table[queue[i][0]][queue[i][1]] = 0;
}

void back(int cnt, int empty_count) {
//	if (min < empty_count) return; // 가지 치기
	if (cnt == cctv_cnt) {
		if (min > empty_count) min = empty_count;
		return;
	}

	for (int i = 0;i <= 3;i++) { // 방향
		draw(cctv[cnt], i, cnt+1, empty_count);
	}
}


int main(void) {
//	freopen("input.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	int empty_count = 0;
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= M;j++) {
			scanf("%d", &data[i][j]);
			table[i][j] = data[i][j];
			if (data[i][j] >= 1 && data[i][j] <= 5) {
				cctv[cctv_cnt] = Cctv(i, j, data[i][j]);
				cctv_cnt++;
			}
			else if (data[i][j] == 0) empty_count++;
		}
	}

	back(0, empty_count);
	printf("%d", min);
	return 0;
}