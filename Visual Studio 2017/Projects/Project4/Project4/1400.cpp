// 안그래도 헷갈리는데 끼워 맞추지 않고.
// 내가 정확하게 이해하기 편한쪽으로 식을 변형하여 계산할 것.

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define INF 0x7fffffff

int N, M;
char map[23][23];

int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int visited[23][23];

struct IntersUnit {
	char dir;
	int a;
	int b;
};

IntersUnit inters[500];
int flag = 0;

int min_(int a, int b) {
	if (a > b) return b;
	return a;
}

int min;

int add(int i, int num, int time) {
	char dir;
	if (i == 1 || i == 3) dir = '-';
	else dir = '|';
	int period = inters[num].a + inters[num].b;

	time = (time+1) % period;
	if (time == 0) time = period;

	if (dir == '-') {
		if (inters[num].dir == '-') {
			if (time <= inters[num].a) return 1;
			else return period + 2 - time;
		}
		else if (inters[num].dir == '|') {
			if (time > inters[num].b) return 1;
			else return inters[num].b + 2 - time;
		}
	}
	
	else { // if (dir == '|') {
		if (inters[num].dir == '-') {
			if (time > inters[num].a) return 1;
			else return inters[num].a + 2 - time;
		}
		else if (inters[num].dir == '|') {
			if (time <= inters[num].b) return 1;
			else return period + 2 - time;
		}
	}
}

void back(int cx, int cy, int dist) {
	if (min <= dist) return;
	for (int i = 0;i <= 3;i++) {
		int nx = cx + dir[i][0];
		int ny = cy + dir[i][1];
		if (ny <= 0 || ny > M) continue;
		if (nx <= 0 || nx > N) continue;

		if (map[ny][nx] == '#' && visited[ny][nx] == 0) {
			visited[ny][nx] = 1;
			back(nx, ny, dist + 1);
			visited[ny][nx] = 0;
		}
		else if (map[ny][nx] >= '0' && map[ny][nx] <= '9' && visited[ny][nx] == 0) {
			visited[ny][nx] = 1;
			int num = map[ny][nx] - '0';
			back(nx, ny, dist + add(i, num, dist));
			visited[ny][nx] = 0;
		}
		else if (map[ny][nx] == 'B') {
			min = min_(min, dist+1);
			return;
		}
	}
}

void process() {
	// 출발점을 찾는다.
	// 교차로를 찾는다.
	int sx, sy, ex, ey;
	int max = -1;
	for (int i = 1;i <= M;i++) {
		for (int j = 1;j <= N;j++) {
			if (map[i][j] >= '0' && map[i][j] <= '9') {
				int num = map[i][j] - '0';
				if (max < num) max = num;
			}
			else if (map[i][j] == 'A') {
				sx = j;
				sy = i;
			}
			else if (map[i][j] == 'B') {
				ex = j;
				ey = i;
			}
		}
	}

	for (int i = 0;i <= max;i++) {
		int buff;
		scanf("%d %c %d %d", &buff, &inters[i].dir, &inters[i].a, &inters[i].b);
	}

	back(sx, sy, 0);
}

int main(void) {
	while (1) {
		scanf("%d %d", &M, &N);
		if (M == 0 && N == 0) break;
		for (int i = 1;i <= M;i++) {
			scanf("%s", &map[i][1]);
		}
		min = INF;
		process();
		if (min == INF) printf("impossible\n");
		else printf("%d\n", min);
	}
	return 0;
}