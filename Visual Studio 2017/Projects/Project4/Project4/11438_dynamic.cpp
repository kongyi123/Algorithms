// 1:38

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int p[100010][30];
int parent[100010];
int depth[100010];

int N, M;

vector<int> link[100010];

int queue[100010][2];
void make_parent() {
	int head = 0, tail = 1;
	queue[head][0] = 1;
	int cur, next;
	parent[1] = -1;
	
	while (head < tail) {
		cur = queue[head][0];
		for (unsigned int i = 0;i < link[cur].size();i++) {
			next = link[cur][i];
			if (parent[next] != 0) continue;
			queue[tail][0] = next;
			queue[tail++][1] = queue[head][1] + 1;
			parent[next] = cur;
			depth[next] = queue[head][1] + 1;
		}
		head++;
	}
}

int lca(int a, int b) {
	if (depth[a] < depth[b]) swap(a, b);
	int log = (int)log2(depth[a]);	// �Ҽ��� �����̴ϱ�..
	for (int i = log;i >= 0;i--) { // 8, 4, 2, 1... �������� ����� ���� �� ���ݾ�? 
		if ((1 << i) <= depth[a] - depth[b])  // b�� ���̰� ���� ��ŭ���� ������ ��� ���ش�.
			a = p[a][i];
	}	// ����Ʈ ������ �� ����� ������ �޼ӵ��� ���̴� ���.. 
		// �̰� ���� ����Ʈ������ �̺а˻��� �����ϰڴ�.. (���, O(N)�� ��ó���� �ʿ��ϴ�.) ��, ����Ʈ�� ���Ҹ� �߰� ���� �ϸ� �̺а˻����� �뵵�� ����ϱ� �����.
		// �ٵ� ����Ʈ���� ���� �װͱ����� ���������� �𸣰ڴ�.

	if (a == b) return a;
	else {
		for (int i = log;i >= 0;i--) {
			if (p[a][i] == 0) continue;
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
		int a, b;
		scanf("%d%d", &a, &b);
		link[a].push_back(b);
		link[b].push_back(a);
	}

	make_parent();

	parent[1] = 0;
	for (int i = 1;i <= N;i++) 
		p[i][0] = parent[i];

//	for (int j = 1; (j << 1) < N;j = j << 1) {
	for (int j = 1; (1 << j) < N;j++) { // �� j�� �ؿ� ���Ŀ� ���̱� ������ ������ ���´� �ȵȴ�.
		for (int i = 1;i <= N;i++) {
			if (p[i][j - 1] != 0) 
				p[i][j] = p[p[i][j - 1]][j - 1]; // �����̳�...
		}
	}

	scanf("%d", &M);
	for (int i = 1;i <= M;i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", lca(a, b));
	}

	return 0;
}

