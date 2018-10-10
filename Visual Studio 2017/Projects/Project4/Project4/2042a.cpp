// 1:04.. 정호님이랑 얘기하느라..
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// #include <conio.h> 이거 주석 처리 또안했음... ㅠㅠ
int N, M, K;
int dat[1 << 20];
long long tree[1 << 21];

long long init(int node, int start, int end) {
	if (start == end) {
		return tree[node] = dat[start];
	}
	else {
		return tree[node] = init(node * 2, start, (start + end) / 2) + init(node * 2 + 1, (start + end) / 2 + 1, end); // tree[node] = 를 빠트림.. 단순 암기한 부분은이렇게 된다.
		// 의미를 음미하면서 코딩을 할 것
	}
}

void update(int node, int start, int end, int index, int diff) {
	if (start > index || end < index) return;
	tree[node] += (long long)diff;

	if (start != end) {
		update(node * 2, start, (start + end) / 2, index, diff);
		update(node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	}
}

long long sum(int node, int start, int end, int left, int right) {
	if (end < left || right < start) return 0;

	if (left <= start && end <= right) {
		return tree[node];
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
			scanf("%d%d", &a, &val);
			// update
			update(1, 1, N, a, -dat[a]+val);
			dat[a] = val;
		}
		else {
			scanf("%d%d", &a, &b);
			// query
			printf("%lld\n", sum(1, 1, N, a, b));
		}
	}
	return 0;
}
