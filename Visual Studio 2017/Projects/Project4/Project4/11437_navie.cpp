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
// 얘는 시간 초과 난다... 얘는 확실히 아래 코드보다 느린코드가 맞긴 하다. 
// 그냥 최적화 코드로 알아두자. 

int lca(int a, int b) {
	while (1) {
		if (depth[a] > depth[b]) {
			swap(a, b); // b가 무조건 뎁스가 큰 애
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
	if (depth[a] > depth[b]) swap(a, b); // b가 무조건 뎁스가 큰 애
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