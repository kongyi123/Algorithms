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
	int log = (int)log2(depth[a]);	// 소수점 버림이니까..
	for (int i = log;i >= 0;i--) { // 8, 4, 2, 1... 이진수로 어떤수든 만들 수 있잖아? 
		if ((1 << i) <= depth[a] - depth[b])  // b와 높이가 맞을 만큼까지 적절히 계속 빼준다.
			a = p[a][i];
	}	// 리스트 관계의 두 노드의 간격을 급속도로 줄이는 방법.. 
		// 이걸 쓰면 리스트에서의 이분검색도 가능하겠다.. (대신, O(N)의 전처리가 필요하다.) 즉, 리스트에 원소를 추가 제거 하면 이분검색으로 용도로 사용하기 힘들듯.
		// 근데 펜윅트리를 쓰면 그것까지도 가능할지도 모르겠다.

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
	for (int j = 1; (1 << j) < N;j++) { // 이 j가 밑에 수식에 쓰이기 때문에 위같은 형태는 안된다.
		for (int i = 1;i <= N;i++) {
			if (p[i][j - 1] != 0) 
				p[i][j] = p[p[i][j - 1]][j - 1]; // 예술이네...
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

