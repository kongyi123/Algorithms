#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX(a,b) a>b?(a):(b)
#define MIN(a, b) a>b?(b):(a)
#define INF 0x7fffffff
#define N_MAX 100010



struct node {
	int val;
	int index;
	node() : val(INF) {}
	bool operator<(node temp) {
		return this->val < temp.val;
	}

};

node tree[N_MAX];
node tree2[N_MAX];

int N;
int dat[N_MAX];

void update(int i, int x) { // root 값이 n인 구조
	int t = i;
	while (i <= N) {
		if (tree[i].val > x) {
			tree[i].index = t;
			tree[i].val = x;
		}
		i += (i & -i);
	}

	i = t - 1;
	while (1) {
		if (tree2[i].val > x) {
			tree2[i].index = t;
			tree2[i].val = x;
		}
		if (i == 0) break;
		i -= (i & -i);
	}
}

node query(int a, int b) {	// 탐색
	node v;
	int cur, next;
	cur = a - 1;
	next = cur + (cur & -cur);
	while (1) {
		if (b == next - 1) {
			if (tree2[cur] < v) v = tree2[cur];
			break;
		}
		else if (b < next - 1) break;
		else if (tree2[cur] < v) v = tree2[cur];
		
		cur = next;
		next += (next & -next);
	}

	cur = b;
	next = cur - (cur & -cur);
	while (1) {
		if (a == next + 1) {
			if (tree[cur] < v) v = tree[cur];
			break;
		}
		else if (a > next + 1) break;
		else if (tree[cur] < v) v = tree[cur];
		cur = next;
		next -= (next & -next);
	}

	return v;
}



int dy(int s, int e) {
	if (s > e) return 0;
	if (s == e) return dat[s];

	int max = 0;
	node ans;

	ans = query(s, e);
	int min = ans.val;
	int p = ans.index;

	// min, p
	
	max = MAX(max, min*(e - s + 1));
	max = MAX(dy(s, p - 1), max);
	max = MAX(dy(p + 1, e), max);

	return max;
}

int main(void) {
	while (1) {
		scanf("%d", &N);
		if (N == 0) break;

		for (int i = 0;i <= N;i++)
			tree[i].val = tree2[i].val = INF;

		for (int i = 1;i <= N;i++) {
			scanf("%d", &dat[i]);
			update(i, dat[i]);
		}

		printf("%d\n", dy(1, N));
	}
	return 0;
}