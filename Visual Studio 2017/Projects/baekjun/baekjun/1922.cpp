#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int n, m;
int par[1100];

typedef struct data {
	int a;
	int b;
	int val;
} data;

data list[110000];

void swap(int& a, int& b) {
	int t = a;
	a = b;
	b = t;
}

void swap(data& d1, data& d2) {
	swap(d1.a, d2.a);
	swap(d1.b, d2.b);
	swap(d1.val, d2.val);
}

int find(int x) {
	if (par[x] == x) return x;
	else return par[x] = find(par[x]);
}

void link(int x, int y) {
	par[find(y)] = find(x);
}

int main(void) {
	fscanf(stdin, "%d", &n);

	for (int i = 1;i <= n;i++) par[i] = i;
	fscanf(stdin, "%d", &m);
	for (int i = 1;i <= m;i++) {
		int a, b, c;
		fscanf(stdin, "%d %d %d", &a, &b, &c);
		list[i].a = a; list[i].b = b; list[i].val = c;
		for (int j = i;j > 1;j = j >> 1) {
			if (list[j].val > list[j >> 1].val) swap(list[j], list[j >> 1]);
			else break;
		}
	}

	int i, j;
	for (i = 1;i <= m;i++) {
		swap(list[1], list[m-i+1]);
		for (j = 1;;) {
			int t = j << 1;
			if (t > m - i) break;
			if (t + 1 <= m - i && list[t + 1].val > list[t].val) t++;
			if (list[j].val < list[t].val) {
				swap(list[j], list[t]);
				j = t;
			}
			else break;
		}
	}

	int ans = 0;

	for (int i = 1;i <= m;i++) {
		if (find(list[i].a) != find(list[i].b)) {
			link(list[i].a, list[i].b);
			ans += list[i].val;
		}
	}
	
	fprintf(stdout, "%d", ans);
	return 0;
}