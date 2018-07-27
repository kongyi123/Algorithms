#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int depth[1100];
int dir[1100];

int parent(int t) {
	while (dir[t] != t) {
		t = dir[t];
	}
	return t;
}


int main(void) {
	int n, m;
	fscanf(stdin, "%d %d", &n, &m);
	for (int i = 1;i <= n;i++) {
		depth[i] = 1;
		dir[i] = i;
	}
	for (int i = 1;i <= m;i++) {
		int a, b;
		fscanf(stdin, "%d %d", &a, &b);		
		a = parent(a);
		b = parent(b);
		if (depth[a] > depth[b]) {
			if (depth[a] < depth[b] + 1)
				depth[a] = depth[b] + 1;
			dir[b] = a;
		}
		else {
			if (depth[b] < depth[a] + 1)
				depth[b] = depth[a] + 1;
			dir[a] = b;
		}
	}

	int cnt = 0;
	int check[1010] = { 0, };
	for (int i = 1;i <= n;i++) {
		int p = parent(i);
		if (check[p] == 0) {
			check[p] = 1;
			cnt++;
		}
	}

	fprintf(stdout, "%d", cnt);
	return 0;
}