// 로봇
// 다음 상태 노드의 y,x,dir이 어떻든 dist는 1씩 증가하기 때문에
// bfs가 성립
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;

struct State {
	int x;
	int y;
	int dir;
	int dist;
	State(int x, int y, int dir, int dist) {
		this->x = x;
		this->y = y;
		this->dir = dir;
		this->dist = dist;
	}
	State() {} // 기본생성자 필요
};

template<typename T>
struct Queue {
	struct Node {
		T val; // 임시 변수를 만들기 때문에
		Node* next;
		Node(T val) { 
			this->val = val;
			this->next = NULL;
		}
	};

	Node *pStart, *pEnd;
	Queue() {
		pStart = pEnd = NULL;
	}

	int isEmpty() {
		if (pStart == NULL) return 1;
		return 0;
	}

	void add(T val) {
		if (isEmpty()) {
			pStart = pEnd = new Node(val);
		}
		else {
			Node *newNode = new Node(val);
			pEnd->next = newNode;
			pEnd = newNode;
		}
	}

	T pull() {
		if (pStart == pEnd) {
			T tmp_val = pStart->val;
			delete pStart;
			pStart = pEnd = NULL;
			return tmp_val;
		}
		else {
			T tmp_val = pStart->val;
			Node* tmp = pStart;
			pStart = tmp->next;
			delete tmp;
			return tmp_val;
		}
	}
};

int data[110][110];
int visited[110][110][5];

int main(void) {
	int M, N;
	scanf("%d %d", &M, &N);
	for (int i = 1;i <= M;i++) {
		for (int j = 1;j <= N;j++) {
			scanf("%d", &data[i][j]);
		}
	}

	int sy, sx, sd;
	int ey, ex, ed;
	scanf("%d %d %d", &sy, &sx, &sd);
	scanf("%d %d %d", &ey, &ex, &ed);

	int ans = 0;
	
	int dir[5][2] = { {0, 0}, {0, 1}, {0, -1}, {1, 0} ,{-1, 0} };
	Queue<State>* q = new Queue<State>();
	visited[sy][sx][sd] = 1;
	q->add(State(sx, sy, sd, 0));
	while (!q->isEmpty()) {
		State cur = q->pull();
		if (cur.y == ey && cur.x == ex && cur.dir == ed) {
			ans = cur.dist;
			break;
		}
		
		for (int k = 1;k <= 3;k++) {				// 1~3만큼 전진
			int ny = cur.y + dir[cur.dir][0] * k;
			int nx = cur.x + dir[cur.dir][1] * k;
			if (ny > M || ny <= 0) continue;
			if (nx > N || nx <= 0) continue;
			if (data[ny][nx] == 0) {
				if (visited[ny][nx][cur.dir] == 0) {
					visited[ny][nx][cur.dir] = 1;
					q->add(State(nx, ny, cur.dir, cur.dist + 1));
				}
			}
			else break;
		}

		int r, l;									// 방향만 변경하는 경우
		if (cur.dir == 1) r = 3, l = 4;
		if (cur.dir == 2) r = 4, l = 3;
		if (cur.dir == 3) r = 2, l = 1;
		if (cur.dir == 4) r = 1, l = 2;
		if (data[cur.y][cur.x] == 0) {
			if (visited[cur.y][cur.x][r] == 0) {
				visited[cur.y][cur.x][r] = 1;
				q->add(State(cur.x, cur.y, r, cur.dist + 1));
			}
			if (visited[cur.y][cur.x][l] == 0) {
				visited[cur.y][cur.x][l] = 1;
				q->add(State(cur.x, cur.y, l, cur.dist + 1));
			}
		}
	}

	printf("%d", ans);
	return 0;
}

