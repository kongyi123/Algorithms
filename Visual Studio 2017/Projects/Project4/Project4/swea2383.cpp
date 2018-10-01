// 1:56 �ٽ� ����.

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
	// dist[0] : ���1 ���� �Ÿ�
	// dist[1] : ���2 ���� �Ÿ�
};


// p_cnt : �����, s_cnt : ��� ��
int n, p_cnt, s_cnt;
int dat[15][15];
int stair[15];

Pos p[15], s[3];

int dap;
int onstair[15][2];
int check[15];

int end_p_cnt; // ��ܿ��� �������� ����� ��

// ��� ũ��, ���� ��� ��ȣ
// ���� �� �ִ��� Ȯ���ϰ� �����ϸ� �ִ� �Լ�
// �־����� 1���� ������ ������ 0����
int push(int size, int val) { 
	int isPushed = 0;
	for (int i = 1;i <= 3;i++) {
		if (onstair[i][0] == 0) {
			onstair[i][0] = val; // ��ܿ� ���� ���
			onstair[i][1] = 0;	 // ��� �ܰ�
			isPushed = 1;
			break;
		}
	}

	return isPushed;
}

// ����� �ð��� 1�帧
void go(int size) {
	for (int i = 1;i <= 3;i++) {
		if (onstair[i][0] != 0) {
			onstair[i][1] ++;
		}
	}
}

// ��ܿ��� �������� ������� ������
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

int queueing_process(int num, int full_p) { // num �� ����� ó��
	int time = 0;
	end_p_cnt = 0;
	for (int i = 1;i < 15;i++) check[i] = 0;

	while (1) {

		time++;
		
		pop(s[num].dat);
		// ���� �� �ִ� ����� Ȯ���ؼ� �ִ°��� �õ��غ�
		for (int i = 1;i <= p_cnt;i++) {
			if (stair[i] != num) continue;
			if (check[i] == 1) continue;
			if (p[i].dist[num] < time) {		// 1 ���ִٰ� ��
				int t = push(s[num].dat, i);
				if (t == 1) check[i] = 1;
			}
		}

		go(s[num].dat);
		

		if (end_p_cnt == full_p) break; // ��� ����� ��ܿ��� ���� ���
	}
	return time; // num�� ����� ó���ϴµ� �ɸ� �ð�
}

void make_order(int k, int a, int b) { // k��° ����� ��� ����� ���� ����
	if (k < 1) { printf("��� ��ȣ ���� : %d\n", k); return; }
	if (k == p_cnt + 1) { // k���� ������� ��� ������ �Ϸ�Ǿ�����
		int max = queueing_process(0, a);
		max = MAX(max, queueing_process(1, b));
		
		if (dap > max) { // dap�� �� ��ܵ��� ó���� ������ �ð��� ���� �ʰ� ������ �͵� �߿� �ּ��ΰ��̾��.
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
				if (dat[i][j] == 1) { // 1�� �������
					p_cnt++;
					p[p_cnt].y = i; p[p_cnt].x = j;
				}
				else if (dat[i][j] != 0) {
					s[s_cnt].y = i; s[s_cnt].x = j; // 0�� ���, 1�� ���
					s[s_cnt].dat = dat[i][j];
					s_cnt++;
				}
			}
		}

		for (int i = 1;i <= p_cnt;i++) { // ���
			for (int j = 0;j < s_cnt;j++) { // ���
				p[i].dist[j] = ABS(p[i].y - s[j].y) + ABS(p[i].x - s[j].x);
			}
		}

		printf("#%d %d\n", tc, process());
	}
	return 0;
}