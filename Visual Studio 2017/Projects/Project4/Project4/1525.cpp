#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#include <conio.h>
#define MAX 98765432

bool visit[MAX];
char table[3][3];

void swap(char& a, char& b) {
	char t = a;
	a = b;
	b = t;
}

// idx에 num을 끼워넣음
void put(int& bitmask, int idx, int num) {
	int t = 1;
	for (char i = 1;i < idx;i++) {
		t = t * 10;
	}
	bitmask += t * num;
}


void clear(char arr[][3]) {
	for (char i = 0;i <= 2;i++) {
		for (char j = 0;j <= 2;j++) {
			arr[i][j] = 0;
		}
	}
}

void mask2arr(int bitmask, char arr[][3]) {
	char pos;
	char num = 0;
	char y, x;
	clear(arr);

	while (bitmask) {
		num++;
		pos = bitmask % 10;
		y = (pos-1) / 3;
		x = (pos-1) % 3;
		arr[y][x] = num;
		bitmask = bitmask / 10;
	}
}

void arr2mask(char arr[][3], int& bitmask) {
	bitmask = 0;
	char t = 1;
	char pos = 0;
	for (char i = 0;i <= 2;i++) {
		for (char j = 0;j <= 2;j++) {
			pos++;
			if (arr[i][j] == 0) continue;
			put(bitmask, arr[i][j], pos);
		}
	}
}

char dir[4][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };
char min = 10;

void back(int state, char cnt) { // 현재 상태, 이동시킨 개수
	if (cnt > min) return;
	if (state == 87654321) {
		if (min > cnt)
			min = cnt;
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
					if (visit[state] == 0) {
						visit[state] = 1;
						back(state, cnt + 1);
						visit[state] = 0;
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
	char num;
	int bitmask = 0;
	char pos = 0;
	//freopen("input.txt", "r", stdin);
	for (char i = 0;i <= 2;i++) {
		for (char j = 0;j <= 2;j++) {
			scanf("%d", &num);
			pos++;
			if (num == 0) continue;
			put(bitmask, num, pos); // 
		}
	}

	visit[bitmask] = 1;
	back(bitmask, 0);
	if (min == 10) printf("-1");
	else printf("%d", min);
	return 0;
}