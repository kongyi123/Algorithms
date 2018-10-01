// 1:56 다시 볼것.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#define INF 0x7fffffff
#define MAX(a, b) a>b?(a):(b)

inline int ABS(int a) {
	if (a < 0) return -a;
	return a;
}

struct Pos {
	int y, x;
	int dat;
	int dist[2];
	// dist[0] : 계단1 과의 거리
	// dist[1] : 계단2 와의 거리
};


// p_cnt : 사람수, s_cnt : 계단 수
int n, p_cnt, s_cnt;
int dat[15][15];
int stair[15];

Pos p[15], s[3];

int dap;
int onstair[15][2];
int check[15];

int end_p_cnt; // 계단에서 빠져나간 사람의 수

// 계단 크기, 넣을 사람 번호
// 넣을 수 있는지 확인하고 가능하면 넣는 함수
// 넣었으면 1리턴 넣을수 없으면 0리턴
int push(int size, int val) { 
	int isPushed = 0;
	for (int i = 1;i <= 3;i++) {
		if (onstair[i][0] == 0) {
			onstair[i][0] = val; // 계단에 오른 사람
			onstair[i][1] = 0;	 // 계단 단계
			isPushed = 1;
			break;
		}
	}

	return isPushed;
}

// 계단의 시간이 1흐름
void go(int size) {
	for (int i = 1;i <= 3;i++) {
		if (onstair[i][0] != 0) {
			onstair[i][1] ++;
		}
	}
}

// 계단에서 빠져나갈 사람들을 내보냄
int pop(int size) { 
	int isEmpty = 1;
	for (int i = 1;i <= 3;i++) {
		if (onstair[i][0] != 0 && onstair[i][1] >= size) {
			onstair[i][0] = onstair[i][1] = 0;
			end_p_cnt++;
		}

		if (onstair[i][0] != 0)
			isEmpty = 0;
	}

	return isEmpty;
}

int queueing_process(int num, int full_p) { // num 번 계단의 처리
	int time = 0;
	end_p_cnt = 0;
	for (int i = 1;i < 15;i++) check[i] = 0;

	while (1) {

		time++;
		
		pop(s[num].dat);
		// 넣을 수 있는 사람을 확인해서 넣는것을 시도해봄
		for (int i = 1;i <= p_cnt;i++) {
			if (stair[i] != num) continue;
			if (check[i] == 1) continue;
			if (p[i].dist[num] < time) {		// 1 분있다가 들어감
				int t = push(s[num].dat, i);
				if (t == 1) check[i] = 1;
			}
		}

		go(s[num].dat);
		

		if (end_p_cnt == full_p) break; // 모든 사람이 계단에서 나간 경우
	}
	return time; // num번 계단을 처리하는데 걸린 시간
}

void make_order(int k, int a, int b) { // k번째 사람이 어느 계단을 갈지 정함
	if (k < 1) { printf("사람 번호 오류 : %d\n", k); return; }
	if (k == p_cnt + 1) { // k명의 사람들의 계단 선택이 완료되었으면
		int max = queueing_process(0, a);
		max = MAX(max, queueing_process(1, b));
		
		if (dap > max) { // dap은 각 계단들이 처리가 끝나는 시간중 가장 늦게 끝나는 것들 중에 최소인것이어야.
			dap = max;
		}
		return;
	}
	else {
		stair[k] = 0;
		make_order(k + 1, a + 1, b);
		stair[k] = 1;
		make_order(k + 1, a, b + 1);
	}
}

int process() {
	dap = INF;
	make_order(1, 0, 0);
	return dap;
}

void init() {
	for (int i = 0;i < 15;i++) {
		check[i] = 0;
		onstair[i][0] = onstair[i][1] = 0;
	}
	s_cnt = p_cnt = 0;
}

int main(void) {
	int T;
	scanf("%d", &T);
	for (int tc = 1;tc <= T;tc++) {
		scanf("%d", &n);
		init();
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= n;j++) {
				scanf("%d", &dat[i][j]);
				if (dat[i][j] == 1) { // 1번 사람부터
					p_cnt++;
					p[p_cnt].y = i; p[p_cnt].x = j;
				}
				else if (dat[i][j] != 0) {
					s[s_cnt].y = i; s[s_cnt].x = j; // 0번 계단, 1번 계단
					s[s_cnt].dat = dat[i][j];
					s_cnt++;
				}
			}
		}

		for (int i = 1;i <= p_cnt;i++) { // 사람
			for (int j = 0;j < s_cnt;j++) { // 계단
				p[i].dist[j] = ABS(p[i].y - s[j].y) + ABS(p[i].x - s[j].x);
			}
		}

		printf("#%d %d\n", tc, process());
	}
	return 0;
}