#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>

#include <conio.h>
#define MAX 98765432
#define INF 125
#define MOD 10000003

using namespace std;

queue<int> visit[MOD];

// 16MB = 16 * mega * byte
//      = 16 * 1024 * 1024 * 8bit = 2^4 * 2^20 * 2^3 = 2^27 bit = 134217728 bit
//bool visit[MAX];		// 1bit x 98765432						=  98768792 bit
char table[3][3];		// 3*3*256 = 2304
char pos, num;			// 256*2	= 512
int bitmask;			// 8byte	= 32bit     
char y, x;				// 256*2	= 512
char dir[4][2] = { { 0, 1 },{ 1, 0 },{ -1, 0 },{ 0, -1 } };		// 8
char min_ = INF;													// 256

inline void swap(char& a, char& b) {
	char t = a;
	a = b;
	b = t;
}

inline void mask2arr(int bitmask, char arr[][3]) {
	num = 0;
	for (char i = 0;i <= 2;i++) {
		for (char j = 0;j <= 2;j++) {
			arr[i][j] = 0;
		}
	}

	while (bitmask) {
		num++;
		pos = bitmask % 10;
		y = (pos-1) / 3;
		x = (pos-1) % 3;
		arr[y][x] = num;
		bitmask = bitmask / 10;
	}
}

inline void arr2mask(char arr[][3], int& bitmask) {
	bitmask = 0;
	int t;
	char pos = 0;
	for (char i = 0;i <= 2;i++) {
		for (char j = 0;j <= 2;j++) {
			pos++;
			if (arr[i][j] == 0) continue;

			t = 1;
			for (char k = 1;k < arr[i][j];k++) {
				t = t * 10;
			}
			bitmask += t * pos;
		}
	}
}

void print() {
	for (int i = 0;i <= 2;i++) {
		for (int j = 0;j <= 2;j++) {
			printf("%d", table[i][j]);
		}
		printf("\n");
	}

	printf("\n");
	_getch();
}


void back(int state, char cnt) { // 현재 상태, 이동시킨 개수
//	print();
	if (cnt > min_) return;
	if (state == 87654321) {
		if (min_ > cnt)
			min_ = cnt;
		return;
	}
	mask2arr(state, table);
	for (char i = 0;i <= 2;i++) {
		for (char j = 0;j <= 2;j++) {
			if (table[i][j] == 0) {
				for (char k = 0;k <= 3;k++) {
					if (i + dir[k][0] < 0 || i + dir[k][0] > 2) continue;
					if (j + dir[k][1] < 0 || j + dir[k][1] > 2) continue;
					swap(table[i][j], table[i + dir[k][0]][j + dir[k][1]]); // 변경

					arr2mask(table, state);
					if (visit[state%MOD].size() == 0) {
						visit[state%MOD].push(state);
						back(state, cnt + 1);
//						visit[state%MOD].pop();
					}
					else {
						bool er = 0;
						char len = visit[state%MOD].size();
						for (int i = 0;i < len;i++) {
							int t = visit[state%MOD].front();
							if (t == state) {
								er = 1; break;
							}
							visit[state%MOD].push(t);
						}

						if (er == 0) {
							visit[state%MOD].push(state);
							back(state, cnt + 1);
//							visit[state%MOD].pop();
						}
					}
					swap(table[i][j], table[i + dir[k][0]][j+dir[k][1]]); // 복구
					arr2mask(table, state);
				}
				
			}
		}
	}
	arr2mask(table, state);
}

int main(void) {
	bitmask = 0;
	pos = 0;
	//freopen("input.txt", "r", stdin);
	for (char i = 0;i <= 2;i++) {
		for (char j = 0;j <= 2;j++) {
			scanf(" %c", &num);
			table[i][j] = num-'0';
		}
	}
	
	arr2mask(table, bitmask);

	visit[bitmask%MOD].push(1);
	back(bitmask, 0);
	if (min_ == INF) printf("-1");
	else printf("%d", min_);
	return 0;
}