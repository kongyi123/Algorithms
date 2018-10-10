// 25 - 44 // 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>
#define INF 0x7fffffff

using namespace std;

int N, M;
int depth[100010];
int parent[100010];
vector<pair<int, int>> link[100010];
bool check[100010];
int min_[100010][30];
int max_[100010][30];

int p[100010][30];

inline int MIN(int a, int b) {
	if (a > b) return b;
	return a;
}

inline int MAX(int a, int b) {
	if (a > b) return a;
	return b;
}

void dfs(int cur, int d) {
	for (int i = 0;i < link[cur].size();i++) {
		int next = link[cur][i].first;
		if (check[next] == 1) continue;
		check[next] = 1;
		depth[next] = d + 1;
		parent[next] = cur;
		min_[next][0] = link[cur][i].second;
		max_[next][0] = link[cur][i].second;
		dfs(next, d + 1);
	}
}

pair<int, int> lca(int a, int b) {
	if (depth[a] < depth[b]) swap(a, b);
	int log = (int)log2(depth[a]) + 1;
	int max_a, min_a;
	int max_b, min_b;
	max_a = max_b = -INF;
	min_a = min_b = INF;

	for (int i = log;i >= 0;i--) {
		if ((1 << i) <= depth[a] - depth[b]) {
			max_a = MAX(max_a, max_[a][i]);
			min_a = MIN(min_a, min_[a][i]);
			a = p[a][i];
		}
	}
	
	
	if (a == b) {
		if (min_a == INF && max_a == -INF) min_a = max_a = 0;
		return pair<int, int>(min_a, max_a);
	}
	else {
		for (int i = log;i >= 0;i--) {
			if (p[a][i] == 0 || p[b][i] == 0) continue;
			if (p[a][i] != p[b][i]) {
				min_a = MIN(min_a, min_[a][i]);
				max_a = MAX(max_a, max_[a][i]);
				min_b = MIN(min_b, min_[b][i]);
				max_b = MAX(max_b, max_[b][i]);

				a = p[a][i];
				b = p[b][i];
			}
		}
		min_a = MIN(min_a, min_[a][0]);
		max_a = MAX(max_a, max_[a][0]);
		min_b = MIN(min_b, min_[b][0]);
		max_b = MAX(max_b, max_[b][0]);

		return pair<int ,int>(MIN(min_a, min_b), MAX(max_a, max_b));
	}
}

int main(void) {
	scanf("%d", &N);
	for (int i = 1;i <= N-1;i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		link[a].push_back(pair<int, int>(b, c));
		link[b].push_back(pair<int, int>(a, c));
	}

	check[1] = 1;
	depth[1] = 1;
	dfs(1, 1); // cur, depth
	min_[1][0] = INF;
	max_[1][0] = -INF;

	for (int i = 1;i <= N;i++) {
		p[i][0] = parent[i];
	}
	
	for (int j = 1;(1 << j) < N;j++) {
		for (int i = 1;i <= N;i++) {
			if (p[i][j - 1] != 0) {
				p[i][j] = p[p[i][j - 1]][j - 1];
				min_[i][j] = min_[i][j - 1];
				max_[i][j] = max_[i][j - 1];
				if (p[p[i][j - 1]][j - 1] != 0) {
					min_[i][j] = MIN(min_[p[i][j - 1]][j - 1], min_[i][j]);
					max_[i][j] = MAX(max_[p[i][j - 1]][j - 1], max_[i][j]);
				}
			}
		}
	}

	scanf("%d", &M);
	for (int i = 1;i <= M;i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		pair<int, int> t = lca(a, b);
		printf("%d %d\n", t.first, t.second);
	}

	return 0;
}