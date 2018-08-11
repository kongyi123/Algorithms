#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#define MAX 10001
#define INF 0x7fffffff

using namespace std;

int N;
int data[MAX][2];
int dp[2][MAX];

int main() {
    int T;
	scanf("%d", &T);
    for (int tc = 1;tc <= T;tc ++) {
		scanf("%d", &N);
		for (int i = 1; i <= N; ++i) {
			int t;
			scanf("%d %d %d", &t, &data[i][0], &data[i][1]);
		}
		sort(dat + 1, dat + n + 1);

		dp[0][0] = -INF;
		for (int j = 1; j <= n; ++j) dp[0][j] = INF;

		int p = 0, pp = 1;
		for (int i = 1; i <= n; ++i) {
			p ^= 1;  pp ^= 1;
			for (int j = 0; j <= i; ++j) {
				dp[p][j] = INF;
				if (dp[pp][j] < INF && dp[pp][j] <= dat[i].y) {
					dp[p][j] = max(dat[i].y, dp[pp][j] + dat[i].h);
				}
				if (j > 0 && dp[pp][j - 1] < INF) {
					dp[p][j] = min(
						dp[p][j],
						dp[pp][j - 1] + dat[i].h
					);
				}
			}
		}

		int ans = INF;
		for (int j = 0; j <= n; ++j) {
			if (dp[n % 2][j] < INF) {
				ans = j;
				break;
			}
		}

		cout << "Case #" << caseidx << '\n';
		cout << ans << '\n';
	
	}
    return 0;
}
