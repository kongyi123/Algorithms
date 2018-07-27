#define _CRT_SECURE_NO_WARNINGS
// 2017. 07. 19
// ������. �̰� ���� �ʴ�. but, test�ϴ°� �ʿ�

// �ƿ� ���� ������ �ڵ��ϴ� ��Ÿ�Ϸ� �ڵ�

#include <stdio.h>
#define MAX 100
#define INPUT in
#define OUTPUT out

FILE *in = fopen("input.txt", "r");
FILE *out = fopen("output.txt", "w");

// ���� ��� ����Ʈ�� ������.
// ���� ��� ����Ʈ�� ���� �� �迭 ���� ���ٰ� ������ҷ� �ؾ�

int v, e;
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
		check[frontier] = 0;
	}
	return 0;
}

void input() {
	int a, b, c;

	fscanf(INPUT, "%d%d", &v, &e);
	fscanf(INPUT, "%d%d", &src, &sink);
	for (int i = 1;i <= e;i++) {
		fscanf(INPUT, "%d %d %d", &a, &b, &c);
		ftable[a][++fcnt[a]] = b;
		ftable[b][++fcnt[b]] = a;
		edge[a][b][0] = c;
//		edge[b][a][0] = c; �������� capacity ������ �ʿ䵵 ���� (���� ������ �� ���� ����)
	}

}

void process() {
	int temp_ad;

	while (1) {
		for (int i = 1;i <= v;i++) check[i] = 0;
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