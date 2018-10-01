// 2:22
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>


struct Node {
	int y;
	int x;
	int state;
	int rest_age;
	int type;
};

int N, M, K;
int dat[500][500];
Node queue[2][50000];
int tail[2];
int dir[4][2] = { {0,1} ,{1, 0}, {-1, 0}, {0, -1 }};

struct Visit {
	int term;
	int type;
	int state;
};

Visit visited[500][500];

void push(int cur, int next, int a, int b, int c, int d, int e) {
	queue[next][tail[next]].rest_age = a;
	queue[next][tail[next]].state = b;
	queue[next][tail[next]].type = c;
	queue[next][tail[next]].y = d;
	queue[next][tail[next]].x = e;
	tail[next]++;
}

void print() {
	for (int i = 190;i <= 210;i++) {
		for (int j = 190;j <= 210;j++) {
			printf("%3d", visited[i][j].state);
		}
		printf("\n");
	}

	printf("\n\n");
	_getch();
}

int process() {
	int cnt = 2;
	int cur, next;
	for (int term = 1; term <= K; term++) {
		cur = cnt % 2;
		next = 1 - cur;
//		print();
		tail[next] = 0;
		if (tail[cur] == 0) break;
		for (int i = 0;i < tail[cur];i ++) {
			int cy = queue[cur][i].y;
			int cx = queue[cur][i].x;
			int ctype = queue[cur][i].type;
			if (ctype != visited[cy][cx].type) continue;

			if (queue[cur][i].state == 0) { // 비활성 상태일때
				queue[cur][i].rest_age--;
				if (queue[cur][i].rest_age == 0) {
					// 자신은 활성상태가 되며
					visited[cy][cx].state = 1;
					push(cur, next, queue[cur][i].type, 1, queue[cur][i].type, cy, cx);
				}
				else {
					push(cur, next, queue[cur][i].rest_age, 0, queue[cur][i].type, cy, cx);
				}

			}
			else { // 활성 상태일때
				if (queue[cur][i].rest_age == queue[cur][i].type) { // 첫 1시간일때
					// 비활성을 낳는다.
					for (int k = 0;k <= 3;k++) {
						int ny = cy + dir[k][0];
						int nx = cx + dir[k][1];
						if (visited[ny][nx].term == cnt) { // 이미 있는데 이번에 같이 만들어진 경우
							if (visited[ny][nx].type < ctype) {
								visited[ny][nx].type = ctype;
								visited[ny][nx].state = 0;
								push(cur, next, ctype, 0, ctype, ny, nx);
							}
						}
						else if (visited[ny][nx].term == 0) { // 아무것도 없다면
							visited[ny][nx].term = cnt;
							visited[ny][nx].type = ctype;
							visited[ny][nx].state = 0;
							push(cur, next, ctype, 0, ctype, ny, nx);
						}
					}
				}

				queue[cur][i].rest_age--;
				if (queue[cur][i].rest_age == 0) {
					visited[cy][cx].state = 2;
					// 죽은상태가 되어야. 그냥 끝이다. 더이상 안퍼지면됨.
				}
				else {			
					push(cur, next, queue[cur][i].rest_age, 1, queue[cur][i].type, cy, cx);
				}

			}
		}


		cnt++;
	}



	int count = 0;
	for (int i = 0;i < 500;i++) {
		for (int j = 0;j < 500;j++) {
			if (visited[i][j].term != 0) {
				if (visited[i][j].state == 2) continue;
				count++;
			}
		}
	}

	return count;
}

void init() {
	for (int i = 0;i < 500;i++) {
		for (int j = 0;j < 500;j++) {
			visited[i][j].state = visited[i][j].term = visited[i][j].type = 0;
		}
	}
	tail[0] = tail[1] = 0;
}

int main(void) {
	int T;
	scanf("%d", &T);
	for (int tc = 1;tc <= T;tc++) {
		scanf("%d%d%d", &N, &M, &K);
		init();
		for (int i = 1;i <= N;i++) {
			for (int j = 1;j <= M;j++) {
				scanf("%d", &dat[i][j]);
				if (dat[i][j] > 0) {
					int y = i + 200;
					int x = j + 200;
					queue[0][tail[0]].y = y;
					queue[0][tail[0]].x = x;
					queue[0][tail[0]].rest_age = queue[0][tail[0]].type = dat[i][j];
					queue[0][tail[0]].state = 0; // 비활성 상태
					visited[y][x].term = 1;
					visited[y][x].type = dat[i][j];
					visited[y][x].state = 0;
					tail[0]++;
				}
			}
		}

		printf("#%d %d\n", tc, process());
	}
	return 0;
}