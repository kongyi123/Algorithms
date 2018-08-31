// 1:13 - 1:19 - 1:43 - 1:45 (claer처리(수정)) - 1:53 (튜닝)
// 데이터 ooooo ..... 다음에 처음부터 짤 때는 restore 처리 빠뜨리지 않을 수 있을까?

// 실수가 잦은 부분 : 1. 구조적&논리적으로 빠트린 부분 2. 구현이 잘못된 부분
// 가능한한 모듈화. 같은 개념은 무조건 같은 함수로 처리될 수 있도록 하자.


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define RED 0
#define BLUE 1

//enum COLOR { RED, BLUE };

struct node {
	int y[2];
	int x[2];
	int dist;
	node(int ry, int rx, int by, int bx, int dist) {
		this->y[RED] = ry;
		this->x[RED] = rx;
		this->y[BLUE] = by;
		this->x[BLUE] = bx;
		this->dist = dist;
	}
	node() {}
};


int N, M;
char data[12][12];
int visited[12][12][12][12];

int ry, rx, by, bx;
int oy, ox;

node queue[3000];
int head, tail;

int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} }; // 동서남북

void go(int &sy, int &sx, int dy, int dx, char ch) { // 구슬의 다음 위치를 찾음
	while (data[sy + dy][sx + dx] == '.') {
		data[sy][sx] = '.';
		sy += dy; sx += dx;
		data[sy][sx] = ch;
	}
	if (data[sy + dy][sx + dx] == 'O') {
		data[sy][sx] = '.';
		sy += dy; sx += dx;
	}
}

node gravity(node cur, int t) { // dir방향으로 기울임
	// 시뮬레이션... 
	// 그려보고 지워준다.

	// 순서 판별
	int rw = cur.y[RED] * dir[t][0] + cur.x[RED] * dir[t][1];
	int bw = cur.y[BLUE] * dir[t][0] + cur.x[BLUE] * dir[t][1];
	data[cur.y[RED]][cur.x[RED]] = 'R';
	data[cur.y[BLUE]][cur.x[BLUE]] = 'B';
	
	// 시뮬레이션(그림)
	if (rw < bw) { // 기울일 방향으로 b가 앞서 있을 경우
		go(cur.y[BLUE], cur.x[BLUE], dir[t][0], dir[t][1], 'B');
		go(cur.y[RED], cur.x[RED], dir[t][0], dir[t][1], 'R');
	}
	else { // 기울일 방향으로 r가 앞서 있을 경우
		go(cur.y[RED], cur.x[RED], dir[t][0], dir[t][1], 'R');
		go(cur.y[BLUE], cur.x[BLUE], dir[t][0], dir[t][1], 'B');
	}
	cur.dist += 1;

	// restore
	for (int i = 0;i <= 1;i++) data[cur.y[i]][cur.x[i]] = '.'; // clear
	data[oy][ox] = 'O';
	
	return cur;
}

int process() {
	head = 0, tail = 1;
	queue[head].y[RED] = ry;
	queue[head].x[RED] = rx;
	queue[head].y[BLUE] = by;
	queue[head].x[BLUE] = bx;
	queue[head].dist = 0;
	visited[ry][rx][by][bx] = 1;

	while (head < tail) {
		for (int i = 0;i <= 3;i++) {
			queue[tail] = gravity(queue[head], i);
			if ((queue[tail].y[RED] == oy && queue[tail].x[RED] == ox)){
				if (!(queue[tail].y[BLUE] == oy && queue[tail].x[BLUE] == ox)) { // 빨간 구슬만 들어간 경우
					int ans = queue[tail].dist;
					if (ans > 10) return -1;
					return ans;
				}

				continue; // 둘다 들어간 경우
			}
			else if ((queue[tail].y[BLUE] == oy && queue[tail].x[BLUE] == ox)) { // 파란 구슬만 들어간 경우
				continue;
			}

			if (visited[queue[tail].y[RED]][queue[tail].x[RED]][queue[tail].y[BLUE]][queue[tail].x[BLUE]] == 0) {
				visited[queue[tail].y[RED]][queue[tail].x[RED]][queue[tail].y[BLUE]][queue[tail].x[BLUE]] = 1;
				tail++;
			}
		}
		head++;
	}

	return -1;
}

int main(void) {
//	freopen("input.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	for (int i = 1;i <= N;i++) {
		scanf("%s", &data[i][1]);
		for (int j = 1;j <= M;j++) {
			if (data[i][j] == 'R') {
				ry = i; rx = j; data[i][j] = '.';
			}
			else if (data[i][j] == 'B') { 
				by = i; bx = j; data[i][j] = '.';
			}
			else if (data[i][j] == 'O') {
				oy = i; ox = j; 
			}
		}
	}


	printf("%d", process());

	
	return 0; 
}