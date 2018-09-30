#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, m;
long long tree[100010];
int dat[100010]; 

void swap(int& a, int& b) {
	int t = a;
	a = b;
	b = t;
}

long long sum(int p) {
	long long ans = 0;
	int cur = p;
	while (1 <= cur) {
		ans = ans + tree[cur];
		cur -= (cur & -cur);
	}
	return ans;
}

void update(int i, long long x) {
	int cur = i;
	while (cur <= n) {
		tree[cur] = tree[cur] + x;
		cur += (cur & -cur);
	}
}

int main(void) {
//	freopen("input.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 1;i <= n;i++) {
		scanf("%lld", &dat[i]);
		update(i, dat[i]);
	}
	int a, x, y;
	int b;
	for (int i = 1;i <= m;i++) {
		scanf("%d%d%d%d", &x, &y, &a, &b);
		if (x > y) swap(x, y);
		printf("%lld\n", sum(y)-sum(x-1));
		update(a, -(long long)dat[a]);
		dat[a] = b;
		update(a, (long long)b);
	}
	return 0;
}
