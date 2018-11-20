#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Node {
	char type;
	int play_time, satis_rate;
};

struct State {
	long visited;	// 어디 방문했는지
	int satis;		// 만족도의 합
	int location;	// 위치
	int day;		// 몇번째 날인지
	int rest_time;	// 남은 시간
	int parent;		// 부모 q의 idx(path 역추적 용)


	State(long visited, int satis, int location, int day, int rest_time, int parent) {
		set(visited, satis, location, day, rest_time, parent);
	}

	void set(long visited, int satis, int location, int day, int rest_time, int parent) {
		this->visited = visited;
		this->satis = satis;
		this->location = location;
		this->day = day;
		this->rest_time = rest_time;
		this->parent = parent;
	}

	State() {}
};


int N, M;
int edge[36][36];
Node p[36];
State q[10000];

int process() {
	int ans = 0;
	int head, tail;
	head = 0, tail = 1;
	q[0].set(1, 0, 1, 1, 9 * 60, -1); // 초항
	// 1번은 무조건 공항이다.

	while (head < tail) {
		State cur;
		for (int i = 1;i <= N;i++) {
			cur = q[head];
			if ((cur.visited & (1 << (i - 1))) == 1) continue;
			if (p[i].type == 'P') { // 공항도 여러번, 호텔도 여러번 갈 수 있다.
				// 이동 해서 노는 시간 까지쓴다.
				if (cur.rest_time >= edge[cur.location][i] + p[i].play_time) {
					cur.visited |= (1 << (i - 1));
					cur.location = i;
					cur.satis += p[i].satis_rate;
					cur.rest_time -= (p[i].play_time + edge[cur.location][i]);
					cur.parent = head;
					q[tail] = cur;
					tail++;
				}
			}
			else if (p[i].type == 'H') { // 호텔인 경우
				// 이동시간만 쓴다.
				if (cur.rest_time >= edge[cur.location][i]) {
					cur.location = i;
					cur.rest_time -= (edge[cur.location][i]);
					cur.parent = head;
					q[tail] = cur;
					tail++;	
				}
			}
			else { // 공항인 경우
				   // 이동시간만 쓴다.
				
			}
		}
		head++;
	}

	return ans;
}

int main(void) {
	int T;
	scanf("%d", &T);
	for (int tc = 1;tc <= T;tc++) {
		scanf("%d%d", &N, &M);
		for (int i = 1;i < N;i++) {
			for (int j = 1;j <= N - i;j++) {
				scanf("%d", &edge[i][j]);
				edge[j][i] = edge[i][j];
			}
		}
	
		char ch[10];
		for (int i = 1;i <= N;i++) {
			scanf("%s", ch);
			p[i].type = ch[0];
			if (ch[0] == 'P') {
				int a, b;
				scanf("%d%d", &a, &b);
				p[i].play_time = a;
				p[i].satis_rate = b;
			}
			else {
				p[i].play_time = p[i].satis_rate = 0;
			}
		}

		printf("#%d %d\n", tc, process());
	}

	return 0;
}