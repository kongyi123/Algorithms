#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int ga[110][110];
int se[110][110];
int m, n, l, g;
int head, tail;

typedef struct node {
	int dir;
	int leftg;
	int y;
	int x;
	int time;
} node;

node queue[2000000];

void add(int dir, int y, int x, int leftg, int time) {
	queue[tail].dir = dir;
	queue[tail].y = y;
	queue[tail].x = x;
	queue[tail].leftg = leftg;
	queue[tail].time = time;
	tail++;
}

int sol() {
	int min = 1000000000;

	head = 0, tail = 0;
	add(0, 1, 1, g, 0); // 가로
	add(1, 1, 1, g, 0); // 세로

	int dir[2][2] = { {1, 0}, {0, 1} };

	while (head < tail) {
		int ny, nx;
		int cy, cx;
		int time;

		cy = queue[head].y; cx = queue[head].x;
		if (cy == m && cx == n) {
			if (min > queue[head].time) {
				min = queue[head].time;
			}
			head++;
			continue;
		}

		for (int i = 0;i <= 1;i++) {
			ny = cy + dir[i][0];
			nx = cx + dir[i][1];
			time = queue[head].time + l;
			if (queue[head].dir != 1-i) time += 1;
			int t;
			if (i == 0) t = se[cy][cx];
			else t = ga[cy][cx];

			if (queue[head].leftg >= t) {
				if (cy <= m && cx <= n) {
					add(1-i, ny, nx, queue[head].leftg - t, time);
				}
			}
		}
		head++;
	}

	if (min == 1000000000) return -1;

	return min;
}

int main(void) {
	int t;
	fscanf(stdin, "%d", &t);
	for (int i = 1;i <= t;i++) {
		fscanf(stdin, "%d%d%d%d", &m, &n, &l, &g);
		for (int j = 1;j <= m;j++)
			for (int k = 1;k <= n - 1;k++) 
				fscanf(stdin, "%d", &ga[j][k]);
		for (int j = 1;j <= m - 1;j++) 
			for (int k = 1;k <= n;k++) 
				fscanf(stdin, "%d", &se[j][k]);
		
		fprintf(stdout, "%d\n", sol());
	}
	return 0;
}
