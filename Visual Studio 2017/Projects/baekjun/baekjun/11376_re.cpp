// 이분 매칭 대표 코드
// 유량 알고리즘의 개념으로도 볼 수 있지만.
// 코드는 그리디 혹은 백트랙킹에 더 가깝다. (KAIST MOCK ACM 2017의 A번과 유사한 느낌)
// -> 이 구조를 이용해서 KIAST MOCK ACM 2017 A번 문제를 풀어볼 것.
// 이분 매칭의 시간복잡도를 계산하면??  V*E



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>
#include <memory.h>

using namespace std;

int n, m;
int rec[2100];
vector<int> adj[2100];
bool check[2100];

bool back(int cur) {
	check[cur] = 1;
	for (auto &next : adj[cur]) { // 인접 리스트를 살펴서 바로 frontier 접근
		if (rec[next] == 0 || (check[rec[next]] == 0 && back(rec[next]))) {
			// job이 아예 처음으로 선택 받았거나  || (이미 차지한 놈이 다른 경로를 또 찾을 수 있다면(단, 이전에 체크한 노드를 제외))
			// 즉, 가능한 경로에 다 다시 설정을 back으로 써 해주는 것임
			rec[next] = cur;
			return true;	// 현 상태에서 새 경로를 찾게 되면 true
		}
	}
	return false;			// 현 상태에서 새 경로를 찾지 못하면 false
}

int main(void) {
	
	fscanf(stdin, "%d %d", &n, &m);
	for (int i = 1;i <= n;i++) {// 인접 리스트 구성
		int a, b;
		fscanf(stdin, "%d", &a);
		for (int j = 1;j <= a;j++) {
			fscanf(stdin, "%d", &b);
			adj[i].push_back(b);			// 1대 다의 매칭일 때  용량과 유량을 늘리는게 아니라, 가상 노드 추가에 간선을 늘려주는 걸로 
			adj[i + n].push_back(b);		// 왜냐면 매칭문제이기 때문
		}
	}

	int cnt = 0;
	for (int i = 1;i <= n*2;i++) {
		if (back(i)) {						// 경로를 찾을 수 있으면 카운팅 해주면서 계속 진행하도록 만들어 주는 구조의 코드
			memset(check, 0, sizeof(check));
			cnt++;
		}
	}

	fprintf(stdout, "%d", cnt);

	return 0;
}