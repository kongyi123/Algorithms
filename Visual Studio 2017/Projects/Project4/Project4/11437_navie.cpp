// 32

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

int N, M;
int parent[50001];
int depth[50001];

vector<int> link[50001];

inline void make_parent(int cur, int d) {
	for (int i = 0;i < link[cur].size();i++) {
		int next = link[cur][i];
		if (depth[next] == 0) {
			depth[next] = d;
			parent[next] = cur;
			make_parent(next, d+1);
		}
	}
}

inline void swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}
/*
// ��� �ð� �ʰ� ����... ��� Ȯ���� �Ʒ� �ڵ庸�� �����ڵ尡 �±� �ϴ�. 
// �׳� ����ȭ �ڵ�� �˾Ƶ���. 

int lca(int a, int b) {
	while (1) {
		if (depth[a] > depth[b]) {
			swap(a, b); // b�� ������ ������ ū ��
		}

		if (depth[a] != depth[b]) {
			b = parent[b];
		} else if(a != b) {
			a = parent[a];
			b = parent[b];
		}
		else break;
	}

	return a;
}
*/
int lca(int a, int b) {
	if (depth[a] > depth[b]) swap(a, b); // b�� ������ ������ ū ��
	while (depth[a] != depth[b]) b = parent[b];
	while (a != b) {
		a = parent[a];
		b = parent[b];
	}

	return a;
}


int main(void) {
	scanf("%d", &N);
	int a, b;
	for (int i = 1;i <= N-1;i++) {
		scanf("%d%d", &a, &b);
		link[a].push_back(b);
		link[b].push_back(a);
	}

	depth[1] = 1;
	make_parent(1, 2);

	scanf("%d", &M);
	for (int i = 1;i <= M;i++) {
		scanf("%d%d", &a, &b);
		printf("%d\n", lca(a, b));
	}

	return 0;
}