#include <cstdio>
#include <cmath>
#include <algorithm>
#define MAX_VALUE 987654321.0

using namespace std;
int n;

int cache[17][65536], dist[17][17];

int TSP(int cur, int visited) {

	if (visited == (1 << n) - 1) return dist[cur][0];

	int &ret = cache[cur][visited];
	if (ret != 0) return ret;
	ret = MAX_VALUE;
	for (int next = 0; next <= n; next++) {
		if (visited&(1 << next)) continue;
		if (dist[cur][next] == 0) continue;
		ret = min(ret, TSP(next, visited | (1 << next)) + dist[cur][next]);
	}
	return ret;
}

int main(void) {
	scanf("%d", &n);
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			scanf("%d", &dist[i][j]);
		}
	}
	printf("%d", TSP(0, 1));
	return 0;
}