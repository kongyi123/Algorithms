#define _CRT_SECURE_NO_WARNINGS
// 2017. 07. 19
// ������. �̰� ���� �ʴ�. but, test�ϴ°� �ʿ�

// �ƿ� ���� ������ �ڵ��ϴ� ��Ÿ�Ϸ� �ڵ�

#include <stdio.h>
#define MAX 500
#define INPUT stdin
#define OUTPUT stdout

//FILE *in = fopen("input.txt", "r");
//FILE *out = fopen("output.txt", "w");

// ���� ��� ����Ʈ�� ������.
// ���� ��� ����Ʈ�� ���� �� �迭 ���� ���ٰ� ������ҷ� �ؾ�

int n, m; // ���� ������, ����� ����
int src, sink;
int ftable[MAX][MAX];
int fcnt[MAX];
int edge[MAX][MAX][2];
int check[MAX];
// edge[][][0] : �뷮
// edge[][][1] : ����

int sum = 0;

int min(int a, int b) {
	if (a > b) return b;
	return a;
}

int flag;

int back(int cur, int admissible) {
	if (cur == sink) {
		flag = 1;
		return admissible;
	}

	int curcnt = fcnt[cur];
	int frontier;
	int temp;
	for (int i = 1;i <= curcnt;i++) {
		frontier = ftable[cur][i];
		if (check[frontier] == 1 || edge[cur][frontier][0] == edge[cur][frontier][1]) continue;

		check[frontier] = 1;
		temp = back(frontier, min(admissible, edge[cur][frontier][0] - edge[cur][frontier][1]));
		if (flag == 1) {
			edge[cur][frontier][1] += temp; // ������ ���� ����
			edge[frontier][cur][1] -= temp; // ������ ���� ����
			return temp;
		}
//		check[frontier] = 0; // 
	}
	return 0;
}

void input() {
	fscanf(INPUT, "%d%d", &n, &m);
	src = 1;
	sink = n + m + 2;
	int cnt;
	int from, to;

	// 1 : src
	// 2~n+1 : �� ��ȣ
	// n+2 ~ n+m+1 : ����� ��ȣ
	// n+m+2 : sink

	for (from = 2;from <= n+1;from++) {
		// src to all cow node
		ftable[src][++fcnt[1]] = from;
		ftable[from][++fcnt[from]] = src; // ������
		edge[src][from][0] = 1;
		
		
		// all cow to chuksa
		fscanf(INPUT, "%d", &cnt);
		for (int j = 1;j <= cnt;j++) {
			fscanf(INPUT, "%d", &to);
			to = to + 1+n; // src ������ ��ȣ �ϳ��� �и���.
			ftable[from][++fcnt[from]] = to;
			ftable[to][++fcnt[to]] = from; // ������
			edge[from][to][0] = 1;
		}
	}

	for (int i = n + 2;i <= n + m + 1;i++) {
		ftable[i][++fcnt[i]] = sink;
		ftable[sink][++fcnt[sink]] = i; // ������
		edge[i][sink][0] = 1;
	}
}

void process() {
	int temp_ad;

	while (1) {
		for (int i = 1;i <= sink;i++) check[i] = 0;
		check[src] = 1;
		flag = 0;
		temp_ad = back(src, 101);
		if (temp_ad == 0) break;
		sum += temp_ad;
	}


}

void output() {
	fprintf(OUTPUT, "%d", sum);
}


int main(void) {
	input();
	process();
	output();
	return 0;
}