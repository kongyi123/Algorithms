// bfs.
// bfs를 사용할 때는 시간 공간 복잡도가 가`능한지 확인을 해야 한다.
// 문제유형 : 어떤 bound를 만족하는 가지들 중 가장 빠른 시간에 갈 수 있는 경로를 찾는 문제.
// 풀이는 다이나믹.


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int ygc[200][200];
int xgc[200][200];
int m, n, l, g;
int t;

int min;


typedef struct location {
	int y;
	int x;
	int leftg;
	int time;
	int dir;
};

location heap[2000000];
int hcnt;

void swap(location &a, location &b) {
	location t;
	t = a;
	a = b;
	b = t;
}

void heap_add(location m) {
	hcnt++;
	heap[hcnt] = m;
	for (int j = hcnt;j > 1;j = j >> 1) {
		if (heap[j].time < heap[j >> 1].time) swap(heap[j], heap[j >> 1]);
	}
}

location heap_pop() {
	swap(heap[1], heap[hcnt]);
	for (int j = 1;;) {
		int k = j << 1;
		if (k > hcnt) break;
		if (k + 1 <= hcnt && heap[k].time < heap[k + 1].time) k++;
		if (heap[j].time < heap[k].time) {
			swap(heap[j], heap[k]);
			j = k;
		}
		else break;
	}
	hcnt--;
	return heap[hcnt + 1];
}

void process() {
	location start;
	start.time = 0;
	start.x = 1;
	start.y = 1;
	start.leftg = g;
	start.dir = 1; // 세로
	heap_add(start);

	start.time = 0;
	start.x = 1;
	start.y = 1;
	start.leftg = g;
	start.dir = 2; // 가로 
	heap_add(start);

	min = 2000000000;

	while (hcnt) {
		location cur, next;
		cur = heap_pop();
		if (cur.y == m && cur.x == n) {
			if (min > cur.time) {

				min = cur.time;
			}
		}
		// 세로로 가는 경우
		next = cur;
		next.dir = 1;
		if (cur.dir == 2) next.time += 1;
		next.time += l;
		next.leftg -= ygc[cur.y][cur.x];
		next.y += 1;
		if (next.leftg > 0) {
			if (next.y <= m && next.x <= n) {
				heap_add(next);
			}
		}

		// 가로로 가는 경우
		next = cur;
		next.dir = 2;
		if (cur.dir == 1) next.time += 1;
		next.time += l;
		next.leftg -= xgc[cur.y][cur.x];
		next.x += 1;
		if (next.leftg > 0) {
			if (next.y <= m && next.x <= n) {
				heap_add(next);
			}
		}

	}
}


int main(void) {
	fscanf(stdin, "%d", &t);
	for (int i = 1;i <= t;i++) {
		fscanf(stdin, "%d %d %d %d", &m, &n, &l, &g);
		for (int i = 1;i <= m;i++) {
			for (int j = 1;j <= n - 1;j++) {
				fscanf(stdin, "%d", &xgc[i][j]);
			}
		}

		for (int i = 1;i <= m - 1;i++) {
			for (int j = 1;j <= n;j++) {
				fscanf(stdin, "%d", &ygc[i][j]);
			}
		}

		process();
		if (min == 2000000000) min = -1;
		fprintf(stdout, "%d\n", min);
	}

	return 0;
}