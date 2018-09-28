#define DEBUG 1

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#if DEBUG
#include <conio.h>
#endif
#define MAX(a,b) a>b?(a):(b)
#define INF 0x7fffffff
#define N_MAX 100010

int tree[N_MAX][2];
int tree2[N_MAX][2];

int N;
int dat[N_MAX];

void update(int i, int x) { // root 값이 n인 구조
	int t = i;
	while (i <= N) {
		if (tree[i][0] > x) {
			tree[i][1] = t;
			tree[i][0] = x;
		}
		i += (i & -i);
	}

	i = t - 1;
	while (1) {
		if (tree2[i][0] > x) {
			tree2[i][1] = t;
			tree2[i][0] = x;
		}
		if (i == 0) break;
		i -= (i & -i);
	}
}

int query(int a, int b) {	// 탐색
	int cur, next;
	cur = a - 1;
	int v = INF, p;
	if (a > 1) {
		next = cur + (cur & -cur);
		while (next - 1 <= b - 1) {
			if (tree2[cur][0] < v) { v = tree2[cur][0]; p = tree2[cur][1]; }
			cur = next;
			next += (next & -next);
		}
	}

	cur = b;
	next = cur - (cur & -cur);
	while (next + 1 >= a) {
		if (tree[cur][0] < v) { v = tree[cur][0]; p = tree[cur][1]; }
		if (next == 0) break;
		cur = next;
		next -= (next & -next);
	}

	return p;
}

long long dy(int s, int e) {
	if (s > e) return 0;
	if (s == e) return dat[s];

	long long max = 0;
	int p = query(s, e);
	int min = dat[p];

	// min, p
	
	max = MAX(max, (long long)min*(e - s + 1));
	max = MAX(dy(s, p - 1), max);
	max = MAX(dy(p + 1, e), max);

	return max;
}

int main(void) {
#if DEBUG
	freopen("input.txt", "r", stdin);
#endif
	while (1) {
		scanf("%d", &N);
		if (N == 0) break;

		for (int i = 0;i <= N;i++)
			tree[i][0] = tree2[i][0] = INF;

		for (int i = 1;i <= N;i++) {
			scanf("%d", &dat[i]);
			update(i, dat[i]);
		}

		printf("%lld\n", dy(1, N));
	}
#if DEBUG
	_getch();
#endif
	return 0;
}