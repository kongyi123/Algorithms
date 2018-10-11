// 40 Fail - 53 Fail - 56 AC

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<pair<int, int>> link[100010];
int depth[100010];
bool check[100010];
int parent[100010];
int p[100010][30];

int min_[100010][30];
int max_[100010][30];

int MAX(int a, int b) {
	if (a > b) return a;
	return b;
}

int MIN(int a, int b) {
	if (a < b) return a;
	return b;
}

void dfs(int cur, int d) { // 현재 깊이와 현재의 노드 번호
	for (int i = 0;i < link[cur].size();i++) {
		int next = link[cur][i].first;
		if (check[next] == 0) {
			check[next] = 1;
			depth[next] = d + 1;
			parent[next] = cur;

			max_[next][0] = min_[next][0] = link[cur][i].second;
			dfs(next, d + 1);
		}
	}
}

void process() {
	check[1] = 1;
	depth[1] = 1;
	dfs(1, 1); // cur, depth

	for (int i = 1;i <= N;i++) 
		p[i][0] = parent[i]; // p의 바로 위 부모
	
	
	// 부모 값 전처리
	for (int j = 1;(1 << j) < N;j++) {
		for (int i = 1;i <= N;i++) { // 이 순서때문에 Fail이지 않을까.
			if (p[i][j - 1] != 0 && p[p[i][j - 1]][j - 1] != 0) {
				p[i][j] = p[p[i][j - 1]][j - 1]; // 나의 2^j칸 위 부모는   나의 2^(j-1)칸 부모의 2^(j-1)칸 부모.
				min_[i][j] = MIN(min_[i][j - 1], min_[p[i][j - 1]][j - 1]);
				max_[i][j] = MAX(max_[i][j - 1], max_[p[i][j - 1]][j - 1]);
			}
		}
	}
}

pair<int, int> lca(int a, int b) {
	if (depth[a] < depth[b]) swap(a, b);
	int log = 20;
	int min_a, max_a, min_b, max_b;
	min_a = min_b = 0x7fffffff;
	max_a = max_b = -0x7fffffff;
	for (int i = log;i >= 0;i--) {
		if (depth[a] - depth[b] >= (1 << i)) {
			min_a = MIN(min_a, min_[a][i]);
			max_a = MAX(max_a, max_[a][i]);

			a = p[a][i];
		}
	}

	if (a == b) {
		if (min_a == 0x7fffffff) return pair<int, int >(0, 0);
		return pair<int, int>(min_a, max_a);
	}
	
	for (int i = log;i >= 0;i--) {
		if (p[a][i] == 0) continue;
		if (p[a][i] != p[b][i]) {

			min_a = MIN(min_a, min_[a][i]);
			max_a = MAX(max_a, max_[a][i]);

			min_b = MIN(min_b, min_[b][i]);
			max_b = MAX(max_b, max_[b][i]);

			a = p[a][i];
			b = p[b][i];

			// break; // <- 이거 붙이면 안되는데.. !!!! 이게 문제였음.
		}
	}


	min_a = MIN(min_a, min_[a][0]);
	max_a = MAX(max_a, max_[a][0]);

	min_b = MIN(min_b, min_[b][0]);
	max_b = MAX(max_b, max_[b][0]);

	return pair<int, int>(MIN(min_a, min_b), MAX(max_a, max_b));
}

int main(void) {
	scanf("%d", &N);
	for (int i = 1;i <= N-1;i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		link[a].push_back(pair<int, int>(b, c));
		link[b].push_back(pair<int, int>(a, c));
	}

	process();

	scanf("%d", &M);
	for (int i = 1;i <= M;i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		pair<int, int > t = lca(a, b);
		printf("%d %d\n", t.first, t.second);
	}
	return 0;
}