#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <algorithm>
#define MAX_VALUE 987654321.0

using namespace std;
int n;

int cache[17][65536], dist[17][17];

// 두 가지를 살핀다.
// visitid => 비트 마스크로 이미 방문한 도시인지 체크
// cache[현재 위치][여지껏 방문한 도시] => 메모이제이션을 통해 

int TSP(int cur, int visited) {
	// 점이 10개라면 10000000000 - 1 = 01111111111
	// 즉, 전부 다 방문했다면
	if (visited == (1 << n) - 1) return dist[cur][0];

	int &ret = cache[cur][visited];		// 메모이제이션 배열에 이미 구해져 있다면
	if (ret != 0) return ret;			// 굳이 새로 구하지 않고 리턴.

	// 만약 처음 구하는 거라면, 

	// 현재 visited에는 cur까지 체크가 된 상황이다.
	ret = MAX_VALUE;					
	for (int next = 0; next <= n; next++) {					// 다음에 방문할 장소 후보 순회
		if (visited&(1 << next)) continue;					// 현재까지 이미 방문한 적이 있으면 스킵				
		if (dist[cur][next] == 0) continue;					// 만약 cur과 next가 같거나 그렇지 않은 경우나 도시 사이의 길이 없는경우 
		ret = min(ret, TSP(next, visited | (1 << next)) + dist[cur][next]);
		
		// 현재 상태에서 어디를 갔다가 그 덩어리에서 
		
		// TSP(next, visited) 에는  state(next,vitited) 에서의 최적값이 구해져서 return 되나? 
		// backtracking으로 말이다.
	

		// return func(); 이런식으로 작성하면 더 작은 단위의 최적값을 먼저 구한 후 그보다 한 바로 한 단계 큰 단위의 최적값을
		//					구하는 순서로 값이 구해지고 첫 layer함 수에서 값을 반환하면서 종료된다.

	}
	return ret;	// 현재에서 다음 단계로 가는데 (모든 가지수로) 한 바퀴 돌고 최적값을 return 하는 수.
}

int main(void) {
	scanf("%d", &n);
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			scanf("%d", &dist[i][j]);			// 인접 행렬을 입력받는다.
		}
	}
	printf("%d", TSP(0, 1));
	return 0;
}