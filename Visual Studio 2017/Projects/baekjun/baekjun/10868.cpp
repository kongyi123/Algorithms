// 45분
// 초기화 부분
// 배열 선언시 배열의 크기 결정


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define INF 2000000000


int tree[262144];

int k;

int min_(int a, int b) {
	if (a > b) return b;
	return a;
}

int min(int b, int c) {
	int x = k + b - 1;
	int y = k + c - 1;

	int t = INF;
	while (x <= y) {
		if (x % 2 == 1) t = min_(t, tree[x++]);
		if (y % 2 == 0) t = min_(t, tree[y--]);
		x = x / 2;
		y = y / 2;
	}

	return t;
}

int main(void) {
	int n, m;
	fscanf(stdin, "%d %d", &n, &m);
	for (k = 1;k < n;k *= 2);	

	for (int i = 1;i <= k*2;i++) tree[i] = INF;

	for (int i = k;i < k+n;i++) 
		fscanf(stdin, "%d", &tree[i]);


	for (int i = k - 1;i >= 1;i--) 
		tree[i] = min_(tree[i * 2], tree[i * 2 + 1]);

	for (int i = 1;i <= m;i++) {
		int a, b;
		fscanf(stdin, "%d %d", &a, &b);
		fprintf(stdout, "%d\n", min(a, b));
	}
	return 0;
}