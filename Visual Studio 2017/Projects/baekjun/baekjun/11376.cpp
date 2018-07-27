#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int n, m;
int visited[2010];
int b[2010];
vector<int> node[100];
int dfs(int here) {
	if (visited[here]) return 0;
	visited[here] = 1;
	for (int i = 0; i<node[here].size(); i++) {
		int there = node[here][i];
		if (!b[there] || dfs(b[there])) {
			b[there] = here;
			return 1;
		}
	}
	return 0;
}
int bmatch() {
	int ret = 0;
	for (int i = 1; i <= n; i++) {
		memset(visited, 0, sizeof(visited));
		if (dfs(i))ret++;
	}
	return ret;
}
int main()
{
	scanf("%d%d", &n, &m);
//	node.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		int v, x;
		scanf("%d", &v);
		while (v--) {
			scanf("%d", &x);
			node[i].push_back(x);
		}
	}
	printf("%d", bmatch());
	return 0;
}
