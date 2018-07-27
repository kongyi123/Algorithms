// 13Ка

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define INF 2000000000

int tree[262144];
int k;

int min(int a, int b) {
	if (a > b) return b;
	return a;
}

int unimin(int s, int e) {
	int x = k + s - 1;
	int y = k + e - 1;
	int t = INF;
	while (x <= y) {
		if (x % 2 == 1) t = min(t, tree[x++]);
		if (y % 2 == 0) t = min(t, tree[y--]);
		x /= 2;
		y /= 2;
	}

	return t;
}

int main(void) {
	int n, m;
	fscanf(stdin, "%d %d", &n, &m);
	for (k = 1;k < n;k *= 2);

	for (int i = 1;i <= k * 2;i++) tree[i] = INF;

	for (int i = k;i < k+n;i++) 
		fscanf(stdin, "%d", &tree[i]);
	
	for (int i = k - 1;i >= 1;i--)
		tree[i] = min(tree[i * 2], tree[i * 2 + 1]);

	for (int i = 1;i <= m;i++) {
		int a, b;
		fscanf(stdin, "%d %d", &a, &b);
		fprintf(stdout, "%d\n", unimin(a, b));
	}

	return 0;
}