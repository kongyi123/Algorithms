// 28 + Lazy Propagation(23)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Node {
	long long lazy;
	long long value;
};

Node tree[1 << 21];
int dat[1000010];
int M, N, K;

long long init(int node, int start, int end) {
	if (start == end) {
		return tree[node].value = dat[start];
	}
	else {
		return tree[node].value = init(node * 2, start, (start + end) / 2) + init(node * 2 + 1, (start + end) / 2 + 1, end);
	}
}

void update(int node, int start, int end, int left, int right, long long diff) {
//	if (right < start || left > end) return;

	if (tree[node].lazy != 0) {
		tree[node].value += tree[node].lazy * (end - start + 1);
		if (start != end) {
			tree[node * 2].lazy += tree[node].lazy;
			tree[node * 2 + 1].lazy += tree[node].lazy;
		}
		tree[node].lazy = 0;
	}
	
	if (right < start || left > end) return;  // 갱신해야 하는 구간을 담당하지 않는 노드면 return.

	if (left <= start && end <= right) {
		tree[node].value += diff * (end - start + 1);
		if (start != end) {
			tree[node * 2].lazy += diff;
			tree[node * 2 + 1].lazy += diff;
		}
		return; // 빠뜨림 아예 노드의 영역이 구하는 구간에 포함되면 더이상 내려갈 필요가 없다.
	}
	update(node * 2, start, (start + end) / 2, left, right, diff);
	update(node * 2 + 1, (start + end) / 2 + 1, end, left, right, diff);

	// 결국 얘때문에... 바로 아랫단 lazy까지 처리해줘야하는 것임. 위로가는 propagation
	tree[node].value = tree[node * 2].value + tree[node * 2 + 1].value;
}

long long sum(int node, int start, int end, int left, int right) {
	if (tree[node].lazy != 0) {
		tree[node].value += tree[node].lazy * (end - start + 1);
		if (start != end) {
			tree[node * 2].lazy += tree[node].lazy;
			tree[node * 2 + 1].lazy += tree[node].lazy;
		}
		tree[node].lazy = 0;
	}

	if (right < start || left > end) return 0;
	if (left <= start && end <= right) return tree[node].value;
	else {
		return sum(node * 2, start, (start + end) / 2, left, right) + sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
	}
}

int main(void) {
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 1;i <= N;i++) {
		scanf("%d", &dat[i]);
	}

	init(1, 1, N);

	for (int i = 1;i <= M + K;i++) {
		int t, a, b;
		long long c;
		scanf("%d", &t);

		if (t == 1) {
			scanf("%d%d%lld", &a, &b, &c);
			update(1, 1, N, a, b, c);
		}
		else {
			scanf("%d%d", &a, &b);
			printf("%lld\n", sum(1, 1, N, a, b));
		}
	}


	return 0;
}