#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define INF 2000000000

int n;
int k;

typedef struct node {
	int cnt;
	int min;
};

node tree[270000];

int min(int a, int b) {
	if (a > b) return b;
	return a;
}

void update(int i, int val) {
	i += k - 1;
	tree[i].min = val;
	tree[i].cnt = 1;
	i = i / 2;
	while (i > 0) {
		int a, b, tmp;
		tmp = -INF;
		if (tree[i*2].min != INF && tmp < tree[i * 2].cnt * tree[i * 2].min) {
			tmp = tree[i * 2].cnt * tree[i * 2].min;
			a = tree[i * 2].cnt;
			b = tree[i * 2].min;
		}

		if (tree[i*2+1].min != INF && tmp < tree[i * 2 + 1].cnt * tree[i * 2 + 1].min) {
			tmp = tree[i * 2 + 1].cnt * tree[i * 2 + 1].min;
			a = tree[i * 2 + 1].cnt;
			b = tree[i * 2 + 1].min;
		}

		if (tree[i * 2].min != INF && tree[i * 2+1].min != INF && tmp < (tree[i * 2].cnt + tree[i * 2 + 1].cnt) * min(tree[i * 2].min, tree[i * 2 + 1].min)) {
			tmp = (tree[i * 2].cnt + tree[i * 2 + 1].cnt) * min(tree[i * 2].min, tree[i * 2 + 1].min);
			a = tree[i * 2].cnt + tree[i * 2 + 1].cnt;
			b = min(tree[i * 2].min, tree[i * 2 + 1].min);
		}
			
		tree[i].cnt = a;
		tree[i].min = b;

		i = i / 2;
	}
}

int main(void) {
	while (1) {
		fscanf(stdin, "%d", &n);
		if (n == 0) break;
		for (int j = 0;j < 270000;j++) tree[j].min = INF;
		for (k = 1;k < n;k *= 2);

		for (int j = 1;j <= n;j++) {
			int data;
			fscanf(stdin, "%d", &data);
			update(j, data);
		}
		fprintf(stdout, "%d\n", tree[1].cnt*tree[1].min);
	}
	return 0;
}