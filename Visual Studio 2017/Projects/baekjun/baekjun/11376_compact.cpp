// 이분 매칭 대표 코드
// 유량 알고리즘의 개념으로도 볼 수 있지만.
// 코드는 그리디 혹은 백트랙킹에 더 가깝다. (KAIST MOCK ACM 2017의 A번과 유사한 느낌)
// -> 이 구조를 이용해서 KIAST MOCK ACM 2017 A번 문제를 풀어볼 것.

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
vector<vector<int>> g;	// 2차원 벡터 (인접 리스트)
int ck[2001]; 
int b[2001];

bool dfs(int cur) {
	ck[cur] = 1;
	for (auto &p : g[cur]) { // 인접 리스트를 살펴서 바로 frontier 접근
		if (b[p] == 0 || ck[b[p]] == 0 && dfs(b[p])) {
			// job이 아예 처음으로 선택 받았거나  || (이미 차지한 놈이 다른 경로를 또 찾을 수 있다면(단, 이전에 체크한 노드를 제외))
			// 즉, 가능한 경로에 다 다시 설정을 back으로 써 해주는 것임
			b[p] = cur;
			return true;	// 현 상태에서 새 경로를 찾게 되면 true
		}
	}
	return false;			// 현 상태에서 새 경로를 찾지 못하면 false
}

int main() {
	int n, m, ans = 0;
	scanf("%d%d", &n, &m);
	g.resize(2 * n + 1);				// 인접 리스트 구성
	for (int i = 1, a; i <= n; i++) {
		scanf("%d", &a);
		for (int j = 0, b; j < a; j++) {
			scanf("%d", &b);
			g[i].push_back(b);			// 1대 다의 매칭일 때  용량과 유량을 늘리는게 아니라, 가상 노드 추가에 간선을 늘려주는 걸로 대신한다.
			g[i + n].push_back(b);		// 왜냐면 매칭문제이기 때문
		}
	}

	for (int i = 1; i <= n * 2; i++) {
		if (dfs(i)) { // 경로를 찾을 수 있으면 카운팅 해주면서 계속 진행하도록 만들어 주는 구조의 코드
			memset(ck, 0, sizeof(ck));
			ans++;
		}
	}
	
	printf("%d\n", ans);
	return 0;

}

