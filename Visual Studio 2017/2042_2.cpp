// 17
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;
vector<int> dat(1000010);
vector<long long> tree((1 << 21) + 1);
int N, M, K;

long long init(int node, int start, int end) {
	if (start == end) {
		return tree[node] = dat[start];
	}
	else {
		return tree[node] = init(node * 2, start, (start + end) / 2) + init(node * 2 + 1, (start + end) / 2 + 1, end);
	}
}

void update(int node, int start, int end, int index, long long diff) {
	if (start > index || end < index) return;
	tree[node] += diff;
	if (start != end) {
		update(node * 2, start, (start + end) / 2, index, diff);
		update(node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	}
}


long long sum(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node]; // 대충 암기해서 틀린 부분
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
		scanf("%d", &t);
		int a, b;
		if (t == 1) {
			scanf("%d%d", &a, &b);
			long long diff;
			diff = b - dat[a];
			dat[a] = b;					// 여기도 잘 아는 실수 포인트인데 또 빠트렸다.
			update(1, 1, N, a, diff);
		}
		else {
			scanf("%d%d", &a, &b);
			printf("%lld\n", sum(1, 1, N, a, b));
		}
	}
	return 0;
}