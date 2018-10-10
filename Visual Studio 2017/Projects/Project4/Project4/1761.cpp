// 31 - 35 - 52 - 60

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M;
vector<pair<int, int>> link[40010];
int parent[40010];
int dt[40010];
bool check[40010];
int p[40010][30];
int depth[40010];

void back(int cur, int dist, int d) {
	for (int i = 0;i < link[cur].size();i++) {
		int next = link[cur][i].first;
		if (check[next] == 1) continue;
		check[next] = 1;
		dt[next] = dist + link[cur][i].second;
		parent[next] = cur;
		depth[next] = d;
		back(link[cur][i].first, dist + link[cur][i].second, d + 1);
	}
}

int lca(int a, int b) {
	if (depth[a] < depth[b]) swap(a, b);
	int log = (int)log2(depth[a]); // ���� Ʋ��.. �ǹ̸� ��������ϱ�..
	for (int i = log;i >= 0;i--) {
		if (depth[a] - depth[b] >= (1 << i)) // log -> i ��ħ
			a = p[a][i];
	}

	if (a == b) return a;
	else {
		for (int i = log;i >= 0;i--) {
			if (p[a][i] == 0) continue; // �̰͵� ����
			if (p[a][i] != p[b][i]) {
				a = p[a][i];
				b = p[b][i];
			}
		}
		return parent[a];
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
	back(1, 0, 1); // cur, dist

	for (int i = 1;i <= N;i++) 
		p[i][0] = parent[i];
	
	for (int j = 1;(1 << j) < N;j++) {
		for (int i = 1;i <= N;i++) {
			if (p[i][j - 1] != 0) // ?? �ǹ̰�. ���� �� �� �θ� �����ϴ��� 
				p[i][j] = p[p[i][j - 1]][j - 1]; // ���Ⱑ ����Ʈ�ε�... Ʋ��
		} 
	}

	scanf("%d", &M);
	for (int i = 1;i <= M;i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		int t = lca(a, b);
		printf("%d\n", dt[a] + dt[b] - 2*dt[t]); // ���������� Ʋ���κ� 2*dt[t]�� ������ϴµ�..
		// ������ �ʹ� �������ϰ� Ǯ����.
	}
	return 0;
}