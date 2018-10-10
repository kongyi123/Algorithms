// 16
// 2042a 튜닝.. 시간 관계상
// 일단 1번 Fail -> long long 형변환 빠트림.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// #include <conio.h> 이거 주석 처리 또안했음... ㅠㅠ

struct Node {
	long long val;
	long long lazy;
};

int N, M, K;
int dat[1 << 20];
Node tree[1 << 21];

long long init(int node, int start, int end) {
	if (start == end) return tree[node].val = dat[start];
	return tree[node].val = init(node * 2, start, (start + end) / 2) + init(node * 2 + 1, (start + end) / 2 + 1, end); 
}

void update(int node, int start, int end, int left, int right, int diff) {
	// 찌꺼기 아래로 전파
	if (tree[node].lazy != 0) {
		tree[node].val += tree[node].lazy * (long long)(end - start + 1);
		if (start != end) {
			tree[node * 2].lazy += tree[node].lazy;
			tree[node * 2 + 1].lazy += tree[node].lazy;
		}
		tree[node].lazy = 0;
	}

	if (end < left || right < start) return ;

	// 발생
	if (left <= start && end <= right) {
		tree[node].val += (long long)diff * (end - start + 1);
		if (start != end) {
			tree[node * 2].lazy += (long long)diff;
			tree[node * 2 + 1].lazy += (long long)diff;
		}
		return;
	}

	if (start != end) {
		update(node * 2, start, (start + end) / 2, left, right, diff);
		update(node * 2 + 1, (start + end) / 2 + 1, end, left, right, diff);
	}

	// 위로 전파
	tree[node].val = tree[node * 2].val + tree[node * 2 + 1].val; // 마지막에 채움  
}

long long sum(int node, int start, int end, int left, int right) {
	// 찌꺼지 아래로 전파
	if (tree[node].lazy != 0) {
		tree[node].val += tree[node].lazy * (long long)(end - start + 1);
		if (start != end) {
			tree[node * 2].lazy += tree[node].lazy;
			tree[node * 2 + 1].lazy += tree[node].lazy;
		}
		tree[node].lazy = 0;
	}
	
	if (end < left || right < start) return 0;
	if (left <= start && end <= right) {
		return tree[node].val;
	}
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
		int t;
		int a, b;
		int val;
		scanf("%d", &t);
		if (t == 1) {
			scanf("%d%d%d", &a, &b, &val);
			// update
			update(1, 1, N, a, b, val);
		}
		else {
			scanf("%d%d", &a, &b);
			// query
			printf("%lld\n", sum(1, 1, N, a, b));
		}
	}
	return 0;
}
