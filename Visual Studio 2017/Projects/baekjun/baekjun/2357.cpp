// 15ºÐ

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <memory.h>
#define INF 2000000000

int min_tree[270000];
int max_tree[270000];
int k;

int min(int a, int b) {
	if (a > b) return b;
	return a;
}

int max(int a, int b) {
	if (a > b) return a;
	return b;
}

void swap(int &a, int &b) {
	int t;
	t = a;
	a = b;
	b = t;
}

int main(void) {
	int n, m;
	fscanf(stdin, "%d %d", &n, &m);

	for (k = 1;k < n;k *= 2);
	for (int i = 1;i <= k * 2;i++) {		// memsetÀº ¾È µÊ
		min_tree[i] = INF;
		max_tree[i] = -INF;
	}

	for (int i = k;i < k+n;i++) {
		fscanf(stdin, "%d", &min_tree[i]);
		max_tree[i] = min_tree[i];
	}

	for (int i = k - 1;i >= 1;i--) {
		min_tree[i] = min(min_tree[i * 2], min_tree[i * 2 + 1]);
		max_tree[i] = max(max_tree[i * 2], max_tree[i * 2 + 1]);
	}

	for (int i = 1;i <= m;i++) {
		int a, b;
		fscanf(stdin, "%d %d", &a, &b);
		if (a > b) swap(a, b);

		int p = a + k - 1;
		int q = b + k - 1;
		int mint = INF;
		int maxt = -INF;
		while (p <= q) {
			if (p % 2 == 1) {
				maxt = max(maxt, max_tree[p]);
				mint = min(mint, min_tree[p++]);
			}
			if (q % 2 == 0) {
				maxt = max(maxt, max_tree[q]);
				mint = min(mint, min_tree[q--]);
			}
			p = p / 2;
			q = q / 2;
		}

		fprintf(stdout, "%d %d\n", mint, maxt);
	}
	return 0;
}