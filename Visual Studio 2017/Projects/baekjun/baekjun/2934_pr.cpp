// 30분

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int tree[110000];
int check[110000];
int n;

int sum(int i) {
	int t = 0;
	while (i > 0) {
		t += tree[i];
		i -= (i&-i);
	}
	return t;
}

void update(int i, int val) {
	while (i <= 100000) {				// 주의..... index제한은 n이 아닐 수 있다.
		tree[i] += val;
		i += (i&-i);
	}
}

void bound_check(int left, int right, int val) {
	update(left, val);
	update(right + 1, -val);
}


int main(void) {
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i++) {
		int a, b;
		fscanf(stdin, "%d %d", &a, &b);
		fprintf(stdout, "%d\n", sum(a) + sum(b) - check[a] - check[b]);
		check[a] = sum(a);
		check[b] = sum(b);
		bound_check(a + 1, b - 1, 1);
	}
	return 0;
}