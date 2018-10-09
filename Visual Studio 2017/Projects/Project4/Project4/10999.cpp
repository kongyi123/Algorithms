#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#define MAXN 1000010
long long arr[MAXN];

typedef struct Tree {
	long long value, lazy;
}Tree;

Tree tree[3 * MAXN];

// 동일
long long  init(int node, int start, int end) {
	if (start == end)
		return tree[node].value = arr[start];
	else
		return tree[node].value = init(node * 2, start, (start + end) / 2) + init(node * 2 + 1, (start + end) / 2 + 1, end);
}

void update_range(int node, int start, int end, int left, int right, long long diff) {
	//lazy가 남아있을 때
	if (tree[node].lazy != 0) {
		tree[node].value += (end - start + 1)*tree[node].lazy;
		if (start != end) {
			tree[node * 2].lazy += tree[node].lazy;
			tree[node * 2 + 1].lazy += tree[node].lazy;
		}
		tree[node].lazy = 0;
	}


	if (right < start || left > end) return;

	//대표 구간을 찾았을 때
	if (left <= start &&  end <= right) {
		tree[node].value += (end - start + 1)*diff;
		if (start != end) {
			tree[node * 2].lazy += diff;
			tree[node * 2 + 1].lazy += diff;
		}
		return;
	}
	update_range(node * 2, start, (start + end) / 2, left, right, diff);
	update_range(node * 2 + 1, (start + end) / 2 + 1, end, left, right, diff);

	tree[node].value = tree[node * 2].value + tree[node * 2 + 1].value;
}

long long sum(int node, int start, int end, int left, int right) {
	if (tree[node].lazy != 0) {
		tree[node].value += (end - start + 1) * tree[node].lazy;
		if (start != end) {
			tree[node * 2].lazy += tree[node].lazy;
			tree[node * 2 + 1].lazy += tree[node].lazy;
		}
		tree[node].lazy = 0;
	}

	// 이하 동일
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node].value;
	return sum(node * 2, start, (start + end) / 2, left, right) + sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main() {
	int N, M, K;
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 1; i <= N; i++)
		scanf("%lld", &arr[i]);
	init(1, 1, N);
	for (int i = 1; i <= M + K; i++) {
		int t1, a, b;
		long long diff;
		scanf("%d", &t1);
		if (t1 == 1) {
			scanf("%d%d%lld", &a, &b, &diff);
			update_range(1, 1, N, a, b, diff);
		}
		else {
			scanf("%d%d", &a, &b);
			printf("%lld\n", sum(1, 1, N, a, b));
		}
	}
	return 0;
}