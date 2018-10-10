// 11437 수정 _ segment tree...

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

vector<int> link[100001];
int parent[100001];
int depth[100001];

int table[200010];
int first[100010];
int tcnt = 1;

int tree[1 << 20]; // 노드 번호로 저장 됨 비교는 depth[노드번호]

void dfs(int cur, int d) {
	for (int i = 0;i < link[cur].size();i++) {
		int next = link[cur][i];
		if (parent[next] == 0) {
			parent[next] = cur;
			depth[next] = d;
			table[++tcnt] = next;
			dfs(next, d + 1);
			table[++tcnt] = cur;
		}
	}
}

int init(int node, int start, int end) {
	if (start == end) {
		return tree[node] = table[start];
	}
	else {
		int a = init(node * 2, start, (start + end) / 2);
		int b = init(node * 2 + 1, (start + end) / 2 + 1, end);
		if (depth[a] > depth[b]) {
			return tree[node] = b;
		}
		return tree[node] = a;
	}
}

int query(int node, int start, int end, int left, int right) {
	if (end < left || right < start) return 0;
	if (left <= start && end <= right) {
		return tree[node];
	}
	else {
		int a = query(node * 2, start, (start + end) / 2, left, right);
		int b = query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
		if (depth[a] > depth[b]) {
			return b;
		}
		return a;
	}
}


int N, M;
int main(void) {
	int a, b;
	scanf("%d", &N);
	for (int i = 1;i <= N - 1;i++) {
		scanf("%d%d", &a, &b);
		link[a].push_back(b);
		link[b].push_back(a);
	}

	parent[1] = -1;
	table[tcnt] = 1;
	dfs(1, 1);

	for (int i = 1;i <= tcnt;i++) {
		if (first[table[i]] == 0)
			first[table[i]] = i;
	}

	depth[0] = 0x7fffffff;
	init(1, 1, tcnt);

	scanf("%d", &M);
	for (int i = 1;i <= M;i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (first[a] > first[b]) swap(a, b);
		printf("%d\n", query(1, 1, tcnt, first[a], first[b]));
	}

	return 0;
}
